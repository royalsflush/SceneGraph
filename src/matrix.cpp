#include <assert.h>
#include <stdarg.h>

#include "matrix.h"
using namespace std;

	template <>
void Matrix<float>::set(int r, int c, ...)
{
	if (this->r!=r || this->c!=c) {
		delete[] this->mat;
		this->r=r; this->c=c;	
		this->mat = new float[r*c];
	}	

	va_list args;
	va_start(args, c);

	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++)
			this->mat[i*c+j]= (float) va_arg(args, double);
	}

	va_end(args);
}


	template <>
void Matrix<short>::set(int r, int c, ...)
{
	if (this->r!=r || this->c!=c) {
		delete[] this->mat;
		this->r=r; this->c=c;	
		this->mat = new short[r*c];
	}

	va_list args;
	va_start(args, c);

	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++)
			this->mat[i*c+j]= (short) va_arg(args, int);
	}

	va_end(args);
}
