#ifndef SG_GROUP_H
#define SG_GROUP_H

#include <list>
using namespace std;

#include "node.h"

class Group : public Node {
	list<Node*> children;	

	public:
	void render();
	int setLights();
	int setCamera();	

	void addNode(Node* newNode);
};

#endif /* SG_GROUP_H */
