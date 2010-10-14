#ifndef SG_SCENE_H
#define SG_SCENE_H

#include "group.h"
#include "environ.h"

class Camera;

class Scene : public Group {
	Camera* cam;
	Environ* env;

	public:
	Scene();

	int setupCamera();
	int setupLights();
	void render();	
	
	void changeAspect(float nasp);
	void setCamera(Camera* c);
	
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
