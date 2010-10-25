#include <stdio.h>
#include <stdlib.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "appearance.h"
#include "texture.h"
#include "imageloader.h"

int Texture::nextId=0;

Texture::Texture(char* filename)
{
	Image* img = loadBMP(filename);
	glGenTextures(1, &this->id);
	Texture::nextId++;
	glBindTexture(GL_TEXTURE_2D, this->id);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, img->width, img->height, GL_RGB, GL_UNSIGNED_BYTE, img->pixels);
	delete img;

	for (int i=0; i<4; i++)
		this->coordPlane[i] = GL_OBJECT_LINEAR;
}

void Texture::setPlane(texcoord tc, float a, float b, float c, float d, bool eyeCoord)
{
	this->planes[tc][0]=a;
	this->planes[tc][1]=b;
	this->planes[tc][2]=c;
	this->planes[tc][3]=d;
	
	if (eyeCoord) {
		this->coordPlane[tc] = GL_EYE_LINEAR;
	}
	
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_S, GL_OBJECT_PLANE, this->planes[S]);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_T, GL_OBJECT_PLANE, this->planes[T]);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
}

void Texture::load()
{
	#ifdef _DBG
		printf("Loading texture\n");
	#endif

	glPushAttrib(GL_TEXTURE_BIT);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, this->id);
}

void Texture::unload()
{
	#ifdef _DBG
		printf("Unloading texture\n");
	#endif

	glPopAttrib();
}
