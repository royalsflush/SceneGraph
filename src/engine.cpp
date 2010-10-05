#include <stdio.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "engine.h"
#include "scene.h"

Engine* Engine::theEngine = NULL;

Engine::Engine()
{
	curr = NULL;
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
	#ifdef _DBG
		printf("Engine->initRender()\n");
	#endif

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);		
}

void Engine::handleResize(int w, int h)
{
	#ifdef _DBG
		printf("Engine->handleResize(%d, %d)\n", w, h);
	#endif
	
	glViewport(0, 0, w, h);

	curr->changeAspect((float)w/(float)h);
	curr->setupCamera();
}

void Engine::renderCurrentScene()
{
	#ifdef _DBG
		printf("Engine->renderCurrentScene()\n");
	#endif

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	if (curr)
		curr->render();

	glutSwapBuffers();
}
