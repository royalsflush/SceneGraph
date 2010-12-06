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
#include "animation.h"

Scene::Scene(const char* name) : Group(name, "Scene"), currCam(NULL)
{
	env = new Environ;
}

void Scene::render() 
{
	Scene::setupCamera();
	Group::setupLights();
	Group::render();
}

int Scene::setupCamera()
{
	while (glGetError() != GL_STACK_UNDERFLOW) { 
		glPopMatrix();
	}

	return Group::setupCamera();
}

void Scene::changeAspect(float nasp)
{
	if (!this->currCam) {
		#ifdef _DBG
			printf("Someone forgot to set up the camera!!\n");
		#endif

		return;
	}

	this->currCam->setAspectRatio(nasp);
}

void Scene::activateCamera(const char* name)
{
	setbuf(stdout,NULL);
	Camera* newCam = (Camera*) this->findNode(name, "Camera");

	if (!newCam) //no camera with this name!
		return;

	printf("New cam is: %p and curr cam is: %p\n", newCam, this->currCam);
	
	if (this->currCam) 
		this->currCam->activate(false);

	this->currCam = newCam;
	this->currCam->activate(true);
}

void Scene::addAnimation(Animation* a, const char* name)
{
	if (animations.find(name) != animations.end())
		return;

	animations[name]=a;	
	a->setScene(this);
}

Animation* Scene::getAnimationByName(const char* name)
{
	return this->animations[name];
}

void Scene::runAnimations()
{
	map<string, Animation*>::iterator it = animations.begin();

	for (it; it!=animations.end(); ++it) {
		if (it->second->isActive())
			it->second->animate(0);
	}
}

/* This functions are just wrappers to the environ class */

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
