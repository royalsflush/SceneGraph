#ifndef SG_NODE_H
#define SG_NODE_H

//Node is an abstract class

class Node {
	public:
	virtual void render() = 0;
	virtual int setLights() = 0;
	virtual int setCamera() = 0;
};

#endif /* SG_NODE_H */
