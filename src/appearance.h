#ifndef APPEARANCE_H
#define APPEARANCE_H

#include "property.h"

class Appearance : public Property {
	public:
	virtual void load() = 0;
	virtual void unload() = 0;
};

#endif /* APPEARANCE_H */
