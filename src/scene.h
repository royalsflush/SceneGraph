#ifndef SG_SCENE_H
#define SG_SCENE_H

#include <map>
#include <string>
using namespace std;

#include "group.h"

//Environ is included instead of
// just forward declared because
// it has the enum to fogModes
#include "environ.h"

class Camera;
class Animation;

class Scene : public Group {
	map<string, Animation*> animations;
	Camera* currCam;
	Environ* env;

	public:
	Scene(const char* name);

	int setupCamera();
	int setupLights();
	void render();	

	/* Camera-related functions */
	
	void changeAspect(float nasp);
	void activateCamera(const char* name); 

	/* Animation-related functions */

	void addAnimation(Animation* a, const char* name);
	Animation* getAnimationByName(const char* name);
	void runAnimations();

	/* Environ wrappers */
	
	void setClearColor(float r, float g, float b, float a);
	void setGlobalLight(float r, float g, float b, float a);
	void twoSidedLighting(bool b);
	void localViewer(bool b);
	void enableFog(bool b);
	void setFogColor(float r, float g, float b, float a);
	void setFogLim(float start, float end);
	void setFogDensity(float d);
	void setFogMode(fogModes f);
};

#endif /* SG_SCENE_H */
