#ifndef SG_NODE_H
#define SG_NODE_H

//Node is an abstract class

class Node {
	public:
	virtual render() = 0;
	virtual setLights() = 0;
	virtual setCamera() = 0;
};

#endif /* SG_NODE_H */
