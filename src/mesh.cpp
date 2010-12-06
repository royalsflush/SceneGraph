#include <stdio.h>
#include <stdlib.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "mesh.h"

Mesh::Mesh(const char* filename)
{
	int ind;	
	FILE* fp = fopen(filename, "rt");

	if (!fp) {
		printf("Error while loading the file!\n");
		exit(1);
	}

	fscanf(fp, "%d %d", &this->nVert, &this->nInd);

	this->vert = new float[3*(this->nVert)];
	this->norm = new float[3*(this->nVert)];

	for (int i=0; i<(this->nVert); i++) {
		fscanf(fp, "%d", &ind);

		for (int j=0; j<3; j++) 
			fscanf(fp, "%f", &this->vert[3*i+j]);

		for (int j=0; j<3; j++) 
			fscanf(fp, "%f", &this->norm[3*i+j]);
	}
	
	this->ind = new unsigned int[3*(this->nInd)];

	for (int i=0; i<this->nInd; i++) {
		fscanf(fp, "%d", &ind);

		for (int j=0; j<3; j++)
			fscanf(fp, "%u", &this->ind[3*i+j]);
	}

	fclose(fp);
}

void Mesh::draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, this->vert);
	glNormalPointer(GL_FLOAT, 0, this->norm);
	glDrawElements(GL_TRIANGLES, 3*(this->nInd), GL_UNSIGNED_INT, this->ind);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
}
