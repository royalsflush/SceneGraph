#include <stdio.h>

#include <map>
#include <vector>
#include <string>
#include <algorithm>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "animation.h"
#include "transform.h"
using namespace std;

Animation::Animation() : frameDuration(1.0), frames(0), active(false) { }

Animation::~Animation() {
	for (int i=0; i<actionsPerFrame.size(); i++)
		for (int j=0; j<actionsPerFrame[i].size(); j++)
			delete actionsPerFrame[i][j];
}

void Animation::setFrameDuration(float dur) {
	this->frameDuration = dur;
}

void Animation::addTransformForKey(Transform* t, const char* key) {
	if (getTransform.find(key) != getTransform.end())
		return;

	#ifdef _ANIM
		printf("Adding transform %s\n", key);
	#endif

	getTransform[key] = t;
}

void Animation::addActionInFrame(const char* transformName, float* vec, char type, int frameNum) {
	#ifdef _ANIM
		printf("Adding action to %s, frame %d\n", transformName, frameNum);
	#endif		

	Action* act = new Action;

	act->vector[0] = vec[0];
	act->vector[1] = vec[1];
	act->vector[2] = vec[2];

	act->type = type;
	act->t = getTransform[transformName];

	if (this->frames < frameNum+1) {
		this->actionsPerFrame.resize(frameNum+1);
		this->frames=frameNum+1;
	}


	this->actionsPerFrame[frameNum].push_back(act);
}

void Animation::startAnimation() {
	this->currFrame = 0;
	this->dtElapsed = 0; 	
	this->maxT = (this->frameDuration)*60;	
	this->active = true;

	#ifdef _ANIM
		printf("Started the animation, maxT = %f\n", this->maxT);
		printf("This animation has %d frames\n", this->frames);
	#endif

	if (this->frames==1)
		return;
}

void Animation::animate(int value) {
	int src = this->currFrame;
	
	for (int i=0; i<actionsPerFrame[src].size(); i++) {
		changeTransform(actionsPerFrame[src][i]);
	}	

	this->dtElapsed+=1;

	if (this->dtElapsed == this->maxT) {
		this->dtElapsed = 0;
		this->currFrame++;

		if (this->currFrame+1 == this->frames) {//reached final frame
			this->active = false;
			return;
		}
	}
}

void Animation::changeTransform(Action* act) {
	float interpol[3];
	float t = (float) dtElapsed/(float) maxT;
	int dst = this->currFrame+1;
	
	for (int i=0; i<actionsPerFrame[dst].size(); i++) {
		Action* nextAction = actionsPerFrame[dst][i];
		
		if (act->t != nextAction->t) continue;
		
		if (act->type == 't') {
			for (int j=0; j<3; j++)
				interpol[j]=(1-t)*act->vector[j]+t*nextAction->vector[j];
			
			act->t->identity();
			act->t->translate(interpol[0], interpol[1], interpol[2]);
			
		//	act->t->printMatrix();			
		}
		else if (act->type == 'r') {

		}

		return;
	}
}

bool Animation::isActive() 
{
	return this->active;
}
