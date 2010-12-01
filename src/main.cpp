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
#include "animation.h"
#include "testScenes.h"

using namespace std;

#define WIN_W 800
#define WIN_H 600

void handleKeyPress(unsigned char k, int x, int y);
void initRender();
void handleResize(int w, int h);
void render();
void createScene();
void update(int value);

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WIN_W, WIN_H);

	glutCreateWindow("Demo - Scene Graph");
	initRender();
	
	glutKeyboardFunc(handleKeyPress);
	glutDisplayFunc(render);
	glutReshapeFunc(handleResize);
	
	createScene();
	glutTimerFunc(16, update, 0);

	glutMainLoop();

	return 0;
}

void handleKeyPress(unsigned char k, int x, int y)
{
	if (k==27) exit(0);
	else if (k == 'd') {
		printf("Opa, right pressed!\n");
		Animation* jump = Engine::getInstance().getAnimationByName("jump");
		jump->startAnimation();
	}
}

void initRender()
{
	Engine::getInstance().initRender();
}

void handleResize(int w, int h)
{
	Engine::getInstance().handleResize(w, h);
}

void render()
{
	Engine::getInstance().renderCurrentScene();	
}

void createScene()
{
	Engine::getInstance().setScene(pixarNotQuite(WIN_W, WIN_H));
}

void update(int value)
{
	Engine::getInstance().changeScene();
	glutPostRedisplay();
	glutTimerFunc(16, update, 0);
}
