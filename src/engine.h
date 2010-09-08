#ifndef ENGINE_H
#define ENGINE_H

class Renderer;
class Scene;

class Engine {
	static Engine* theEngine;
	
	Renderer* theRenderer;
	Scene* curr;

	Engine();
	~Engine();

	public:
	static Engine& getInstance();

	void setRenderer(Renderer*);
	void setScene(Scene*);
	void initRender();
	void renderCurrentScene();
	//void changeScene();
	//svoid handleKeyPress(unsigned char k, int x, int y);
};

#endif /* ENGINE_H */
