#include <stdio.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "group.h"
#include "scene.h"
#include "camera.h"
#include "environ.h"

Scene::Scene()
{
	this->cam=NULL;
	env = new Environ;
}

void Scene::render() 
{
	Group::setupCamera();
	Group::setupLights();
	Group::render();
}

int Scene::setupCamera()
{
	return Group::setupCamera();
}

void Scene::changeAspect(float nasp)
{
	if (!this->cam) {
		#ifdef _DBG
			printf("Someone forgot to set up the camera!!\n");
		#endif

		return;
	}

	this->cam->setAspectRatio(nasp);
}

void Scene::setCamera(Camera* c)
{
	this->cam=c;
}

int Scene::setupLights()
{
	return Group::setupLights();
}

void Scene::setClearColor(float r, float g, float b, float a)
{
	env->setClearColor(r, g, b, a);
}

void Scene::setGlobalLight(float r, float g, float b, float a)
{
	env->setGlobalLight(r, g, b, a);
}

void Scene::twoSidedLighting(bool b)
{
	env->twoSidedLighting(b);
}

void Scene::localViewer(bool b)
{
	env->localViewer(b);
}

void Scene::enableFog(bool b)
{
	env->enableFog(b);
}

void Scene::setFogColor(float r, float g, float b, float a)
{
	env->setFogColor(r, g, b, a);
}

void Scene::setFogLim(float start, float end)
{
	env->setFogLim(start, end);
}

void Scene::setFogDensity(float d)
{
	env->setFogDensity(d);
}

void Scene::setFogMode(fogModes f)
{
	env->setFogMode(f);
}
