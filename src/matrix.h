#ifndef MATRIX_H
#define MATRIX_H

#include <assert.h>
#include <stdarg.h>

template <typename T>

class Matrix {
	int r, c;
	T* mat;
	T getPos(int i, int j) const;
	
	public:
	Matrix(); //ok
	~Matrix(); //ok
	Matrix(int n); //ok
	Matrix(int r, int c); //ok

	void sparse(); //ok
	bool isSparse(); //ok
	void identity(); //ok
	void set(int r, int c, ...); //check floating points
	void transpose();
	Matrix getInverse();
	T determinant();
	Matrix LUdecomp();

	int getR() const; //ok
	int getC() const; //ok

	Matrix& operator*(Matrix&); //esta dando merda
	Matrix& operator=(const Matrix&); //ok
//	bool operator=(const T[]);
	Matrix operator+(Matrix&); //idem aqui
//	Matrix operator*(const T); //nao testei
	Matrix& operator*=(const T);
//	Matrix& operator*=(Matrix&);
	operator T*();
	T* operator[](const int); //ok
};



//------------- Constructors -------------//

//Creates a 4x4 identity matrix
template <typename T>
Matrix<T>::Matrix() : r(4), c(4) 
{	
	this->mat = new T[16]; 
	this->identity();
}

//Creates an n x n identity matrix
template <typename T>
Matrix<T>::Matrix(int n) : r(n), c(n)
{
	assert(n>0);

	this->mat = new T[n*n];
	this->identity();
}

//Creates an r x c sparse matrix
template <typename T>
Matrix<T>::Matrix(int r, int c) : r(r), c(c)
{
	assert((r>0) && (c>0));

	this->mat = new T[r*c];
	this->sparse();
}

//-------------- Destructor ---------------//

template <typename T>
Matrix<T>::~Matrix()
{
	delete[] this->mat;
}

//------------- Utility functions ----------//

//Fills the current matrix with 0's
template <typename T>
void Matrix<T>::sparse() 
{
	for (int i=0; i<this->r; i++) {
		for (int j=0; j<this->c; j++) {
			this->mat[i*(this->c)+j]=0;
		}
	}
}

//Check if the matrix is sparse
template <typename T>
bool Matrix<T>::isSparse()
{
	bool sparse=true;

	for (int i=0; i<this->r; i++) {
		for (int j=0; j<this->c; j++) {
			if (this->mat[i*(this->c)+j]!=0) {
				sparse=false;
				break;
			}
		}
	}

	return sparse;
}

//If the matrix is square, transforms it into the identity matrix
//otherwise, does nothing.
template <typename T>
void Matrix<T>::identity()
{
	assert(this->c==this->r);

	for (int i=0; i<this->r; i++) {
		for (int j=0; j<this->c; j++) {
			this->mat[i*(this->c) + j]= (i==j)? 1 : 0;
		}
	}
}

//------------- Set functions -----------//

template <typename T>
void Matrix<T>::set(int r, int c, ...)
{
	delete[] this->mat;
	this->r=r; this->c=c;	

	va_list args;
	va_start(args, c);

	this->mat = new T[r*c];

	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++)
			this->mat[i*c+j]=va_arg(args,T);
	}

	va_end(args);
}

template <>
void Matrix<float>::set(int r, int c, ...)
{
	delete[] this->mat;
	this->r=r; this->c=c;	

	va_list args;
	va_start(args, c);

	this->mat = new float[r*c];

	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++)
			this->mat[i*c+j]= (float) va_arg(args, double);
	}

	va_end(args);
}

template <>
void Matrix<short>::set(int r, int c, ...)
{
	delete[] this->mat;
	this->r=r; this->c=c;	

	va_list args;
	va_start(args, c);

	this->mat = new short[r*c];

	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++)
			this->mat[i*c+j]= (short) va_arg(args, int);
	}

	va_end(args);
}

//---------- Operations on the matrix ------//

template <typename T>
void Matrix<T>::transpose()
{

}

template <typename T>
T Matrix<T>::determinant()
{

}

template <typename T>
Matrix<T> Matrix<T>::getInverse()
{
	
}

//------------------- Getters ------------------//
template <typename T>
int Matrix<T>::getR() const
{
	return this->r;
}

template <typename T>
int Matrix<T>::getC() const
{
	return this->c;
}

template <typename T>
T Matrix<T>::getPos(int i, int j) const
{
	return this->mat[i*(this->c)+j];
}

//-------------- Operator Overloads -----------//

//---------------- Type T casts ----------------//

//Casts matrix to an array of size r*c. This vector is
//dependent to the matrix class, so the user should copy
//it before destroying the matrix it is attached to (if
//he/she wishes to maintain the array 
template <typename T>
Matrix<T>::operator T*()
{
	return this->mat;
}

//-------------- Assignment ------------------//

//Assigns a to your matrix. Returns false if
//a was sparse, else returns true;
template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& a) 
{ 
	delete this->mat;
	this->r = a.getR();
	this->c = a.getC();

	this->mat = new T[a.getC()*a.getR()];

	for (int i=0; i<a.getR(); i++) {
		for (int j=0; j<a.getC(); j++)
			this->mat[i*(this->c)+j]= a.getPos(i,j);
	}

	return *this;
}

//Assigns a const array to your matrix. Be sure
//the array is HAS AT LEAST r*c size. Otherwise,
//you'll get a segfault 
/*template <typename T>
bool Matrix<T>::operator=(const T a[])
{
	for (int i=0; i<(this->r); i++) {
		for (int j=0; j<(this->c); j++)
			this->mat[i*(this->c)+j]=a[i*(this->c)+j];
	}

	return this->isSparse();
} */

//-------- Matrix - Matrix operations ---------//
template <typename T>
Matrix<T>& Matrix<T>::operator*(Matrix<T>& a) 
{
	assert(this->c == a.getR());
	
	Matrix<T> res(this->r, a.getC());

	for (int i=0; i<this->r; i++) {
		for (int j=0; j<a.getC(); j++) {		
			for (int k=0; k<this->c; k++) {
				res[i][j]+=this->mat[i*(this->c)+k]*a[k][j];
			}
		}
	}

	return res;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T>& a)
{
	assert((this->c==a.getC()) && (this->r==a.getR()));
	Matrix res(this->c, this->r);

	for (int i=0; i<this->c; i++) {
		for (int j=0; j<this->r; j++)
			res[i][j] = a[i][j]+this->mat[i*(this->c)+j];
	}
}


//---------- Matrix - number operations -------//
template <typename T>
Matrix<T>& Matrix<T>::operator*=(const T a) 
{ 
	for (int i=0; i<this->c; i++) {
		for (int j=0; j<this->r; j++)
			this->mat[i*(this->c)+j]*=a;
	}

	return *this;
}


//----------- Array subscript overload ---------//
template <typename T>
T* Matrix<T>::operator[](const int i)
{
	return &(this->mat[i*this->c]);
}


#endif /* MATRIX_H */
