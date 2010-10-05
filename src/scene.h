#ifndef SG_SCENE_H
#define SG_SCENE_H

#include "group.h"

class Camera;

class Scene : public Group {
	Camera* cam;

	public:
	int setupCamera();
	int setupLights();
	void render();	
	
	void changeAspect(float nasp);
	void setCamera(Camera* c);
};

#endif /* SG_SCENE_H */
