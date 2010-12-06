#include "testScenes.h"
#include "engine.h"
#include "animation.h"

#include "scene.h"
#include "camera.h"
#include "transform.h"
#include "light.h"

#include "camMan.h"
#include "manipulator.h"
#include "fpview.h"
#include "switch.h"

#include "entity.h"

#include "sphere.h"
#include "cube.h"
#include "mesh.h"

#include "texture.h"
#include "material.h"

Scene* tessCube(float w, float h)
{
	Camera* theCamera = new Camera("mainC");
	theCamera->setZPlanes(1.0f, 100.0f);
	theCamera->setEye(0.0f, 0.0f, 10.0f);
	theCamera->setUp(0.0f, 1.0f, 0.0f);
	theCamera->setCenter(0.0f, 0.0f, 0.0f);
	theCamera->setAspectRatio(w/h);
	theCamera->setAngle(50.0f);
	theCamera->setManipulator(new VManipulator);
	theCamera->setZCenter(10.0f);

	Material* greyPlastic = new Material(0.5f, 0.5f, 0.5f);
	greyPlastic->setSpecular(0.5f, 0.5f, 0.5f);
	greyPlastic->setShininess(30);

	Entity* cube = new Entity("cube", new Cube(2.0f, 2.0f, 2.0f), greyPlastic);

	/* Luz verde vindo de cima */	
	Light* l0 = new Light("greenUpperL", 0.0f, 3.0f, 0.0f, 1.0f);
	l0->setAmbient(0.0f, 0.2f, 0.0f, 1.0f);
	l0->setDiffuse(0.0f, 0.6f, 0.0f, 1.0f);
	l0->setSpecular(0.0f, 0.5f, 0.0f, 1.0f);
	l0->setSpotDir(0.0f, -1.0f, 0.0f);
	l0->setSpotCutoff(80);
	l0->setSpotExp(90);

	l0->setSwitch(new Switch);
	
	/* Luz de spot vindo pelo lado direito - vermelha */
	Light* l1 = new Light("redRightL", 3.0f, 0.0f, 0.0f, 1.0f);
	l1->setAmbient(0.2f, 0.0f, 0.0f, 1.0f);
	l1->setDiffuse(0.6f, 0.0f, 0.0f, 1.0f);
	l1->setSpecular(0.5f, 0.0f, 0.0f, 1.0f);
	l1->setSpotDir(-1.0f, 0.0f, 0.0f);
	l1->setSpotCutoff(30);
	l1->setSpotExp(30);

	/* Luz de spot vindo de baixo, muito concentrada - ciano */
	Light* l2 = new Light("cyanLowL", 0.0f, -3.0f, 3.0f, 1.0f);
	l2->setAmbient(0.0f, 0.2f, 0.2f, 1.0f);
	l2->setDiffuse(0.0f, 0.5f, 0.5f, 1.0f);
	l2->setSpecular(0.5f, 0.5f, 0.5f, 1.0f);
	l2->setSpotDir(0.0f, 1.0f, -1.0f);
	l2->setSpotCutoff(60);
	l2->setSpotExp(128);

	Scene* theScene = new Scene("mainScene");
	theScene->setClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	theScene->addNode(theCamera);
	theScene->activateCamera("mainC");
	theScene->addNode(l0);
	theScene->addNode(l1);
	theScene->addNode(l2);
	theScene->addNode(cube);

	return theScene;
}

