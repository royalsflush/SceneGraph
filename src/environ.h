#ifndef ENVIRON_H
#define ENVIRON_H

enum fogModes {
	linear, exp, exp2
};

class Environ {
	public:
	void setGlobalLight(float r, float g, float b, float a);
	void twoSidedLighting(bool b);
	void localViewer(bool b);
	void setupEnviron();
	void setClearColor(float r, float b, float b, float a);
	void enableFog(bool b);
	void setFogColor(float r, float g, float b, float a);
	void setFogDensity(float d);
	void setFogLim(float start, float end);
	void setFogMode(fogModes f);
};

#endif
