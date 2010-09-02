#include <stdio.h>

#include "engine.h"
#include "renderer.h"

Engine* Engine::theEngine = NULL;

Engine::Engine()
{
	theRenderer = NULL;
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

void Engine::renderCurrentScene()
{
	printf("huh?");

	if (theRenderer)
		theRenderer->renderSphere();
}
