//============================================================================
// Name        : Matrix.cpp
// Author      : Corey Kruger
// Description : Matrix class illustration
//============================================================================

#include <iostream>
#include "Matrix.h"
using namespace std;


int main() {

	matrix myMatrix(3, 3);
	myMatrix.setVal(0, 0, 1);
	myMatrix.setVal(0, 1, 2);
	myMatrix.setVal(0, 2, -1);

	myMatrix.setVal(1, 0, 3);
	myMatrix.setVal(1, 1, 4);
	myMatrix.setVal(1, 2, 5);

	myMatrix.setVal(2, 0, 8);
	myMatrix.setVal(2, 1, 6);
	myMatrix.setVal(2, 2, 7);

	cout << "First matrix ('matrix1'):" << endl;
	myMatrix.print();
	matrix cof = myMatrix.cofactorM(0, 0);

	cout  << endl;
	cout << "Determinant of first matrix:" << endl;
	cout << myMatrix.getDet() << endl;

	cout << endl;
	cout << "Cofactor matrix of the top-left entry in first matrix:" << endl;
	cof.print();

	cout << endl;
	matrix newm = myMatrix.inverse();
	cout << "Inverse of first matrix:" << endl;
	newm.print();

	cout << endl;
	cout << "Transpose of first matrix:" << endl;
	matrix trans = myMatrix.transpose();
	trans.print();

	cout << endl;
	cout << "Operator '+' overloaded. Added 'matrix1 + matrix1'." << endl;
	matrix adder = myMatrix + myMatrix;
	adder.print();

	cout << endl;
	cout << "Operator '+' overloaded for adding 'matrix + float'. Added 'matrix1 + 10'." << endl;
	matrix adderFloat = myMatrix + 10;
	adderFloat.print();
	cout << endl;

	cout << endl;
	cout << "Operator '-' overloaded. Subtracted '(previous matrix) - matrix1'." << endl;
	matrix subM =  adderFloat - myMatrix;
	subM.print();

	cout << endl;
	cout << "Operator '-' overloaded. Subtracted '(all 10s matrix) - 1'." << endl;
	matrix subFloat =  subM - 1;
	subFloat.print();

	cout << endl;
	cout << "Operator '*' overloaded. Multiplied 'matrix1 * (all 10s matrix)'." << endl;
	matrix mulM = myMatrix*subM;
	mulM.print();


	matrix am1(2, 3);
	am1.setVal(0, 0, 1);
	am1.setVal(0, 1, 2);
	am1.setVal(0, 2, 3);
	am1.setVal(1, 0, 4);
	am1.setVal(1, 1, 5);
	am1.setVal(1, 2, 6);


	matrix am2(3, 2);
	am2.setVal(0, 0, 1);
	am2.setVal(0, 1, 2);
	am2.setVal(1, 0, 3);
	am2.setVal(1, 1, 4);
	am2.setVal(2, 0, 5);
	am2.setVal(2, 1, 6);


	cout << endl << endl;
	cout << "Two Matrices of eligible dimensions are multiplied to form a new matrix:" << endl;
	cout << "(Note: width of first must equal height of second or vis-versa)" << endl;
	cout << "\nFirst 2x3 matrix:" << endl;
	am1.print();
	cout << endl << "second 3x2 matrix:" << endl;
	am2.print();
	cout << endl << "Now multiplied together:" << endl;
	matrix multy = am1*am2;
	multy.print();
	return 0;
}
