

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
	matrix operator+(matrix addthis);
	matrix operator+(float addthis);
	matrix operator-(matrix subthis);
	matrix operator-(float subthis);
	matrix operator*(matrix multhis);
	matrix operator*(float multhis);
private:
	int height;
	int width;
	float** mat;
};

