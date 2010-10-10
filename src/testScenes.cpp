#include "testScenes.h"
#include "engine.h"
#include "scene.h"
#include "camera.h"
#include "transform.h"
#include "material.h"
#include "entity.h"
#include "light.h"
#include "manipulator.h"
#include "sphere.h"
#include "cube.h"

Scene* demoScene(float w, float h)
{
	#ifdef _DBG
		printf("Setting up demo scene\n");
	#endif

	Camera* theCamera = new Camera;
	theCamera->setZPlanes(1.0f, 100.0f);
	theCamera->setEye(10.0f, 5.0f, 20.0f);
	theCamera->setUp(0.0f, 1.0f, 0.0f);
	theCamera->setCenter(10.0f, 3.0f, 10.0f);
	theCamera->setAspectRatio(w/h);
	theCamera->setAngle(50.0f);
	theCamera->setManipulator(new VManipulator);

	Material* redPlastic = new Material(0.5f, 0.0f, 0.0f);
	redPlastic->setSpecular(0.5f, 0.5f, 0.5f);
	redPlastic->setShininess(128);

	Material* greenPlastic = new Material(0.0f, 0.5f, 0.0f);
	greenPlastic->setSpecular(0.5f, 0.5f, 0.5f);
	greenPlastic->setShininess(128);

	Entity* box = new Entity(new Cube(5.0f, 1.0f, 5.0f), redPlastic);
	Entity* ball = new Entity(new Sphere(1.0f), greenPlastic);

	Transform* rt = new Transform;
	rt->rotate(30, 0.0f, 0.0f, 0.0f);

	Transform* transl = new Transform;
	transl->translate(10.0f, 2.5f, 10.0f);
	transl->addNode(box);
	rt->addNode(transl);

	Transform* tr2 = new Transform;
	tr2->translate(0.0f, 1.5f, 0.0f); 
	tr2->addNode(ball);
	transl->addNode(tr2);

	Light* l0 = new Light(10.0f, 20.0f, 10.0f, 1.0f);
	l0->setAmbient(0.2f, 0.2f, 0.2f, 1.0f);
	l0->setDiffuse(0.6f, 0.6f, 0.6f, 1.0f);
	l0->setSpecular(0.5f, 0.5f, 0.5f, 1.0f);

	Scene* theScene = new Scene;
	theScene->addNode(theCamera);
	theScene->setCamera(theCamera);
	theScene->addNode(l0);
	theScene->addNode(rt);

	return theScene;
}

Scene* lightsTestScene(float w, float h)
{
	#ifdef _DBG
		printf("Setting up lights test scene\n");
	#endif

	Camera* theCamera = new Camera;
	theCamera->setZPlanes(1.0f, 100.0f);
	theCamera->setEye(0.0f, 0.0f, 20.0f);
	theCamera->setUp(0.0f, 1.0f, 0.0f);
	theCamera->setCenter(0.0f, 0.0f, 0.0f);
	theCamera->setAspectRatio(w/h);
	theCamera->setAngle(50.0f);
	theCamera->setManipulator(new VManipulator);

	Material* whitePlastic = new Material(0.5f, 0.5f, 0.0f);
	whitePlastic->setSpecular(0.3f, 0.3f, 0.3f);
	whitePlastic->setShininess(128);

	Entity* ball = new Entity(new Sphere(2.0f), whitePlastic);
	
	Light* l0 = new Light(0.0f, 4.0f, 0.0f, 1.0f);
	l0->setAmbient(0.4f, 0.4f, 0.4f, 1.0f);
	l0->setDiffuse(0.6f, 0.6f, 0.6f, 1.0f);
	l0->setSpecular(0.5f, 0.5f, 0.5f, 1.0f);
	
	Scene* theScene = new Scene;
	theScene->setClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	theScene->addNode(theCamera);
	theScene->setCamera(theCamera);
	theScene->addNode(l0);
	theScene->addNode(ball);

	return theScene;
}

Scene* tableScene(float w, float h)
{

}
