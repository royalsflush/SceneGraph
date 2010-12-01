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
#define DIST 10.0

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
static Matrix<float> rotateAroundPt(float angle, float* axis, float* pt);

static int lastX, lastY;
static double angleX, angleY;

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
	lastX = 0.0f;
	lastY = 0.0f;

	glutWarpPointer(0.0f, 0.0f);

	this->setCurrent(this);
}

void FPView::move(float x, float y, float z)
{
	if (eye[X]>=MAX_X && x>0) return; 
	if (eye[X]<=-MAX_X && x<0) return; 
		
	if (eye[Z]>=MAX_Z && z>0) return; 
	if (eye[Z]<=-MAX_Z && z<0) return; 

	Matrix<float> transl;
	Matrix<float> rot;

	float pt[3] = {-eye[X], -eye[Y], -eye[Z]};
	float yaxis[3] = {0.0f, 1.0f, 0.0f};

	transl.set(4, 4,
		1.0f, 0.0f, 0.0f, -x,
		0.0f, 1.0f ,0.0f, -y,
		0.0f, 0.0f ,1.0f, -z,
		0.0f, 0.0f, 0.0f, 1.0f);


	rot = rotateAroundPt(angleX, yaxis, pt);
	
	transl.t();
	transl=rot*transl;	
	rot = rotateAroundPt(-angleX, yaxis, pt);
	transl*=rot;
	
	this->inv=transl*(this->inv);	

	//for (int i=0; i<3; i++)
	//	pt[i]=-pt[i];


	//Changing the eye coordinates
	transl.set(4, 4,
		1.0f, 0.0f, 0.0f, x,
		0.0f, 1.0f ,0.0f, y,
		0.0f, 0.0f ,1.0f, z,
		0.0f, 0.0f, 0.0f, 1.0f);

	rot = rotateAroundPt(angleX, yaxis, pt);
	
	transl.t();
	transl=rot*transl;	
	rot = rotateAroundPt(-angleX, yaxis, pt);
	transl*=rot;	

	updateEye(transl);
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
	float pt[3] = {-eye[X], -eye[Y], -eye[Z]};
	float axis[3] = {x, y, z};
	Matrix<float> rot = rotateAroundPt(angle, axis, pt);
	this->inv=rot*(this->inv);
}

static Matrix<float> rotateAroundPt(float angle, float* axis, float* pt)
{
	Matrix<float> transl;
	Matrix<float> rot;
	
	transl.set(4, 4,
		1.0f, 0.0f, 0.0f, -pt[X],
		0.0f, 1.0f ,0.0f, -pt[Y],
		0.0f, 0.0f ,1.0f, -pt[Z],
		0.0f, 0.0f, 0.0f, 1.0f);
		
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glLoadIdentity();
	glRotatef(-angle, axis[X], axis[Y], axis[Z]);
	glGetFloatv(GL_MODELVIEW_MATRIX, rot);

	rot=transl*rot;

	transl.set(4, 4,
		1.0f, 0.0f, 0.0f, pt[X],
		0.0f, 1.0f ,0.0f, pt[Y],
		0.0f, 0.0f ,1.0f, pt[Z],
		0.0f, 0.0f, 0.0f, 1.0f);
	
	rot=rot*transl;		
	rot.t();

	glPopMatrix();
	return rot;
}

static void motion(int x, int y)
{
	bool changes = false;
	Matrix<float> tmp;
	int dx = x - lastX;
	int dy = y - lastY;

	if (abs(dx)>1) {
		double angle = atan((double)dx);
		
		FPView::getCurrent()->look(TORAD(angle)/DIST, 0.0f, 1.0f, 0.0f);
		angleX+=TORAD(angle)/DIST;

		lastX=x;
		changes=true;
	}

	if (abs(dy)>1) {
		double angle = atan((double)dy);
		angleY+=TORAD(angle)/DIST;

	//	FPView::getCurrent()->look(TORAD(angle)/DIST, 1.0f, 0.0f, 0.0f);

		lastY=y;
		changes=true;
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
