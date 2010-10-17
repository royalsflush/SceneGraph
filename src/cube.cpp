#include <stdio.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "cube.h"

Cube::Cube(float x, float y, float z) : dimX(x), dimY(y), dimZ(z) 
{ 
	this->div=30;	
	this->vert=NULL;
	this->norm=NULL;
	this->ind=NULL;

	this->buildCube();		
}

void Cube::buildCube()
{
	this->nVert=6*(this->div+1)*(this->div+1);
	this->nInd=12*(this->div)*(this->div);
	
	if (this->vert) delete[] this->vert;
	if (this->norm) delete[] this->norm;
	if (this->ind) delete[] this->ind;

	this->vert = new float[3*(this->nVert)];
	this->norm = new float[3*(this->nVert)];
	this->ind = new unsigned int[3*(this->nInd)];

	int offsetV;
	int offsetI;
	

	for (int j=0; j<=this->div; j++) {
		for (int i=0; i<=this->div; i++) {
			int k = Cube::index(i,j);
		
			 this->vert[3*k] = (float)i/(float)this->div;
			 this->vert[3*k+1] = (float)j/(float)this->div;
			 this->vert[3*k+2] = 0.0f;
		}
	}
	
	for (int j=0; j<=this->div; j++) {
		for (int i=0; i<=this->div; i++) {
			int k = Cube::index(i,j);
		
			 this->norm[3*k] = 0.0f;
			 this->norm[3*k+1] = 0.0f;
			 this->norm[3*k+2] = -1.0f;
		}
	}
	
	int k=0;

	for (int j=0; j<this->div; j++) {
		for (int i=0; i<this->div; i++) {
			this->ind[k++]= index(i,j);
			this->ind[k++]= index(i+1,j+1);
			this->ind[k++]= index(i,j+1);
			this->ind[k++]= index(i,j);
			this->ind[k++]= index(i+1,j);
			this->ind[k++]= index(i+1,j+1);
		}
	}
}

void Cube::draw()
{
	#ifdef _DBG
		printf("Drawing Cube\n");
	#endif

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glScalef(this->dimX, this->dimY, this->dimZ);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	
	glVertexPointer(3, GL_FLOAT, 0, this->vert);
	glNormalPointer(GL_FLOAT, 0, this->norm);
	
	//Plano xy
	glPushMatrix();
	
	glTranslatef(-0.5f, -0.5f, 0.5f);
	glDrawElements(GL_TRIANGLES, 3*(this->nInd), GL_UNSIGNED_INT, this->ind);	

	glPushMatrix();
	
	glRotatef(180, -1, 0, 0);
	glTranslatef(0.0f, -1.0f, 1.0f);	
	glDrawElements(GL_TRIANGLES, 3*(this->nInd), GL_UNSIGNED_INT, this->ind);	
	
	glPopMatrix();
	glPopMatrix();
	
	//Plano xz
	glPushMatrix();
	glRotatef(90, 1, 0, 0);

	glPushMatrix();
	glTranslatef(-0.5f, -0.5f, -0.5f);
	glDrawElements(GL_TRIANGLES, 3*(this->nInd), GL_UNSIGNED_INT, this->ind);	
	glPopMatrix();	

	glRotatef(180,-1, 0, 0);
	glTranslatef(-0.5f, -0.5f, -0.5f);
	glDrawElements(GL_TRIANGLES, 3*(this->nInd), GL_UNSIGNED_INT, this->ind);	
	glPopMatrix();

	//Plano yz
	glPushMatrix();
	glRotatef(90, 0, 1, 0);

	glPushMatrix();
	glTranslatef(-0.5f, -0.5f, -0.5f);
	glDrawElements(GL_TRIANGLES, 3*(this->nInd), GL_UNSIGNED_INT, this->ind);	
	glPopMatrix();	

	glPushMatrix();
	glRotatef(180,-1, 0, 0);
	glTranslatef(-0.5f, -0.5f, -0.5f);
	glDrawElements(GL_TRIANGLES, 3*(this->nInd), GL_UNSIGNED_INT, this->ind);	
	glPopMatrix();

	glPopMatrix();

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	
	glPopMatrix();
}

void Cube::setDiv(int numDivs)
{
	if (this->div==numDivs) return;

	this->div=numDivs;
	this->buildCube();
}

int Cube::index(int i, int j)
{
	return i+j*(this->div+1);
}
