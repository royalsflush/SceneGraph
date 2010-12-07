#ifndef SG_NODE_H
#define SG_NODE_H

#include <string>
using namespace std;

class Renderer;

//Node is an abstract class

class Node {
	string id;
	string type;

	public:
	Node(const char* nId, const char* nType);
	string getId();
	string getType();
	
	//Virtual scene graph functions
	virtual void render() = 0;
	virtual int setupLights() = 0;
	virtual int setupCamera() = 0;
	virtual Node* findNode(const char* name, const char* nType);
	virtual void addRenderer(Renderer* r);
};

#endif /* SG_NODE_H */
