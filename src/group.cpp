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

	for (it=this->children.begin(); it!=this->children.end(); ++it) {
		(*it)->render();
	}
}

int Group::setupLights()
{	
	list<Node*>::iterator it;
	
	for (it=this->children.begin(); it!=this->children.end(); ++it) {
		(*it)->setupLights();
	}
}

int Group::setupCamera()
{
	list<Node*>::iterator it;
	
	for (it=this->children.begin(); it!=this->children.end(); ++it) {
		(*it)->setupCamera();
	}
}
