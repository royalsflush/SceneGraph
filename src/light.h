#ifndef LIGHT_H
#define LIGHT_H

#include "node.h"
#include "switch.h"

class Light : public Node {
	float pos[4];
	float amb[4];
	float dif[4];
	float spec[4];
	float spotDir[3];
	int spotExp;
	int spotCutoff;
	int ind;
	static int lightCount;
	static Switch* ctrlSwitch;

	public:
	Light(float x, float y, float z, float w);
	void setSpecular(float r, float g, float b, float a);
	void setDiffuse(float r, float g, float b, float a);
	void setAmbient(float r, float g, float b, float a);
	void setSpotDir(float dirX, float dirY, float dirZ);
	void setSpotExp(int exp);
	void setSpotCutoff(int cutoff);
	int setupLights();
	int setupCamera();
	void render();

	void setSwitch(Switch* s);
};

#endif /* LIGHT_H */
