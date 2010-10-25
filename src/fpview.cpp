#include "fpview.h"

FPView* FPView::curr = 0;

void FPView::SetCurrent(FPView* fp)
{
	FPView::curr = fp;	
}

FPView::FPView()
{
	VManipulator::Identity();
	glutMouseFunc(this->mouse);
	glutMotionFunc(motion);
	this->SetCurrent(this);
}

static void motion(int x, int y)
{
	
}
