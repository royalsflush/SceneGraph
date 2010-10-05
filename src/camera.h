#ifndef CAMERA_H
#define CAMERA_H

#include "node.h"

class Camera : public Node {
	float eye[3], center[3], up[3];
	float fovy, aspect, znear, zfar;

	public:
	int setupCamera();
	int setupLights();
	void render();

	void setEye(float x, float y, float z);
	void setCenter(float x, float y, float z);
	void setUp(float x, float y, float z);
	void setZPlanes(float near, float far);
	void setAngle(float alpha);
	void setAspectRatio(float asp);
};

#endif /* CAMERA_H */
