#ifndef MESH_H
#define MESH_H

#include "shape.h"

class Mesh : public Shape {
	float* vert;
	float* norm;
	unsigned int* ind;
	int nVert;
	int nInd;

	public:
	Mesh(const char* filename);
	void draw();	
};

#endif /* MESH_H */
