#include <stdlib.h>
#include <string>
using namespace std;

#include "node.h"

Node::Node(const char* nId, const char* nType) 
{ 
	this->id = nId;
	this->type = nType;
}

Node* Node::findNode(const char* name, const char* nType)
{
	#ifdef _DBG
		printf("Reached %s - %p\n", id.c_str(), this);
	#endif
	
	if (!this->id.compare(name) && !this->type.compare(nType))
		return this;

	return NULL;
}

string Node::getId()
{
	return id;
}

string Node::getType()
{
	return type;
}
