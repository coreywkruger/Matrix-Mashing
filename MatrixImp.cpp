#include <iostream>
#include "Matrix.h"
#include <math.h>
using namespace std;

/////////////////////////////////////////////
//Constructor.
matrix::matrix(int w, int h) {
	height = h;
	width = w;
	int j;

	//Sets the height and width.
	mat = new float* [width];
	for (j = 0; j < width; j++) {
		mat[j] = new float[height];
	}
}

/////////////////////////////////////////////
//Sets the value of the entry specified.
void matrix::setVal(int col, int row, float val) {
	mat[col][row] = val;
}

/////////////////////////////////////////////
//Returns the value of the entry specified.
float matrix::getVal(int col, int row) {
	return mat[col][row];
}

/////////////////////////////////////////////
//Returns the determinant of the matrix object as a float.
float matrix::getDet() {

	//This function moves along the top row of the matrix, and finds the cofactor matrix of each entry there.
	//These cofactor matrices are recursively condensed down, until a 2x2 matrix emerges. When the 2x2 matrix
	//is found, its determinant is returned.
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

/////////////////////////////////////////////
//Returns the cofactor matrix of the entry specified, and returns it.
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

/////////////////////////////////////////////
//Returns a copy of the matrix in its inverse form.
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

/////////////////////////////////////////////
//Returns a copy of the matrix in transpose form.
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

/////////////////////////////////////////////
//Returns the determinant of a 2x2 matrix (if provided).
float matrix::Det2x2() {
		return (mat[0][0]*mat[1][1] - mat[1][0]*mat[0][1]);
}

/////////////////////////////////////////////
//Return height of the matrix.
int matrix::getH() {
	return height;
}

/////////////////////////////////////////////
//Return width of the matrix.
int matrix::getW() {
	return width;
}

/////////////////////////////////////////////
//For printing the matrix, line-by-line.
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

/////////////////////////////////////////////
//Overload + for adding the matrix object to another matrix object.
matrix matrix::operator+(matrix addthis) {
	if (getW() == addthis.getW() && getH() == addthis.getH()) {
		matrix newMat(getW(), getH());
		int i, j;
		for (i = 0; i < getW(); i++) {
			for (j = 0; j < getH(); j++) {
				newMat.setVal(i, j, mat[i][j] + addthis.getVal(i, j));
			}
		}
		return newMat;
	} else {
		cerr << "Matrices not eligible for addition: not of equal dimension." << endl;
	}
}

/////////////////////////////////////////////
//Overload + for a float to all entries in the matrix object.
matrix matrix::operator+(float addthis) {
	matrix newMat(getW(), getH());
	int i, j;
	for (i = 0; i < getW(); i++) {
		for (j = 0; j < getH(); j++) {
			newMat.setVal(i, j, mat[i][j] + addthis);
		}
	}
	return newMat;
}


/////////////////////////////////////////////
//Overload - for subtracting one matrix from another.
matrix matrix::operator-(matrix addthis) {
	if (getW() == addthis.getW() && getH() == addthis.getH()) {
		matrix newMat(getW(), getH());
		int i, j;
		for (i = 0; i < getW(); i++) {
			for (j = 0; j < getH(); j++) {
				newMat.setVal(i, j, mat[i][j] - addthis.getVal(i, j));
			}
		}
		return newMat;
	} else {
		cerr << "Matrices not eligible for subtraction: not of equal dimension." << endl;
	}
}

/////////////////////////////////////////////
//Overload * for multiplying all entries in the matrix object by a single float.
matrix matrix::operator*(float multhis) {
	matrix newMat(getW(), getH());
	int i, j;
	for (i = 0; i < getW(); i++) {
		for (j = 0; j < getH(); j++) {
			newMat.setVal(i, j, mat[i][j]*multhis);
		}
	}
	return newMat;
}

/////////////////////////////////////////////
//Overload - for subtracting a float from the matrix object.
matrix matrix::operator-(float addthis) {
	matrix newMat(getW(), getH());
	int i, j;
	for (i = 0; i < getW(); i++) {
		for (j = 0; j < getH(); j++) {
			newMat.setVal(i, j, mat[i][j] - addthis);
		}
	}
	return newMat;
}



/////////////////////////////////////////////
//Overload * for multiplying two matrix objects.
matrix matrix::operator*(matrix multhis) {
	if (getH() == multhis.getW()) {
		matrix newMat(getH(), multhis.getW());
		int i, j;
		for (i = 0; i < newMat.getW(); i++) {
			for (j = 0; j < newMat.getH(); j++) {
				float val = 0;
				int k;
				for (k = 0; k < getW(); k++) {
					val += mat[k][j]*multhis.getVal(i, k);
				}
				newMat.setVal(i, j, val);
			}
		}
		return newMat;
	} else {
		cerr << "Matrices not eligible for multiplication: not of correct dimension." << endl;
	}
}
