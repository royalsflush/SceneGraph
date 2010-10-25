#ifndef TEXTURE_H
#define TEXTURE_H

#include "appearance.h"

enum texcoord {
	S=0, T, R, Q
};

class Texture : public Appearance {
	float planes[4][4];
	int coordPlane[4];	
	static int nextId;
	unsigned int id;

	public:
	Texture(char* filename);
	void load();
	void unload();
	void setPlane(texcoord t, float a, float b, float c, float d, bool eyeCoord);

};

#endif /* TEXTURE_H */
