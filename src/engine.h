#ifndef ENGINE_H
#define ENGINE_H

#include <map>
#include <string>
using namespace std;

class Animation;
class Scene;

class Engine {
	static Engine* theEngine;
	Scene* curr;
	map<string, Animation*> getAnimation;

	Engine();

	public:
	static Engine& getInstance();

	void setScene(Scene*);
	void initRender();
	void renderCurrentScene();
	void changeScene();

	void handleResize(int w, int h);
	void handleKeyPress(unsigned char k, int x, int y);

	void addAnimation(Animation* a, char* name);
	Animation* getAnimationByName(char* name);
};

#endif /* ENGINE_H */
