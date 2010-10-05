#include <list>

#include "group.h"
#include "node.h"
using namespace std;

void Group::addNode(Node* newNode)
{
	this->children.push_back(newNode);
}

void Group::render()
{
	list<Node*>::iterator it;

	#ifdef _DBG
		printf("Group->render()\n");
	#endif

	for (it=this->children.begin(); it!=this->children.end(); ++it) {
		(*it)->render();
	}
}

int Group::setupLights()
{	
	list<Node*>::iterator it;
	int numLights=0;	

	#ifdef _DBG
		printf("Group->setupLights()\n");
	#endif
	
	for (it=this->children.begin(); it!=this->children.end(); ++it) {
		numLights+= (*it)->setupLights();
	}

	#ifdef _DBG
		printf("Last group had %d lights\n", numLights);
	#endif

	return numLights;
}

int Group::setupCamera()
{
	list<Node*>::iterator it;
	int camera=0;	

	#ifdef _DBG
		printf("Group->setupCamera()\n");
	#endif
	
	for (it=this->children.begin(); it!=this->children.end(); ++it) {
		camera+= (*it)->setupCamera();
	}

	#ifdef _DBG
		printf("%s the camera\n", camera? "Already found" : "Havent found");
	#endif

	return camera;
}
