//This main is for test purposes only

#include <stdio.h>
#include <stdlib.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "engine.h"
#include "renderer.h"
#include "openglrend.h"

using namespace std;

#define WIN_W 400
#define WIN_H 400

void handleKeyPress(unsigned char k, int x, int y);
void initRender();
void handleResize(int w, int h);
void render();

int main(int argc, char ** argv)
{
	OpenGLRenderer* r = new OpenGLRenderer;	
	Engine::getInstance().setRenderer(r);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WIN_W, WIN_H);

	glutCreateWindow("Demo - Scene Graph");
	initRender();
	
	glutDisplayFunc(render);
	glutKeyboardFunc(handleKeyPress);
	glutReshapeFunc(handleResize);
	
	glutMainLoop();

	return 0;
}

void handleKeyPress(unsigned char k, int x, int y)
{
	switch (k) {
		case 27: //ESC
			exit(0);
	}
}

void initRender()
{
	Engine::getInstance().initRender();
}

void handleResize(int w, int h)
{

glViewport(0, 0, w, h);
	
	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
	
	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,                  //The camera angle
				   (double)w / (double)h, //The width-to-height ratio
				   1.0,                   //The near z clipping coordinate
				   200.0);                //The far z clipping coordinate
}

void render()
{
	printf("grr");
	Engine::getInstance().renderCurrentScene();
}
