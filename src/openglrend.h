#ifndef OPENGL_RENDERER_H
#define OPENGL_RENDERER_H

#include "renderer.h"

class OpenGLRenderer : public Renderer {
	public:
	void init();
	void renderSphere();
	void renderCube();
	void renderMesh();
};

#endif /* OPENGL_RENDERER_H */
