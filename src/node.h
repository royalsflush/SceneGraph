#ifndef SG_NODE_H
#define SG_NODE_H

//Node is an abstract class

class Node {
	public:
	virtual void render() = 0;
	virtual int setupLights() = 0;
	virtual int setupCamera() = 0;
};

#endif /* SG_NODE_H */
