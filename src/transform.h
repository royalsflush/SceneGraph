#ifndef SG_TRANSFORM_H
#define SG_TRANSFORM_H

#include "group.h"
//#include "matrix.h"

class Transform : public Group {	
	float mat[16];
	float inv[16];

	void load();
	void unload();
	void loadInv();

	public:
	Transform();
	void render();
	int setupLights();
	int setupCamera();

	void rotate();
	void translate(float dx, float dy, float dz);
	void scale();
	void loadIdentity();
};

#endif /* SG_TRANSFORM_H */
