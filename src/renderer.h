#ifndef RENDERER_H
#define RENDERER_H

//Renderer is an abstract class

class Renderer {
	public:
	virtual void init() = 0;
	virtual void renderSphere() = 0;
	virtual void renderCube() = 0;
	virtual void renderMesh() = 0;
};

#endif /* RENDERER_H */