Scene* demoScene(float w, float h)
{
	#ifdef _DBG
		printf("Setting up demo scene\n");
	#endif

	Camera* theCamera = new Camera("mainC");
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

	Entity* box = new Entity("box", new Cube(5.0f, 1.0f, 5.0f), redPlastic);
	Entity* ball = new Entity("ball", new Sphere(1.0f), greenPlastic);

	Transform* transl = new Transform("boxT");
	transl->translate(10.0f, 2.5f, 10.0f);
	transl->addNode(box);

	Transform* tr2 = new Transform("ballT");
	tr2->translate(0.0f, 1.5f, 0.0f); 
	tr2->addNode(ball);
	transl->addNode(tr2);

	Light* l0 = new Light("mainL", 10.0f, 20.0f, 10.0f, 1.0f);
	l0->setAmbient(0.2f, 0.2f, 0.2f, 1.0f);
	l0->setDiffuse(0.6f, 0.6f, 0.6f, 1.0f);
	l0->setSpecular(0.5f, 0.5f, 0.5f, 1.0f);

	Scene* theScene = new Scene("mainScene");
	theScene->addNode(theCamera);
	theScene->activateCamera("mainC");
	theScene->addNode(l0);
	theScene->addNode(transl);

	return theScene;
}

Scene* lightsTestScene(float w, float h)
{
	#ifdef _DBG
		printf("Setting up lights test scene\n");
	#endif

	Camera* theCamera = new Camera("main");
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

	Entity* ball = new Entity("ball", new Sphere(1.0f), bluePlastic);

	/* Luz no infinito - verde */	
	Light* l0 = new Light("greenL", 0.0f, 10.0f, 0.0f, 0.0f);
	l0->setAmbient(0.0f, 0.2f, 0.0f, 1.0f);
	l0->setDiffuse(0.0f, 0.6f, 0.0f, 1.0f);
	l0->setSpecular(0.0f, 0.5f, 0.0f, 1.0f);

	l0->setSwitch(new Switch);
	
	/* Luz de spot vindo pelo lado direito - vermelha */
	Light* l1 = new Light("redRightL", 4.0f, 0.0f, 0.0f, 1.0f);
	l1->setAmbient(0.2f, 0.0f, 0.0f, 1.0f);
	l1->setDiffuse(0.6f, 0.0f, 0.0f, 1.0f);
	l1->setSpecular(0.5f, 0.0f, 0.0f, 1.0f);
	l1->setSpotDir(-1.0f, 0.0f, 0.0f);
	l1->setSpotCutoff(45);

	/* Luz de spot vindo de baixo, muito concentrada - ciano */
	Light* l2 = new Light("cyanLowL", 0.0f, -3.0f, 3.0f, 1.0f);
	l2->setAmbient(0.0f, 0.2f, 0.2f, 1.0f);
	l2->setDiffuse(0.0f, 0.5f, 0.5f, 1.0f);
	l2->setSpecular(0.5f, 0.5f, 0.5f, 1.0f);
	l2->setSpotDir(0.0f, 1.0f, -1.0f);
	l2->setSpotCutoff(60);
	l2->setSpotExp(128);

	Scene* theScene = new Scene("mainScene");
	theScene->setClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	theScene->addNode(theCamera);
	theScene->activateCamera("mainC");
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

	Camera* theCamera = new Camera("mainC");
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

	Entity* bunny = new Entity("bunny", new Mesh("bunny.msh"), none);
	
	Light* l0 = new Light("mainL", 0.0f, 5.0f, 0.0f, 1.0f);
	l0->setAmbient(0.2f, 0.2f, 0.2f, 1.0f);
	l0->setDiffuse(0.5f, 0.5f, 0.5f, 1.0f);
	l0->setSpecular(0.5f, 0.5f, 0.5f, 1.0f);

	Light* l2 = new Light("cyanL", 0.0f, -4.0f, 4.0f, 1.0f);
	l2->setAmbient(0.0f, 0.2f, 0.2f, 1.0f);
	l2->setDiffuse(0.0f, 0.5f, 0.5f, 1.0f);
	l2->setSpecular(0.5f, 0.5f, 0.5f, 1.0f);
	l2->setSpotDir(0.0f, 1.0f, -1.0f);
	l2->setSpotCutoff(60);
	l2->setSpotExp(128);

	Transform *t1 = new Transform("bunny1T");
	t1->translate(-0.8f, -1.0f, 6.0f);
	t1->addNode(bunny);
	t1->addNode(l2);

	Transform *t2 = new Transform("bunny2T");
	t2->translate(2.0f, -1.0f, 2.0f);
	t2->addNode(bunny);
	t2->addNode(l2);
	
	Transform *t3 = new Transform("bunny3T");
	t3->translate(-0.5f, 0.0f, -5.0f);
	t3->addNode(bunny);
	t3->addNode(l2);
	
	Scene* theScene = new Scene("mainScene");
	theScene->setClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	theScene->addNode(theCamera);
	theScene->activateCamera("mainC");
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

/* Funcoes para fazer a cena da mesa */
Transform* buildChair(Texture* t, Material* m);
Transform* buildTable(Material* m);
Transform* buildBigLight();
Transform* buildLamp();

Scene* tableScene(float w, float h)
{
	char tmpStr[30];

	#ifdef _DBG
		printf("Setting up the table scene\n");
	#endif

	Camera* theCamera = new Camera("mainC");
	theCamera->setZPlanes(1.0f, 100.0f);
	theCamera->setEye(8.0f, -5.0f, 15.0f);
	theCamera->setUp(0.0f, 1.0f, 0.0f);
	theCamera->setCenter(8.0f, -5.0f, 0.0f);
	theCamera->setAspectRatio(w/h);
	theCamera->setAngle(50.0f);
	theCamera->setManipulator(new VManipulator);
	theCamera->setZCenter(20.0f);

	/* Codigo para a sala em si */

	Material* walls = new Material(0.3f, 0.3f, 0.3f);
	walls->setSpecular(0.2f, 0.2f, 0.2f);
	walls->setShininess(50);
	
 	Entity* room = new Entity("room", new Cube(20.0, 0.0f, 40.0f), walls);
	Transform* roomT = new Transform("roomT");
	roomT->translate(0.0f, -7.5f, 0.0f);
	roomT->addNode(room);

	Texture* wood = new Texture("../images/teakwood.bmp");
	wood->setPlane(S, 1.0f, 0.0f, 0.0f, 0.0f, false); 
	wood->setPlane(T, 0.0f, 1.0f, 0.0f, 0.0f, false); 
	
	Material* greyPlastic = new Material(0.2f, 0.2f, 0.2f);
	greyPlastic->setSpecular(0.5f, 0.5f, 0.5f);
	greyPlastic->setShininess(90);

	Entity* ball = new Entity("ball", new Sphere(1.0f), greyPlastic);
	
	/* Codigo para a luz comprida */
	Transform* lightPos = buildBigLight();

	/* a mesa */
	Transform* tablePos = buildTable(greyPlastic);

	/* cadeiras */
	Transform* chairCont = buildChair(wood, greyPlastic); 
	Transform** chairPos = new Transform*[5];

	for (int i=0; i<5; i++) {
		sprintf(tmpStr, "chairPos%d", i+1);
		chairPos[i] = new Transform(tmpStr);
	}

	chairPos[0]->rotate(90, 0.0f, 1.0f, 0.0f);
	chairPos[0]->translate(-3.0f, 0.0f, 5.0f);

	chairPos[1]->rotate(100, 0.0f, 1.0f, 0.0f);
	chairPos[1]->translate(3.0f, 0.0f, 7.0f);

	chairPos[2]->rotate(80, 0.0f, 1.0f, 0.0f);
	chairPos[2]->translate(5.0f, 0.0, 0.0f);

	chairPos[3]->rotate(95, 0.0f, 1.0f, 0.0f);
	chairPos[3]->translate(-2.0f, 0.0f, -3.0f);

	chairPos[4]->rotate(120, 0.0, 1.0f, 0.0f);
	chairPos[4]->translate(6.0f, 0.0f, 5.0f);

	for (int i=0; i<5; i++)
		chairPos[i]->addNode(chairCont);

	/* Coelho sobre uma cadeira */

	Entity* bunny = new Entity("bunny", new Mesh("bunny.msh"), greyPlastic);
	Transform* bunnyT = new Transform("bunnyT");
	bunnyT->translate(0.5f, -5.2f, -0.3f);
	bunnyT->addNode(bunny);
	chairPos[4]->addNode(bunnyT); 
	
	Transform* lampPos = buildLamp();
	chairPos[2]->addNode(lampPos);

	/* Montando a cena */

	Scene* theScene = new Scene("mainScene");
	theScene->setClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	theScene->addNode(theCamera);
	theScene->activateCamera("mainC");
	
	theScene->addNode(roomT);
	//theScene->addNode(ball);
	theScene->addNode(lightPos);
	theScene->addNode(tablePos);

	for (int i=0; i<5; i++)
		theScene->addNode(chairPos[i]);

	//Fog!

	theScene->enableFog(true);
	theScene->setFogColor(0.2f, 0.2f, 0.2f, 1.0f);
	theScene->setFogMode(linear);
	theScene->setFogLim(5.0, 40.0);


	return theScene;
}

Transform* buildLamp()
{
	Transform* luxPos = new Transform("luxPos");

	Material* redPlastic = new Material(0.5f, 0.0f, 0.0f);
	redPlastic->setSpecular(0.2f, 0.2f, 0.2f);
	redPlastic->setShininess(1);	
	
	Material* redLamp = new Material(0.2f, 0.2f, 0.2f);
	redLamp->setSpecular(0.2f, 0.2f, 0.2f);
	redLamp->setShininess(40);	

	Entity* baseA = new Entity("baseA", new Mesh("luxor/base_a.msh"), redPlastic);
	Entity* baseB = new Entity("baseB", new Mesh("luxor/base_b.msh"), redPlastic);
	Transform* baseT = new Transform("baseT");
	baseT->addNode(baseA);
	baseT->addNode(baseB);
	luxPos->addNode(baseT);

	Entity* haste1 = new Entity("haste1", new Mesh("luxor/haste1.msh"), redPlastic);
	Transform* haste1T = new Transform("haste1T");
	haste1T->translate(0.0f, 4.0f, 0.0f);
	haste1T->addNode(haste1);
	baseT->addNode(haste1T);
	
	Entity* haste2 = new Entity("haste2", new Mesh("luxor/haste2.msh"), redPlastic);
	Transform* haste2T = new Transform("haste2T");
	haste2T->translate(0.0f, 17.15f, 0.0f);
	haste2T->addNode(haste2);
	haste1T->addNode(haste2T);
	
	Entity* haste3A = new Entity("haste3A", new Mesh("luxor/haste3_a.msh"), redPlastic);
	Transform* haste3T = new Transform("haste3T");
	haste3T->translate(0.0f, 16.78f, 0.0f);
	haste3T->addNode(haste3A);
	
	Entity* haste3B = new Entity("haste3B", new Mesh("luxor/haste3_b.msh"), redPlastic);
	haste3T->addNode(haste3B);
	haste2T->addNode(haste3T);
	
	Entity* cupulaA = new Entity("cupula1", new Mesh("luxor/cupula_a.msh"), redPlastic);
	Entity* cupulaB = new Entity("cupula2", new Mesh("luxor/cupula_b.msh"), redPlastic);
	Transform* cupulaT = new Transform("cupulaT");
	cupulaT->translate(0.0f, 18.12f, 0.0f);
	cupulaT->addNode(cupulaA);
	cupulaT->addNode(cupulaB);
	haste3T->addNode(cupulaT);
	
	Entity* lampada = new Entity("bulb", new Mesh("luxor/lampada.msh"), redLamp);
	Transform* lampadaT = new Transform("bulbT");
	lampadaT->translate(0.0f, 8.4f, 9.0f);
	lampadaT->addNode(lampada);
	cupulaT->addNode(lampadaT);

	Light* bulb = new Light("bulbL", 0.0f, 0.0f, 0.0f, 1.0f);
	bulb->setAmbient(0.2f, 0.2f, 0.2f, 1.0f);
	bulb->setDiffuse(0.2f, 0.2f, 0.2f, 1.0f);
	bulb->setSpecular(0.2f, 0.2f, 0.2f, 1.0f);
	bulb->setSpotDir(0.0f, 0.0f, 1.0f);
	bulb->setSpotCutoff(60);
	bulb->setSpotExp(60);
	lampadaT->addNode(bulb);

	return luxPos;
}

Transform* buildBigLight()
{
	Transform* lightPos = new Transform("lightPos");
	lightPos->translate(0.0f, 7.25f, 0.0f);

	Material* lightMat = new Material(1.0f, 1.0f, 1.0f);
	lightMat->setSpecular(0.2f, 0.2f, 0.2f);
	lightMat->setShininess(60);

	Entity* lightObj = new Entity("lightObj", new Cube(1.0f, 0.5f, 5.0f), lightMat);
	lightPos->addNode(lightObj);

	Light* bigLight1 = new Light("bigLight3", 0.0f, 0.0f, 0.0f, 1.0f);
	bigLight1->setAmbient(0.1f, 0.1f, 0.0f, 1.0f);
	bigLight1->setDiffuse(0.1f, 0.1f, 0.1f, 1.0f);
	bigLight1->setSpecular(0.2f, 0.2f, 0.2f, 1.0f);
	bigLight1->setSpotDir(0.0f, -1.0f, 0.0f);
	bigLight1->setSpotCutoff(80);
	bigLight1->setSpotExp(30);
	
	Light* bigLight2 = new Light("bigLight2", 0.0f, 0.0f, 1.0f, 1.0f);
	bigLight2->setAmbient(0.1f, 0.0f, 0.1f, 1.0f);
	bigLight2->setDiffuse(0.1f, 0.1f, 0.1f, 1.0f);
	bigLight2->setSpecular(0.2f, 0.2f, 0.2f, 1.0f);
	bigLight2->setSpotDir(0.0f, -1.0f, 0.0f);
	bigLight2->setSpotCutoff(80);
	bigLight2->setSpotExp(30);
	
	Light* bigLight3 = new Light("bigLight3", 0.0f, 0.0f, -1.0f, 1.0f);
	bigLight3->setAmbient(0.0f, 0.1f, 0.1f, 1.0f);
	bigLight3->setDiffuse(0.1f, 0.1f, 0.1f, 1.0f);
	bigLight3->setSpecular(0.2f, 0.2f, 0.2f, 1.0f);
	bigLight3->setSpotDir(0.0f, -1.0f, 0.0f);
	bigLight3->setSpotCutoff(80);
	bigLight3->setSpotExp(30);
	
	lightPos->addNode(bigLight1);
	lightPos->addNode(bigLight2);
	lightPos->addNode(bigLight3);

	return lightPos;
}

Transform* buildTable(Material* m)
{
	Transform* tablePos = new Transform("tablePosT");
	tablePos->translate(6.0f, -7.5f, -13.0f);

	Entity* tableTop = new Entity("tableTop", new Cube(5.0f, 0.2f, 8.0f), m);
	Transform* tableTopTransform = new Transform("tableTopT");
	tableTopTransform->translate(0.0f, 2.5f, 0.0f);
	tableTopTransform->addNode(tableTop);
	tablePos->addNode(tableTopTransform);

	Entity* tableLeg = new Entity("tableLeg", new Cube(0.5f, 2.0f, 8.0f), m);
	Transform* tableLegTransform = new Transform("tableLegT");
	tableLegTransform->translate(0.0f, 1.4f, 0.0f);
	tableLegTransform->addNode(tableLeg);
	tablePos->addNode(tableLegTransform);

	Entity* tableFoot = new Entity("tableFoot", new Cube(2.0f, 0.5f, 0.5f), m);
	Transform* tableFootT1 = new Transform("tableFootT1");
	tableFootT1->translate(0.0f, 0.25f, 3.75f);
	tableFootT1->addNode(tableFoot);
	tablePos->addNode(tableFootT1);
	
	Transform* tableFootT2 = new Transform("tableFootT2");
	tableFootT2->translate(0.0f, 0.25f, -3.75f);
	tableFootT2->addNode(tableFoot);
	tablePos->rotate(15, 0.0f, 1.0f, 0.0f);
	tablePos->addNode(tableFootT2);

	return tablePos;
}

Transform* buildChair(Texture* t, Material* m) 
{
	char* tmpStr;

	Transform* chairCont = new Transform("chairCont");
	chairCont->translate(0.0f, -6.75f, 0.0f);
		
	Entity* chairLeg = new Entity("chairLeg", new Cube(0.2f, 1.5f, 0.2f), m);
	Transform** chairLegTs = new Transform*[4];
	
	for (int i=0; i<4; i++) {
		sprintf(tmpStr, "chairLegT%d", i+1);
		chairLegTs[i] = new Transform(tmpStr);
	}

	for (int i=0; i<4; i++)
		chairLegTs[i]->addNode(chairLeg);

	chairLegTs[0]->translate(0.75f, 0.0f, 0.75f);
	chairLegTs[1]->translate(-0.75f, 0.0f, 0.75f);
	chairLegTs[2]->translate(-0.75f, 0.0f, -0.75f);
	chairLegTs[3]->translate(0.75f, 0.0f, -0.75f);

	for (int i=0; i<4; i++)
		chairCont->addNode(chairLegTs[i]);

	Entity* chairSeat = new Entity("chairSeat", new Cube(2.0f, 0.1f, 2.0f), t);
	Transform* chairSeatT = new Transform("chairSeatT");
	chairSeatT->translate(0.0f, 0.8f, 0.0f);
	chairSeatT->addNode(chairSeat);
	chairCont->addNode(chairSeatT);

	Entity* chairBack = new Entity("chairBack", new Cube(2.0f, 1.0f, 0.1f), t);
	Transform* chairBackT = new Transform("chairBackT");
	chairBackT->translate(0.0f, 2.2f, -1.0f);		
	chairBackT->addNode(chairBack);	
	chairCont->addNode(chairBackT);

	Entity* chairSup = new Entity("chairSup", new Cube(0.2f, 1.5f, 0.2f), m);
	Transform* chairSupT1 = new Transform("chairSupT1");
	chairSupT1->translate(0.5f, 1.4f, -1.1f);		
	chairSupT1->addNode(chairSup);	
	chairCont->addNode(chairSupT1);
	Transform* chairSupT2 = new Transform("chairSupT2");
	chairSupT2->translate(-0.5f, 1.4f, -1.1f);		
	chairSupT2->addNode(chairSup);	
	chairCont->addNode(chairSupT2);

	Entity* chairTablePt1 = new Entity("chairTable1", new Cube(1.0f, 0.1f, 1.5f), t);
	Transform* chairTableT1 = new Transform("chairTableT1");
	chairTableT1->translate(1.0f, 1.5f, 0.5f);
	chairTableT1->addNode(chairTablePt1);
	chairCont->addNode(chairTableT1);
	
	Entity* chairTablePt2 = new Entity("chairTable2", new Cube(0.5f, 0.1f, 0.75f), t);
	Transform* chairTableT2 = new Transform("chairTableT2");
	chairTableT2->translate(1.25f, 1.5f, -0.625f);
	chairTableT2->addNode(chairTablePt2);
	chairCont->addNode(chairTableT2);

	Entity* tableSup = new Entity("tableSup", new Cube(0.75f, 0.2f, 0.2f), m);
	Transform* tableSupT = new Transform("tableSupT");
	tableSupT->translate(0.9f, 1.35f, -1.2f);
	tableSupT->addNode(tableSup);
	chairCont->addNode(tableSupT);

	Entity* tableSup2 = new Entity("tableSup2", new Cube(0.2f, 0.2f, 1.5f), m);
	Transform* tableSupT2 = new Transform("tableSupT2");
	tableSupT2->translate(1.15f, 1.35f, -0.3f);
	tableSupT2->addNode(tableSup2);
	chairCont->addNode(tableSupT2);	 

	return chairCont;
}

// Here starts the code to lamp animation

void setUpAnimations() {
}

Scene* pixarNotQuite(float w, float h) {
	Camera* theCamera = new Camera("mainC");
	theCamera->setZPlanes(1.0f, 100.0f);
	theCamera->setEye(0.0f, 0.0f, 20.0f);
	theCamera->setUp(0.0f, 1.0f, 0.0f);
	theCamera->setCenter(0.0f, 0.0f, 0.0f);
	theCamera->setAspectRatio(w/h);
	theCamera->setAngle(50.0f);
	theCamera->setManipulator(new VManipulator);
	theCamera->setZCenter(60.0f);

	Camera* auxCam = new Camera("lampCam");
	auxCam->setZPlanes(1.0f, 100.0f);
	auxCam->setEye(0.0f, 0.0f, 5.0f);
	auxCam->setUp(0.0f, 1.0f, 0.0f);
	auxCam->setCenter(0.0f, 0.0f, 100.0f);
	auxCam->setAspectRatio(w/h);
	auxCam->setAngle(50.0f);

	Transform* lamp = buildLamp();
	lamp->scale(0.2f, 0.2f, 0.2f);
	lamp->rotate(90, 0.0f, 1.0f, 0.0f);
	lamp->translate(-3.0f, -3.0f, -40.0f);

	Material* greyPlastic = new Material(0.3f, 0.3f, 0.3f);
	greyPlastic->setSpecular(0.5f, 0.5f, 0.5f);
	greyPlastic->setShininess(128);

	Cube* floorCube = new Cube(200.0, 1.0f, 200.0f);
	floorCube->setDiv(200);

	Entity* floor = new Entity("floor", floorCube, greyPlastic);
	Transform* floorT = new Transform("floorT");
	floorT->translate(-3.0f, -3.5f, -40.0f);
	floorT->addNode(floor);

	Material* redPlastic = new Material(0.5f, 0.f, 0.0f);
	redPlastic->setSpecular(0.5f, 0.5f, 0.5f);
	redPlastic->setShininess(128);
	
	Entity* box = new Entity("box", new Cube(3.0f, 30.0f, 3.0f), redPlastic);
	Transform* boxT = new Transform("boxT");
	boxT->translate(14.0f, 10.0f, -40.0f);
	boxT->addNode(box);	

	Light* l0 = new Light("mainL", 0.0f, 0.0f, 1.0f, 0.0f);
	l0->setAmbient(0.2f, 0.2f, 0.2f, 1.0f);
	l0->setDiffuse(0.2f, 0.2f, 0.2f, 1.0f);
	l0->setSpecular(0.2f, 0.2f, 0.2f, 1.0f);

	Scene* theScene = new Scene("mainScene");	
	theScene->addNode(theCamera);
	theScene->addNode(lamp);
	theScene->addNode(l0);
	theScene->addNode(floorT);
	theScene->addNode(boxT);
/*
	Entity* ball = new Entity("ball", new Sphere(1.0f), redPlastic);
	Transform* ballT = new Transform("ballT");
	ballT->translate(0.0f, 0.0f, 0.0f);
	ballT->addNode(ball);	
*/	
	Transform* bulbT = (Transform*) theScene->findNode("bulbT", "Transform");
	bulbT->addNode(auxCam);
//	bulbT->addNode(ballT);

	theScene->setClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	theScene->activateCamera("lampCam");	

/*	Animation* prepareJump = new Animation;
	Animation* jump = new Animation;	
	
	float pos1[3] = {0.0, 0.0, 0.0};
	float pos2[3] = {0.0, 30.0, 40.0};
	
	jump->addActionInFrame("baseT", pos1, 't', 0);
	jump->addActionInFrame("baseT", pos2, 't', 1);

	Engine::getInstance().addAnimationToScene(jump, "jump");
	Engine::getInstance().addAnimationToScene(prepareJump, "prepareJump");

	setUpAnimations();
*/
	return theScene;
}
