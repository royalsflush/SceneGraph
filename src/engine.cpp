#include <stdio.h>

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

void Engine::renderCurrentScene()
{
	if (theRenderer)
		theRenderer->renderSphere();
}
