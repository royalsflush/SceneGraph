#ifndef ENGINE_H
#define ENGINE_H

class Renderer;
class Scene;

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
};

#endif /* ENGINE_H */
