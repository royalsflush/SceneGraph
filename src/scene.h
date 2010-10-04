#ifndef SG_SCENE_H
#define SG_SCENE_H

#include "group.h"

class Scene : public Group {
	public:
	int setCamera();
	int setLights();
	void render();	
};

#endif /* SG_SCENE_H */
