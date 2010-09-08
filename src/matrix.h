#ifndef MATRIX_H
#define MATRIX_H

#include <assert.h>
#include <stdarg.h>

#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x))

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
	Matrix(const Matrix<T>&);//ok

	void sparse(); //ok
	bool isSparse(); //ok
	void identity(); //ok
	void set(int r, int c, ...); //check floating points
	void t(); //ok
	const Matrix invert();
	T det(); //not working
	Matrix LUdecomp();

	//Dimension getters

	int getR() const; //ok
	int getC() const; //ok

	Matrix& operator=(const Matrix&); //ok

	// Unary minus
	const Matrix operator-(); //ok
	
	// Binary operators

	const Matrix operator*(const Matrix&); //ok
	const Matrix operator+(const Matrix&); //ok
	const Matrix operator-(const Matrix&); //ok

	// Compond operators: seem okay

	Matrix& operator*=(const T); //ok
	Matrix& operator+=(const Matrix&); //ok
	Matrix& operator-=(const Matrix&); //ok
	Matrix& operator*=(const Matrix&); //ok	

	//Utility overloads	

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

//copy constructor
	template <typename T>
Matrix<T>::Matrix(const Matrix<T>& a)
{
	this->r = a.getR();
	this->c = a.getC();

	this->mat = new T[(this->r)*(this->c)];

	for (int i=0; i<(this->r); i++) {
		for (int j=0; j<(this->c); j++)
			this->mat[(this->c)*i+j]=a.getPos(i,j);
	} 
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
	if (this->r!=r || this->c!=c) {
		delete[] this->mat;
		this->r=r; this->c=c;	
		this->mat = new T[r*c];
	}

	va_list args;
	va_start(args, c);


	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++)
			this->mat[i*c+j]=va_arg(args,T);
	}

	va_end(args);
}

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

//---------- Operations on the matrix ------//

	template <typename T>
void Matrix<T>::t()
{
	Matrix<T> trans(this->c, this->r);

	for (int i=0; i<this->r; i++) {
		for (int j=0; j<this->c; j++) 
			trans[j][i] = this->mat[i*(this->c)+j];
	}

	*this=trans;
}

	template <typename T>
T Matrix<T>::det()
{
	assert(this->r==this->c);

	bool upper=true, lower=true;

	//checks if is triangular (or diagonal)
	//Det for triangulars is O(n^2) (finding the determinant itself is O(n), but
	//checking if the matrix is triangular is O(n^2))
	for (int i=0; i<this->r; i++) {
		for (int j=0; j<this->c; j++) {
			if (i==j) continue;
			if (j>i && this->mat[i*(this->c)+j]!=0) lower=false;
			else if (i<j && this->mat[i*(this->c)+j]!=0) upper=false;
		}
	}

	if (upper || lower) {
		T d=1;

		for (int i=0; i<this->r; i++)
			d*=this->mat[i*(this->c)+i];

		return d;
	}

	//If the matrix is not triangular, use other methods

	//Laplace extension for n<=4 - O(n!)
	switch(this->r) {
		case 1:
			return this->mat[0];
		case 2:
		case 3: 
		case 4:
			{
				T d; Matrix<T> tmp(this->r-1);
				d=0;			

				for (int k=0; k<(this->r); k++) {
					for (int i=1; i<(this->r); i++) {
						for (int j=0, sm=0; j<(this->r) && sm<(this->r-1); j++) {	
							if (j==k) continue;
							tmp[i-1][sm++]=this->mat[i*(this->c)+j];
						}
					}				

					if (k%2==0)
						d+= this->mat[k]*tmp.det();	
					else
						d-= this->mat[k]*tmp.det();	

				}

				return d;
			}	
		default:
			break;	
	}

	//LUdecomp and find det for upper matrix - O(n^3)
	return (this->LUdecomp()).det();
}

	template <typename T>
const Matrix<T> Matrix<T>::invert()
{
	assert(this->det());
}

	template <typename T>
Matrix<T> Matrix<T>::LUdecomp()
{
	assert(this->r==this->c);

	Matrix<T> low(this->r);
	Matrix<T> up(this->r);

	//for (int i=0; i<			
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

	template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& a) 
{
	if (&a == this) return *this;

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

//-------- Unary Minus --------------//
	
	template <typename T>
const Matrix<T> Matrix<T>::operator-()
{
	Matrix<T> res(*this);
	res*=-1;

	return res;
}

//-------- Binary operators ---------//

	template <typename T>
const Matrix<T> Matrix<T>::operator*(const Matrix<T>& a) 
{
	assert(this->c == a.getR());

	Matrix<T> res(this->r, a.getC());

	for (int i=0; i<this->r; i++) {
		for (int j=0; j<a.getC(); j++) {		
			for (int k=0; k<this->c; k++) {
				res[i][j]+=this->mat[i*(this->c)+k]*a.getPos(k, j);
			}
		}
	}

	return res;
}

	template <typename T>
const Matrix<T> Matrix<T>::operator+(const Matrix<T>& a)
{
	assert((this->c==a.getC()) && (this->r==a.getR()));
	
	Matrix<T> res(*this);
	res+=a;

	return res;
}

	template <typename T>
const Matrix<T> Matrix<T>::operator-(const Matrix<T>& a)
{
	assert((this->c==a.getC()) && (this->r==a.getR()));
	
	Matrix<T> res(*this);
	res-=a;

	return res;
}

//------- Compound operators --------//

	template <typename T>
Matrix<T>& Matrix<T>::operator*=(const T a) 
{ 
	for (int i=0; i<this->r; i++) {
		for (int j=0; j<this->c; j++)
			this->mat[i*(this->c)+j]*=a;
	}

	return *this;
}

	template <typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& a) 
{	
	*this = ((*this)*a);

	return *this;
}

	template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& a) 
{
	assert((this->r==a.getR()) && (this->c==a.getC())); 

	for (int i=0; i<this->r; i++) {
		for (int j=0; j<this->c; j++)
			this->mat[i*(this->c)+j]+=a.getPos(i,j);
	}

	return *this;
}

	template <typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& a) 
{
	assert((this->r==a.getR()) && (this->c==a.getC())); 
	
	for (int i=0; i<this->r; i++) {
		for (int j=0; j<this->c; j++)
			this->mat[i*(this->c)+j]-=a.getPos(i,j);
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
