#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "fpview.h"
#include "matrix.h"

#define SPEED 0.7
#define DIST 200.0

#define MAX_X 8.5
#define MAX_Z 18.5

#define PI 3.1459
#define TORAD(x) (x*180.0f/PI)

enum {
	X=0, Y, Z
};

FPView* FPView::curr = 0;

static void motion(int x, int y);
static void keyboard(unsigned char k, int x, int y);

static int lastX, lastY;

void FPView::setCurrent(FPView* fp)
{
	FPView::curr = fp;	
}

FPView* FPView::getCurrent()
{
	return FPView::curr;
}

FPView::FPView()
{
	glutPassiveMotionFunc(motion);
	glutKeyboardFunc(keyboard);	

	this->setCurrent(this);
}

void FPView::move(float x, float y, float z)
{
	if (eye[X]>=MAX_X && x>0) return; 
	if (eye[X]<=-MAX_X && x<0) return; 
		
	if (eye[Z]>=MAX_Z && z>0) return; 
	if (eye[Z]<=-MAX_Z && z<0) return; 

	Matrix<float> tmp(this->inv);
	this->inv.set(4, 4,
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f ,0.0f, 0.0f,
		0.0f, 0.0f ,1.0f, 0.0f,
		-x, -y, -z, 1.0f);

	this->inv*=tmp;	

	//Changing the eye coordinates
	tmp.set(4, 4,
		1.0f, 0.0f, 0.0f, x,
		0.0f, 1.0f ,0.0f, y,
		0.0f, 0.0f ,1.0f, z,
		0.0f, 0.0f, 0.0f, 1.0f);

	updateEye(tmp);
}

void FPView::updateEye(float* m)
{
	Matrix<float> tmp;
	tmp.setFromArray(4, 4, m);

	Matrix<float> eyeTmp(4, 1);

	for (int i=0; i<3; i++)
		eyeTmp[i][0]=eye[i];
	
	eyeTmp[3][0]=1.0f;

	#ifdef _FPVIEW
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++) 
				printf("%f ", tmp[i][j]);
			printf("\n");
		}
		printf("\n");
	#endif

	eyeTmp=tmp*eyeTmp;
	
	#ifdef _FPVIEW
		printf("r, c from eyeTmp: %d, %d\n", eyeTmp.getR(), eyeTmp.getC());

		for (int i=0; i<4; i++) {
			for (int j=0; j<1; j++) 
				printf("%f ", eyeTmp[i][j]);
			printf("\n");
		}
		printf("\n");
	#endif

	for (int i=0; i<3; i++)
		eye[i]=eyeTmp[i][0];

	#ifdef _FPVIEW
		printf("new eye: %f, %f, %f\n", eye[X], eye[Y], eye[Z]);
	#endif
}

void FPView::look(float angle, float x, float y, float z)
{
	Matrix<float> transl;
	Matrix<float> rot;
	
	transl.set(4, 4,
		1.0f, 0.0f, 0.0f, -eye[X],
		0.0f, 1.0f ,0.0f, -eye[Y],
		0.0f, 0.0f ,1.0f, -eye[Z],
		0.0f, 0.0f, 0.0f, 1.0f);
		
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glLoadIdentity();
	glRotatef(-angle, x, y, z);
	glGetFloatv(GL_MODELVIEW_MATRIX, rot);
	rot.t();	

	rot=transl*rot;

	transl.set(4, 4,
		1.0f, 0.0f, 0.0f, eye[X],
		0.0f, 1.0f ,0.0f, eye[Y],
		0.0f, 0.0f ,1.0f, eye[Z],
		0.0f, 0.0f, 0.0f, 1.0f);
	
	rot=rot*transl;		
	rot.t();

	//Rot agora e a inversa da matrix de rotacao em torno do olho
	this->inv=rot*this->inv;
	
	glPopMatrix();

}

static void motion(int x, int y)
{
	int dx = x - lastX;
	int  dy = y - lastY;
	bool changes = false;
	Matrix<float> tmp;
	
	#ifdef _FPVIEW
		printf("x: %d,  y: %d\n", x, y);
	#endif

	if (abs(dx)>1) {
		#ifdef _FPVIEW
			printf("dx: %d ", dx);
		#endif

		double angle = atan((double)dx/DIST);
		
		#ifdef _FPVIEW
			printf("angle: %lf\n", TORAD(angle));
		#endif
		

		FPView::getCurrent()->look(TORAD(angle), 0.0f, 1.0f, 0.0f);
		
		lastX=x;
		changes=true;
	}

	if (dy>1) {
		//changes=true;
	}

	if (changes) glutPostRedisplay();
}

static void keyboard(unsigned char k, int x, int y)
{
	bool changes=false;

	switch (k) {
		case 27:
			exit(0);
		case 'a':
		case 'A':
			FPView::getCurrent()->move(-SPEED, 0.0f, 0.0f);
			changes=true;
			break;
		case 'w':
		case 'W':
			FPView::getCurrent()->move(0.0f, 0.0f, -SPEED);	
			changes=true;
			break;
		case 'S':
		case 's':
			FPView::getCurrent()->move(0.0f, 0.0f, SPEED);
			changes=true;
			break;
		case 'd':
		case 'D':
			FPView::getCurrent()->move(SPEED, 0.0f, 0.0f);
			changes=true;
			break;
	}

	if (changes) glutPostRedisplay();
}

void FPView::load() { }

void FPView::loadInv()
{
	glMultMatrixf(this->inv);
}

void FPView::setEyeCoords(float x, float y, float z)
{
	#ifdef _FPVIEW
		printf("Setting up eye coordinates\n");
	#endif

	this->eye[X]=x;
	this->eye[Y]=y;
	this->eye[Z]=z;
	
	#ifdef _FPVIEW
		printf("Eye is: %f, %f, %f\n", eye[X], eye[Y], eye[Z]);
	#endif	
}

void FPView::setCameraTransf(float* m) { }

#undef PI
#undef TORAD(x)
