#ifndef SG_TRANSFORM_H
#define SG_TRANSFORM_H

#include "group.h"
#include "matrix.h"

class Transform : public Group {	
	Matrix<float> mat;
	Matrix<float> inv;

	public:
	Transform(const char* name);

	void load();
	void unload();
	void loadInv();
	
	void render();
	int setupLights();
	int setupCamera();

	void identity();
	void rotate(float angle, float vx, float vy, float vz);
	void translate(float dx, float dy, float dz);
	void scale(float dx, float dy, float dz);

	void printMatrix();
};

#endif /* SG_TRANSFORM_H */
