#ifndef FPVIEW_H
#define FPVIEW_H

#include "camMan.h"
#include "matrix.h"

class FPView : public CamMan
{
	static FPView* curr;
	Matrix<float> inv;
	Matrix<float> mat;
	float eye[3];

	public:
		FPView();
		static void setCurrent(FPView* fp);
		static FPView* getCurrent();	
		
		void move(float x, float y, float z);
		void look(float angle, float x, float y, float z);

		void load();
		void loadInv();		
		void setEyeCoords(float x, float y, float z);
		void updateEye(float* m);
		
		//Essa funcao nao esta pronta, ainda
		void setCameraTransf(float* m); 

		void setZCenter(float zcent) { }
};

#endif /* FPSVIEW_H */
