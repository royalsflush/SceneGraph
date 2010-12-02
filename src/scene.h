#ifndef SG_SCENE_H
#define SG_SCENE_H

#include <map>
#include <string>
using namespace std;

#include "group.h"
#include "environ.h"

class Camera;

class Scene : public Group {
	map<string, Camera*> cameraOpts;
	Camera* currCam;
	Environ* env;

	public:
	Scene(const char* name);

	int setupCamera();
	int setupLights();
	void render();	
	
	void changeAspect(float nasp);
	void addCamera(Camera* c, const char* name);
	void activateCamera(const char* name); 
	
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
