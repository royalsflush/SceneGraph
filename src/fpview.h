#ifndef FPVIEW_H
#define FPVIEW_H

#include "camMan.h"

class FPView : public VManipulator
{
	static FPView* curr;

	public:
		FPView();
		void load();
		void loadInv();		
}

#endif /* FPSVIEW_H */
