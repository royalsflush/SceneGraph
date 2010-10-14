#include <stdio.h>
#include <stdlib.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "environ.h"

enum {
	R=0, G, B, A
};

void Environ::setGlobalLight(float r, float g, float b, float a)
{
	float globalLight[4] = {r, g, b, a};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalLight);
}

void Environ::twoSidedLighting(bool b)
{
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, b? GL_TRUE : GL_FALSE);
}

void Environ::localViewer(bool b)
{
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, b? GL_TRUE : GL_FALSE);
}

void Environ::setClearColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}

void Environ::enableFog(bool b)
{
	if (b) glEnable(GL_FOG);
	else glDisable(GL_FOG);
}

void Environ::setFogColor(float r, float g, float b, float a)
{
	float fogColor[4] = {r, g, b, a};
	glFogfv(GL_FOG_COLOR, fogColor);
}

void Environ::setFogDensity(float d)
{
	glFogf(GL_FOG_DENSITY, d);
}

void Environ::setFogLim(float start, float end)
{
	glFogf(GL_FOG_START, start);
	glFogf(GL_FOG_END, end);
}

void Environ::setFogMode(fogModes f)
{
	switch (f) {
		case linear:
			glFogi(GL_FOG_MODE, GL_LINEAR);
			break;
		case exp:
			glFogi(GL_FOG_MODE, GL_EXP);
			break;
		case exp2:
			glFogi(GL_FOG_MODE, GL_EXP2);
			break;
	}
}
