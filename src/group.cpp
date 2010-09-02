#include <list>

#include "group.h"
using namespace std;

void Group::addNode(Node* newNode)
{
	this->children.push_back(newNode);
}
