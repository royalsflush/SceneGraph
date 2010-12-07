#ifndef SG_GROUP_H
#define SG_GROUP_H

#include <list>
#include <string>
using namespace std;

#include "node.h"

class Renderer;

class Group : public Node {
	list<Node*> children;	

	public:
	Group(const char* nId);
	Group(const char* nId, const char* nType);

	void render();
	int setupLights();
	int setupCamera();	

	virtual void printChildren();
	virtual Node* findNode(const char* name, const char* type);
	void addNode(Node* newNode);
	void addRenderer(Renderer* r);
};

#endif /* SG_GROUP_H */
