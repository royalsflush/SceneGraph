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
#include "switch.h"
#include "mesh.h"

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

	Transform* transl = new Transform;
	transl->translate(10.0f, 2.5f, 10.0f);
	transl->addNode(box);

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
	theScene->addNode(transl);

	return theScene;
}

Scene* lightsTestScene(float w, float h)
{
	#ifdef _DBG
		printf("Setting up lights test scene\n");
	#endif

	Camera* theCamera = new Camera;
	theCamera->setZPlanes(1.0f, 100.0f);
	theCamera->setEye(0.0f, 0.0f, 10.0f);
	theCamera->setUp(0.0f, 1.0f, 0.0f);
	theCamera->setCenter(0.0f, 0.0f, 0.0f);
	theCamera->setAspectRatio(w/h);
	theCamera->setAngle(50.0f);
	theCamera->setManipulator(new VManipulator);

	Material* bluePlastic = new Material(0.5f, 0.5f, 0.5f);
	bluePlastic->setSpecular(0.5f, 0.5f, 0.5f);
	bluePlastic->setShininess(30);

	Entity* ball = new Entity(new Sphere(1.0f), bluePlastic);

	/* Luz no infinito - verde */	
	Light* l0 = new Light(0.0f, 10.0f, 0.0f, 0.0f);
	l0->setAmbient(0.0f, 0.2f, 0.0f, 1.0f);
	l0->setDiffuse(0.0f, 0.6f, 0.0f, 1.0f);
	l0->setSpecular(0.0f, 0.5f, 0.0f, 1.0f);

	l0->setSwitch(new Switch);
	
	/* Luz de spot vindo pelo lado direito - vermelha */
	Light* l1 = new Light(4.0f, 0.0f, 0.0f, 1.0f);
	l1->setAmbient(0.2f, 0.0f, 0.0f, 1.0f);
	l1->setDiffuse(0.6f, 0.0f, 0.0f, 1.0f);
	l1->setSpecular(0.5f, 0.0f, 0.0f, 1.0f);
	l1->setSpotDir(-1.0f, 0.0f, 0.0f);
	l1->setSpotCutoff(45);

	/* Luz de spot vindo de baixo, muito concentrada - ciano */
	Light* l2 = new Light(0.0f, -3.0f, 3.0f, 1.0f);
	l2->setAmbient(0.0f, 0.2f, 0.2f, 1.0f);
	l2->setDiffuse(0.0f, 0.5f, 0.5f, 1.0f);
	l2->setSpecular(0.5f, 0.5f, 0.5f, 1.0f);
	l2->setSpotDir(0.0f, 1.0f, -1.0f);
	l2->setSpotCutoff(60);
	l2->setSpotExp(128);

	Scene* theScene = new Scene;
	theScene->setClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	theScene->addNode(theCamera);
	theScene->setCamera(theCamera);
	theScene->addNode(l0);
	theScene->addNode(l1);
	theScene->addNode(l2);
	theScene->addNode(ball);

	return theScene;
}

Scene* meshTest(float w, float h)
{
	#ifdef _DBG
		printf("Setting up the mesh test scene\n");
	#endif

	Camera* theCamera = new Camera;
	theCamera->setZPlanes(1.0f, 100.0f);
	theCamera->setEye(0.0f, 0.0f, 10.0f);
	theCamera->setUp(0.0f, 1.0f, 0.0f);
	theCamera->setCenter(0.0f, 0.0f, 0.0f);
	theCamera->setAspectRatio(w/h);
	theCamera->setAngle(50.0f);
	theCamera->setManipulator(new VManipulator);

	Material* none = new Material(0.5f, 0.5f, 0.5f);
	none->setSpecular(0.5f, 0.5f, 0.5f);
	none->setShininess(60);

	Entity* bunny = new Entity(new Mesh("bunny.msh"), none);
	
	Light* l0 = new Light(0.0f, 5.0f, 0.0f, 1.0f);
	l0->setAmbient(0.2f, 0.2f, 0.2f, 1.0f);
	l0->setDiffuse(0.5f, 0.5f, 0.5f, 1.0f);
	l0->setSpecular(0.5f, 0.5f, 0.5f, 1.0f);

	Light* l2 = new Light(0.0f, -4.0f, 4.0f, 1.0f);
	l2->setAmbient(0.0f, 0.2f, 0.2f, 1.0f);
	l2->setDiffuse(0.0f, 0.5f, 0.5f, 1.0f);
	l2->setSpecular(0.5f, 0.5f, 0.5f, 1.0f);
	l2->setSpotDir(0.0f, 1.0f, -1.0f);
	l2->setSpotCutoff(60);
	l2->setSpotExp(128);

	Transform *t1 = new Transform;
	t1->translate(-0.8f, -1.0f, 6.0f);
	t1->addNode(bunny);
	t1->addNode(l2);

	Transform *t2 = new Transform;
	t2->translate(2.0f, -1.0f, 2.0f);
	t2->addNode(bunny);
	t2->addNode(l2);
	
	Transform *t3 = new Transform;
	t3->translate(-0.5f, 0.0f, -5.0f);
	t3->addNode(bunny);
	t3->addNode(l2);
	
	Scene* theScene = new Scene;
	theScene->setClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	theScene->addNode(theCamera);
	theScene->setCamera(theCamera);
	theScene->addNode(t1);
	theScene->addNode(t2);
	theScene->addNode(t3);
	theScene->addNode(l0);
	theScene->setGlobalLight(0.4, 0.1, 0.1, 1.0f);
	theScene->twoSidedLighting(true);
	theScene->localViewer(true);
	theScene->enableFog(true);
	theScene->setFogColor(0.8f, 0.8f, 0.8f, 1.0f);
	theScene->setFogMode(linear);
	theScene->setFogLim(4.0, 10.0);

	return theScene;
}

Scene* tableScene(float w, float h)
{
	#ifdef _DBG
		printf("Setting up the table scene\n");
	#endif 
}
