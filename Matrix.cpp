//============================================================================
// Name        : Matrix.cpp
// Author      : Corey Kruger
// Description : Matrix class illustration
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;

class matrix {
public:
	matrix(int, int);
	void setVal(int, int, float);
	float getVal(int, int);
	float getDet();
	float Det2x2();
	matrix cofactorM(int col, int row);
	matrix inverse();
	matrix transpose();
	int getH();
	int getW();
	void print();
private:
	int height;
	int width;
	float** mat;
};

matrix::matrix(int w, int h) {
	height = h;
	width = w;
	int j;
	mat = new float* [width];
	for (j = 0; j < width; j++) {
		mat[j] = new float[height];
	}
}

void matrix::setVal(int col, int row, float val) {
	mat[col][row] = val;
}

float matrix::getVal(int col, int row) {
	return mat[col][row];
}

float matrix::getDet() {
	if (getH() == 2 && getW() == 2)
		return Det2x2();
	else if (getH() > 2 && getW() > 2 && getH() == getW());
		float value = 0;
		int i;
		for (i = 0; i < getW(); i++) {
			matrix temp = cofactorM(i, 0);
			value += pow(-1, i) * (temp.getDet()) * mat[i][0];
		}
		return value;

}

matrix matrix::cofactorM(int col, int row) {
	matrix newMat(getW() - 1, getH() - 1);
	int i, j;
	int k = 0;
	for (i = 0; i < getW(); i++) {
		if (i == col) {
			i++;
		}
		if (i >= getW()) {
			break;
		}
		int l = 0;
		for (j = 0; j < getH(); j++) {
			if (j == row) {
				j++;
			}
			if (j >= getH()) {
				break;
			}
			newMat.setVal(k, l, mat[i][j]);
			l++;
		}
		k++;

	}
	return newMat;
}

matrix matrix::inverse() {
	matrix inversion(getW(), getH());
	int i, j;
	for (i = 0; i < getW(); i++) {
		for (j = 0; j < getH(); j++) {
			matrix temp = cofactorM(i, j);
			float num = ( (pow(-1, i + j)) * temp.getDet() ) / getDet();
			inversion.setVal(j, i, num);
		}
	}
	return inversion;
}

matrix matrix::transpose() {
	matrix transM(getW(), getH());
	int i, j;
	for (i = 0; i < getW(); i++) {
		for (j = 0; j < getH(); j++) {
			transM.setVal(i, j, mat[j][i]);
		}
	}
	return transM;
}

float matrix::Det2x2() {
		return (mat[0][0]*mat[1][1] - mat[1][0]*mat[0][1]);
}

int matrix::getH() {
	return height;
}

int matrix::getW() {
	return width;
}

void matrix::print() {
	cout << "---------------" << endl;
	int i;
	for (i = 0; i < getH(); i++) {
		int j;
		for (j = 0; j < getW(); j++) {
			cout << getVal(j, i) << " | ";
		}
		cout << endl;
	}
}

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

	cout << "First matrix:" << endl;
	myMatrix.print();
	matrix cof = myMatrix.cofactorM(1, 2);

	cout  << endl;
	cout << "Determinant of first matrix:" << endl;
	cout << myMatrix.getDet() << endl;

	cout << endl;
	cout << "Cofactor matrix of first entry in first matrix:" << endl;
	cof.print();

	cout << endl;
	matrix newm = myMatrix.inverse();
	cout << "Inverse of first matrix:" << endl;
	newm.print();

	cout << endl;
	cout << "Transpose of first matrix:" << endl;
	matrix trans = myMatrix.transpose();
	trans.print();
	return 0;
}
