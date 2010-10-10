// manipulator.cpp
// Visualização 3D
// W. Celes - celes@inf.puc-rio.br
// PUC-Rio, Set 2010

#include "manipulator.h"
#include "vector.h"

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.1459
#define TORAD(x) (x*180.0f/PI)

VManipulator* VManipulator::s_current = 0;

// internal control
static char g_state = ' ';
static int g_x0, g_y0;

static VVector map (int x, int y)
{
	VVector v;
	int vp[4];
	glGetIntegerv(GL_VIEWPORT,vp);
	int radius = vp[2] < vp[3] ? vp[2]/2 : vp[3]/2;
	v.x = (float)((x-vp[0]) - vp[2]/2) / radius;
	v.y = (float)((vp[3]-y-vp[0]) - vp[3]/2) / radius;
	float len = sqrt(v.x*v.x + v.y*v.y);
	if (len > 1.0) {
		v.x /= len;
		v.y /= len;
		v.z = 0.0f;
	}
	else {
		v.z = sqrt(1 - v.x*v.x - v.y*v.y);
	}
	return v;
}

static void mouse(int button, int state, int x, int y)
{
	if (!VManipulator::GetCurrent())
		return;
	if (state == GLUT_DOWN) {
		g_x0 = x; g_y0 = y;
		if (button == GLUT_LEFT_BUTTON) {
			g_state = 'r';

			#ifdef _DBG
				printf("Pressed left button\n"); 
			#endif
		}
		else if (button == GLUT_RIGHT_BUTTON) {
			g_state = 's';
		
			#ifdef _DBG
				printf("Pressed right button\n"); 
			#endif
		}
		else
			g_state = ' ';
	}
}

static void motion (int x, int y)
{
	if (!VManipulator::GetCurrent())
		return;
	int dx = abs(x-g_x0);
	int dy = abs(y-g_y0);
	if ( dx > 1 || dy > 1) {
		if (g_state == 'r') {
			VVector v0 = map(g_x0, g_y0);
			VVector v1 = map(x, y);
			VVector r = Cross(v0, v1);
			VManipulator::GetCurrent()->Rotate(TORAD(2*asin(r.Length())),r.x,r.y,r.z);

		}
		else if (g_state == 's') {
			int vp[4];
			glGetIntegerv(GL_VIEWPORT,vp);
			float f = dx > dy ? (float)(x-g_x0) / vp[2] : (float) (-y+g_y0) / vp[3];
			VManipulator::GetCurrent()->Scale(1+f, 1+f, 1+f);
		}
		g_x0 = x; g_y0 = y;
		glutPostRedisplay();
	}
}

void VManipulator::SetCurrent (VManipulator* manip)
{
	s_current = manip;
}

VManipulator* VManipulator::GetCurrent ()
{
	return s_current;
}

VManipulator::VManipulator()
{
	this->Identity();
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	SetCurrent(this);
}

void VManipulator::SetZCenter (float zcenter)
{
	m_zcenter = zcenter;
}

void VManipulator::Identity ()
{
	glPushAttrib(GL_TRANSFORM_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glGetFloatv(GL_MODELVIEW_MATRIX, m_matrix);
	glPopMatrix();
	glPopAttrib();
}

void VManipulator::Rotate (float angle, float rx, float ry, float rz)
{
	glPushAttrib(GL_TRANSFORM_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glRotatef(angle, rx, ry, rz);
	glMultMatrixf(m_matrix);
	glGetFloatv(GL_MODELVIEW_MATRIX, m_matrix);
	glPopMatrix();
	glPopAttrib();
}

void VManipulator::Scale (float sx, float sy, float sz)
{
	glPushAttrib(GL_TRANSFORM_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glScalef(sx, sy, sz);
	glMultMatrixf(m_matrix);
	glGetFloatv(GL_MODELVIEW_MATRIX, m_matrix);
	glPopMatrix();
	glPopAttrib();
}

void VManipulator::Load ()
{
	glTranslatef(0.0f, 0.0f, -m_zcenter);
	glMultMatrixf(m_matrix);
	glTranslatef(0.0f, 0.0f, m_zcenter);
}
