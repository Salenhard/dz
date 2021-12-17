#include <iostream>
#include "Matrix.h"
using namespace std;

int square(int a, int i, int j) {
	return a * a;
}

int main() {
	setlocale(0, "ru");
	Matrix A;
	Matrix B;
	B.init(3, 3);
	A.init(3, 3);
	B.fill_rand();
	A.fill_rand();
	cout << "Матрица A:" << endl << B.get_string() << endl;
	cout << "Матрица A:" << endl << A.get_string() << endl;
	A *= B;
	cout << "Матрица A:" << endl << A.get_string() << endl;
	A *= 2;
	cout << "Матрица A:" << endl << A.get_string() << endl;
	A.transposition();
	cout << "Транспонированная матрица A:" << endl << A.get_string() << endl;
	A.fill_number(25);
	cout << "Матрица A:" << endl << A.get_string() << endl;
	A.diagonal();
	cout << "Матрица A:" << endl << A.get_string() << endl;
	cout << "Определитель матрицы А: " << A.determinant() << endl;


	A.apply( square );
	cout << "Матрица A:" << endl << A.get_string() << endl;

	A.apply(  [](int a, int i, int j) -> int {return i * 10 + j; }  ) ;
	cout << "Матрица A:" << endl << A.get_string() << endl;
}