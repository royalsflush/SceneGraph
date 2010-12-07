#ifndef SHAPE_H
#define SHAPE_H

#include "renderer.h"

class Shape {
	protected:
	Renderer* currRend;

	public: 
	Shape() : currRend(NULL) { }
	virtual void draw() = 0;
	void setRenderer(Renderer* r) { this->currRend=r; }
	void setRenderMode(rend_modes newMode) {
		if (!this->currRend) return;
		this->currRend->setMode(newMode);
	}
};

#endif /* SHAPE_H */
