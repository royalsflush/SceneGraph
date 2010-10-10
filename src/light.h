#ifndef LIGHT_H
#define LIGHT_H

#include "node.h"

class Light : public Node {
	float pos[4];
	float amb[4];
	float dif[4];
	float spec[4];
	int ind;
	static int lightCount;

	public:
	Light(float x, float y, float z, float w);
	void setSpecular(float r, float g, float b, float a);
	void setDiffuse(float r, float g, float b, float a);
	void setAmbient(float r, float g, float b, float a);
	int setupLights();
	int setupCamera();
	void render();
};

#endif /* LIGHT_H */
