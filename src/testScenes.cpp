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
#include "texture.h"

Scene* tex(float w, float h) 
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
	theCamera->setZCenter(10.0f);

	Material* greenPlastic = new Material(0.0f, 0.5f, 0.0f);
	greenPlastic->setSpecular(0.5f, 0.5f, 0.5f);
	greenPlastic->setShininess(128);

	Texture* tex = new Texture("../images/vtr.bmp");
	tex->setPlane(S, 1.0f, 0.0f, 0.0f, 0.0f, false);
	tex->setPlane(T, 0.0f, -1.0f, 0.0f, 0.0f, false);

	Entity* box = new Entity(new Cube(5.0f, 1.0f, 5.0f), tex);
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

Scene* tessCube(float w, float h)
{
	Camera* theCamera = new Camera;
	theCamera->setZPlanes(1.0f, 100.0f);
	theCamera->setEye(0.0f, 0.0f, 10.0f);
	theCamera->setUp(0.0f, 1.0f, 0.0f);
	theCamera->setCenter(0.0f, 0.0f, 0.0f);
	theCamera->setAspectRatio(w/h);
	theCamera->setAngle(50.0f);
	theCamera->setManipulator(new VManipulator);
	theCamera->setZCenter(10.0f);

	Material* bluePlastic = new Material(0.5f, 0.5f, 0.5f);
	bluePlastic->setSpecular(0.5f, 0.5f, 0.5f);
	bluePlastic->setShininess(30);

	Entity* ball = new Entity(new Cube(2.0f, 2.0f, 2.0f), bluePlastic);

	/* Luz verde vindo de cima */	
	Light* l0 = new Light(0.0f, 3.0f, 0.0f, 1.0f);
	l0->setAmbient(0.0f, 0.2f, 0.0f, 1.0f);
	l0->setDiffuse(0.0f, 0.6f, 0.0f, 1.0f);
	l0->setSpecular(0.0f, 0.5f, 0.0f, 1.0f);
	l0->setSpotDir(0.0f, -1.0f, 0.0f);
	l0->setSpotCutoff(80);
	l0->setSpotExp(90);

	l0->setSwitch(new Switch);
	
	/* Luz de spot vindo pelo lado direito - vermelha */
	Light* l1 = new Light(3.0f, 0.0f, 0.0f, 1.0f);
	l1->setAmbient(0.2f, 0.0f, 0.0f, 1.0f);
	l1->setDiffuse(0.6f, 0.0f, 0.0f, 1.0f);
	l1->setSpecular(0.5f, 0.0f, 0.0f, 1.0f);
	l1->setSpotDir(-1.0f, 0.0f, 0.0f);
	l1->setSpotCutoff(30);
	l1->setSpotExp(30);

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
	theCamera->setZCenter(10.0f);

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
	theCamera->setZCenter(10.0f);

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

	Camera* theCamera = new Camera;
	theCamera->setZPlanes(1.0f, 100.0f);
	theCamera->setEye(0.0f, 0.0f, 10.0f);
	theCamera->setUp(0.0f, 1.0f, 0.0f);
	theCamera->setCenter(0.0f, 0.0f, 0.0f);
	theCamera->setAspectRatio(w/h);
	theCamera->setAngle(50.0f);
	theCamera->setManipulator(new VManipulator);

/*
	Texture* walls = new Texture("../images/walltext.bmp");
	walls->setPlane(S, 0.2f, 0.0f, 0.0f, 0.0f, false);
	walls->setPlane(T, 0.0f, 0.2f, 0.0f, 0.0f, false);
*/

	/* Codigo para a sala em si */

	Material* walls = new Material(0.7f, 0.55f, 0.425f);
	walls->setSpecular(0.5f, 0.435f, 0.375f);
	walls->setShininess(60);
	
 	Entity* room = new Entity(new Cube(20.0, 20.0f, 40.0f), walls);

	/* Codigo para a luz comprida */

	Transform* lightPos = new Transform;
	lightPos->translate(0.0f, 9.0f, 0.0f);

	Material* lightMat = new Material(1.0f, 1.0f, 1.0f);
	lightMat->setSpecular(0.2f, 0.2f, 0.2f);
	lightMat->setShininess(60);

	Entity* lightObj = new Entity(new Cube(1.0f, 0.5f, 5.0f), lightMat);
	lightPos->addNode(lightObj);

	Light* bigLight1 = new Light(0.0f, 0.0f, 0.0f, 1.0f);
	bigLight1->setAmbient(0.2f, 0.2f, 0.2f, 1.0f);
	bigLight1->setDiffuse(0.6f, 0.6f, 0.6f, 1.0f);
	bigLight1->setSpecular(0.5f, 0.5f, 0.5f, 1.0f);
	bigLight1->setSpotDir(0.0f, -1.0f, 0.0f);
	bigLight1->setSpotCutoff(120);
	bigLight1->setSpotExp(30);
	
	Light* bigLight2 = new Light(0.0f, 0.0f, 1.0f, 1.0f);
	bigLight2->setAmbient(0.2f, 0.2f, 0.2f, 1.0f);
	bigLight2->setDiffuse(0.6f, 0.6f, 0.6f, 1.0f);
	bigLight2->setSpecular(0.5f, 0.5f, 0.5f, 1.0f);
	bigLight2->setSpotDir(0.0f, -1.0f, 0.0f);
	bigLight2->setSpotCutoff(120);
	bigLight2->setSpotExp(30);
	
	Light* bigLight3 = new Light(0.0f, 0.0f, -1.0f, 1.0f);
	bigLight3->setAmbient(0.2f, 0.2f, 0.2f, 1.0f);
	bigLight3->setDiffuse(0.6f, 0.6f, 0.6f, 1.0f);
	bigLight3->setSpecular(0.5f, 0.5f, 0.5f, 1.0f);
	bigLight3->setSpotDir(0.0f, -1.0f, 0.0f);
	bigLight3->setSpotCutoff(120);
	bigLight3->setSpotExp(30);
	
	lightPos->addNode(bigLight1);
	lightPos->addNode(bigLight3);
	lightPos->addNode(bigLight2);

	/* a mesa */

	Transform* tablePos = new Transform;
	tablePos->translate(7.0f, -10.0f, -15.0f);

	Material* greyPlastic = new Material(0.5f, 0.5f, 0.5f);
	greyPlastic->setSpecular(0.5f, 0.5f, 0.5f);
	greyPlastic->setShininess(90);

	Entity* tableTop = new Entity(new Cube(5.0f, 0.2f, 8.0f), greyPlastic);
	Transform* tableTopTransform = new Transform;
	tableTopTransform->translate(0.0f, 2.5f, 0.0f);
	tableTopTransform->addNode(tableTop);
	tablePos->addNode(tableTopTransform);

	Entity* tableLeg = new Entity(new Cube(0.5f, 2.0f, 8.0f), greyPlastic);
	Transform* tableLegTransform = new Transform;
	tableLegTransform->translate(0.0f, 1.4f, 0.0f);
	tableLegTransform->addNode(tableLeg);
	tablePos->addNode(tableLegTransform);

	Entity* tableFoot = new Entity(new Cube(2.0f, 0.5f, 0.5f), greyPlastic);
	Transform* tableFootT1 = new Transform;
	tableFootT1->translate(0.0f, 0.25f, 3.75f);
	tableFootT1->addNode(tableFoot);
	tablePos->addNode(tableFootT1);
	
	Transform* tableFootT2 = new Transform;
	tableFootT2->translate(0.0f, 0.25f, -3.75f);
	tableFootT2->addNode(tableFoot);
	tablePos->addNode(tableFootT2);

	/* Montando a cena */

	Scene* theScene = new Scene;
	theScene->setClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	theScene->addNode(theCamera);
	theScene->setCamera(theCamera);
	
	theScene->addNode(room);
	theScene->addNode(lightPos);
	theScene->addNode(tablePos);

	return theScene;
}
