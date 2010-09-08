#include <stdio.h>
#include "matrix.h"
using namespace std;

void print(Matrix<int>& a) {
	for (int i=0; i<a.getR(); i++) {
		for (int j=0; j<a.getC(); j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("\n");
}

int main() {
	Matrix<int> a(2);
	//Matrix<int> b(3);	
	a[1][1]=5;

/*	for (int i=0; i<a.getR(); i++) {
		for (int j=0; j<a.getC(); j++)
			printf("%d ", a[i][j]);

		printf("\n");
	}

	a.set(2, 2,
		3, 2,
		3, 3);
	
	for (int i=0; i<a.getR(); i++) {
		for (int j=0; j<a.getC(); j++)
			printf("%d ", a[i][j]);

		printf("\n");
	} */

	//b.set(2, 1,
	//	1, 2);

	Matrix<int> b(a);

	b.set(2, 2,
		1, 2,
		4, 5);


	print(a);
	print(b);
	
	Matrix<int> c(a*b);

	a*=b;

	print(a);

	//printf("%d\n", b.det()); 
	//printf("%d\n", a.det());

	print(c);

	return 0;
}
