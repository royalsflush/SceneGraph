#include <stdio.h>
#include <list>
#include <string>

#include "group.h"
#include "node.h"
using namespace std;

Group::Group(const char* nId) : Node(nId, "Group") { }
Group::Group(const char* nId, const char* nType) : Node(nId, nType) { }

void Group::addNode(Node* newNode)
{
	this->children.push_back(newNode);
}

Node* Group::findNode(const char* name, const char* nType)
{
	list<Node*>::iterator it;
	
	Node* result = Node::findNode(name, nType);
	if (result) return result;

	printf("\n");
	this->printChildren();
	printf("\n");

	for (it=this->children.begin(); it!=this->children.end(); ++it)  {
		result = (*it)->findNode(name, nType);
		if (result) return result;
	}

	return NULL;
}

void Group::render()
{
	list<Node*>::iterator it;

	for (it=this->children.begin(); it!=this->children.end(); ++it) 
		(*it)->render();
}

int Group::setupLights()
{	
	list<Node*>::iterator it;
	int numLights=0;	

	for (it=this->children.begin(); it!=this->children.end(); ++it)
		numLights+= (*it)->setupLights();

	return numLights;
}

int Group::setupCamera()
{
	list<Node*>::iterator it;
	int camera=0;	

	for (it=this->children.begin(); it!=this->children.end(); ++it) 
		camera+= (*it)->setupCamera();

	return camera;
}

void Group::printChildren()
{
	list<Node*>::iterator it;
	
	printf("Children of %s:\n", this->getId().c_str());

	for (it=this->children.begin(); it!=this->children.end(); ++it) 
		printf("%s\n", (*it)->getId().c_str());

	printf("\n");
}
