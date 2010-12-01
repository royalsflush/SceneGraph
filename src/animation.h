#ifndef ANIMATION_H
#define ANIMATION_H

#include <map>
#include <vector>
#include <string>
using namespace std;

// I'm going to reference the
// Transform class in the map
class Transform;
class Animation;

class Action {
	char type; //r for rotation, s for scaling, t for translation
	
	//That's the vector associated with the action
	//For rotation, I'm using the module as the angle
	float vector[3]; 

	//Transform associated with this action
	Transform* t;

	public:
	friend class Animation;
};

class Animation {
	/* This part deals with general information about the
	animation */

	//That's actually the duration for space between frames
	float frameDuration;

	//A little key-value philosophy here
	map<string, Transform*> getTransform;

	//Counter for the frames
	int frames;

	//Animation is active
	bool active;

	//The actions executed in each frame
	vector< vector<Action*> > actionsPerFrame;

	/* This part controls the animation that's running */
	
	//This is the x0 of the animation
	int currFrame;
	
	// t = (dtElapsed/maxT);
	int dtElapsed;
	int maxT;

	//Private methods
	void changeTransform(Action* act);

	public:
	Animation();
	~Animation();

	bool isActive();

	void setFrameDuration(float dur);
	void addTransformForKey(Transform* t, char* key);

	//FrameNum starts with 0
	void addActionInFrame(char* transformName, float* vec, char type, int frameNum);

	void startAnimation();
	void animate(int value);
	void clearState();	
};

#endif /* ANIMATION_H */
