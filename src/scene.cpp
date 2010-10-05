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

void Scene::render() 
{ 
	#ifdef _DBG
		printf("Scene->render()\n");
	#endif


	Group::setupCamera();
	Group::setupLights();
	Group::render();
}

int Scene::setupCamera()
{
	#ifdef _DBG
		printf("Scene->setupCamera()\n");
	#endif

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
	#ifdef _DBG
		printf("Scene->setupLights()\n");
	#endif
		
	return Group::setupLights();
}
