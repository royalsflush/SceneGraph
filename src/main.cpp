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

//n for not ready
//r for ready
//j for jumped
static char lampState = 'n';

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
	else if (k == 's') { //WASD control	
		if (lampState!='n') return;
		Engine::getInstance().getAnimationByName("prepareJump")->startAnimation();
		lampState='r';
	}
	else if (k == 'w') {
		if (lampState!='r') return;
		Engine::getInstance().getAnimationByName("stand")->startAnimation();
		lampState='n';	
	}
	else if (k == 'd') {
		if (lampState!='r') return;
		Engine::getInstance().getAnimationByName("jump")->startAnimation();
		lampState='j';		
	}
	else if (k=='l') { //change camera
		Engine::getInstance().changeCameraTo("lampCam");		
	}
	else if (k=='m') {
		Engine::getInstance().changeCameraTo("mainC");
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
