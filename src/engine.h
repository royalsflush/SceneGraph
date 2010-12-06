#ifndef ENGINE_H
#define ENGINE_H

#include <map>
#include <string>
using namespace std;

class Scene;
class Animation;

class Engine {
	static Engine* theEngine;
	Scene* curr;

	Engine();

	public:
	static Engine& getInstance();

	void setScene(Scene*);
	void initRender();
	void renderCurrentScene();
	void changeScene();

	void handleResize(int w, int h);
	void handleKeyPress(unsigned char k, int x, int y);

	void addAnimationToScene(Animation* a, const char* name);
	Animation* getAnimationByName(const char* name);

	void changeCameraTo(const char* name);
};

#endif /* ENGINE_H */
