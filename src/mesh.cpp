#include <stdio.h>
#include <stdlib.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "renderer.h"
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

	glGenBuffers(1, &vbuf); 
	glBindBuffer(GL_ARRAY_BUFFER, vbuf);
	glBufferData(GL_ARRAY_BUFFER, this->nVert*3*sizeof(float), this->vert, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &ibuf); 
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibuf);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*3*this->nInd, this->ind, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			
	glGenBuffers(1, &nbuf); 
	glBindBuffer(GL_ARRAY_BUFFER, nbuf);
	glBufferData(GL_ARRAY_BUFFER, this->nVert*sizeof(float)*3, this->norm, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	fclose(fp);
}

void Mesh::draw()
{
	if (!this->currRend) return;
	
	this->currRend->draw(this->vert, this->ind, this->norm, this->nInd);
}
