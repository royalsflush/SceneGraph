#include <stdio.h>
#include "matrix.h"
using namespace std;

int main() {
	Matrix<int> a(3);
	//Matrix<int> b(3);	
	a[1][2]=5;

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

	Matrix<int> b(3);
	b.set(3, 3,
		-2, 2, -3,
		-1, 1, 3,
		2, 0, -1);

	a.set(2, 2, 
		-1, 3,
		2, -1);

	printf("%d\n", b.det()); 
	printf("%d\n", a.det());

	for (int i=0; i<b.getR(); i++) {
		for (int j=0; j<b.getC(); j++)
			printf("%d ", b[i][j]);

		printf("\n");
	}

	for (int i=0; i<a.getR(); i++) {
		for (int j=0; j<a.getC(); j++)
			printf("%d ", a[i][j]);

		printf("\n");
	}

	return 0;
}
