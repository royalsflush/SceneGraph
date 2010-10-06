#include <stdio.h>
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
	int numLights=0;	

	for (it=this->children.begin(); it!=this->children.end(); ++it) {
		numLights+= (*it)->setupLights();
	}

	return numLights;
}

int Group::setupCamera()
{
	list<Node*>::iterator it;
	int camera=0;	

	for (it=this->children.begin(); it!=this->children.end(); ++it) {
		camera+= (*it)->setupCamera();
	}

	return camera;
}
