#ifndef MATERIAL_H
#define MATERIAL_H

#include "property.h"
#include "appearance.h"

class Material : public Appearance {
	float amb[4];
	float dif[4];
	float spec[4];
	int shine;

	public:
	Material(float r, float g, float b);
	void setSpecular(float r, float g, float b);
	void setShininess(int sh);
	void load();
	void unload();
};

#endif /* MATERIAL_H */
