#ifndef SG_GROUP_H
#define SG_GROUP_H

#include <list>
#include <string>
using namespace std;

#include "node.h"

class Group : public Node {
	list<Node*> children;	

	public:
	Group(const char* nId);
	Group(const char* nId, const char* nType);

	void render();
	int setupLights();
	int setupCamera();	

	Node* findNode(const char* name, const char* type);
	void addNode(Node* newNode);
};

#endif /* SG_GROUP_H */
