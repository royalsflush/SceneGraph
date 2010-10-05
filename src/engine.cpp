#include <stdio.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "engine.h"
#include "renderer.h"
#include "scene.h"

Engine* Engine::theEngine = NULL;

Engine::Engine()
{
	theRenderer = NULL;
	curr = NULL;
}

Engine::~Engine()
{
	delete theRenderer;
}

void Engine::setRenderer(Renderer* newRend)
{
	if (theRenderer)
		delete theRenderer;

	theRenderer = newRend;
}

void Engine::setScene(Scene* newScene)
{
	if (curr)
		delete curr;

	curr = newScene;
}

Engine& Engine::getInstance()
{
	if (theEngine == NULL)
		theEngine = new Engine;

	return *theEngine;
}

void Engine::initRender()
{
	if (theRenderer)
		theRenderer->init();
		
}

void Engine::handleResize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity(); 
	gluPerspective(45.0,                  //The camera angle
			(double)w / (double)h, //The width-to-height ratio
			1.0,                   //The near z clipping coordinate
			200.0);                //The far z clipping coordinate

}

void Engine::renderCurrentScene()
{
	if (curr)
		curr->render();
}
