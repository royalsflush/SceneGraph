#include <stdlib.h>
#include <stdio.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "switch.h"

Switch* Switch::curr = NULL;

Switch::Switch()
{
	this->lightMask=0xffffffff;
	glutKeyboardFunc(handleKeys);
	setCurr(this);
}

Switch* Switch::getCurr()
{
	return Switch::curr;
}

void Switch::setCurr(Switch* s)
{
	Switch::curr = s;
}

void Switch::handleKeys(unsigned char k, int x, int y)
{
	if (k==27) exit(0);
	if (k>='0' && k<='7') {
		#ifdef _DBG
			printf("Pressed %c key\n", k);			
		#endif

		if (Switch::getCurr()->isOn(k-'0')) 
			Switch::getCurr()->turnOff(k-'0');
		else
			Switch::getCurr()->turnOn(k-'0');
	
		#ifdef _DBG
			for (int i=0; i<8; i++) {
				if (Switch::getCurr()->isOn(i))
					printf("1");
				else 
					printf("0");
			}

			printf("\n");

		#endif

		glutPostRedisplay();
	}
}

void Switch::turnOn(int index)
{
	this->lightMask|=(1<<index);
}

void Switch::turnOff(int index)
{
	this->lightMask&=(0xffffffff-(1<<index));
}

bool Switch::isOn(int index)
{
	if (this->lightMask & (1<<index)) {
		return true;
	}

	return false;
}
