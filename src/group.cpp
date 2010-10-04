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

int Group::setLights()
{	
	list<Node*>::iterator it;
	
	for (it=this->children.begin(); it!=this->children.end(); ++it) {
		(*it)->setLights();
	}
}

int Group::setCamera()
{
	list<Node*>::iterator it;
	
	for (it=this->children.begin(); it!=this->children.end(); ++it) {
		(*it)->setCamera();
	}
}
