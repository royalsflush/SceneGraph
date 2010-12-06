#include <stdio.h>
#include <math.h>

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
#include "scene.h"
using namespace std;

#define PI 3.141592
#define TORAD(theta) (theta*PI)/180.0 
#define TODEG(theta) 180.0*theta/PI

Animation::Animation() : animationScene(NULL), frameDuration(1.0), frames(0), active(false) { }

Animation::~Animation() {
	for (int i=0; i<actionsPerFrame.size(); i++)
		for (int j=0; j<actionsPerFrame[i].size(); j++)
			delete actionsPerFrame[i][j];
}

void Animation::setFrameDuration(float dur) {
	this->frameDuration = dur;
}

void Animation::addActionInFrame(const char* transformName, float* vec, char type, int frameNum) {
	#ifdef _ANIM
		printf("Adding action to %s, frame %d\n", transformName, frameNum);
	#endif		

	if (!this->animationScene) //you should put the scene first
		return;

	Transform* t = (Transform*) this->animationScene->findNode(transformName, "Transform");

	Action* act = new Action;

	act->vector[0] = vec[0];
	act->vector[1] = vec[1];
	act->vector[2] = vec[2];

	act->type = type;
	act->t = t;

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

	if (this->frames==1) {
		this->active = false;
		return;
	}
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
				interpol[j]=(1-t*t)*act->vector[j]+t*t*nextAction->vector[j];
			
			act->t->identity();
			act->t->translate(interpol[0], interpol[1], interpol[2]);
			
		//	act->t->printMatrix();			
		}
		else if (act->type == 'r') {	
			float alpha = 0;
			float q0[4];
			float q1[4];
			float angle0=0, angle1=0;

			for (int j=0; j<4; j++) {
				angle0+=act->vector[j]*act->vector[j];
				angle1+=nextAction->vector[j]*nextAction->vector[j];
			}	

			angle0=sqrt(angle0); angle1=sqrt(angle1);
	
			q0[0] = cos(TORAD(angle0/2.0));
			q1[0] = cos(TORAD(angle1/2.0));

			for (int j=1; j<4; j++) {
				q0[j]=(act->vector[j-1])*sin(TORAD(angle0/2.0));
				q1[j]=(nextAction->vector[j-1])*sin(TORAD(angle1/2.0));
			
				if (angle0) q0[j]/=angle0;
				if (angle1) q1[j]/=angle1;
			}	
			
			//dot product
			for (int j=0; j<4; j++)
				alpha+=q0[j]*q1[j];
		
			alpha = acos(alpha);
	
			for (int j=0; j<4; j++)
				interpol[j]= (sin((1-t)*alpha)*q0[j]+sin(t*alpha)*q1[j])/sin(alpha);

			float angle = acos(interpol[0]);
			angle*=2;

			for (int j=1; j<4; j++) {
				if (angle) interpol[j] = interpol[j]/sin(angle/2.0);
				else interpol[j]=0.0;
			}

			angle = TODEG(angle);

			act->t->identity();
			act->t->rotate(angle, interpol[1], interpol[2], interpol[3]);
		}

		return;
	}
}

bool Animation::isActive() 
{
	return this->active;
}

void Animation::setScene(Scene* s)
{
	this->animationScene = s;
}
