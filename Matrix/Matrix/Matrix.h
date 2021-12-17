#pragma once

using
func3param = int(*)(int, int, int);



class Matrix
{
private:
	int rows;
	int cols;
	int** matrix;
public:
	void init(int new_rows, int new_cols);		//создает матрицу размером rowsxcols
	Matrix& operator += (const Matrix& b);				// сложение
	Matrix& operator *= (const Matrix& b);				// умножение
	Matrix& operator *= (int number);				// умножение
	Matrix& operator -= (const Matrix& b);				// вычитание
	Matrix& operator = (const Matrix& b);		// копирование
	void fill_rand();							// заполнение рандомными числами
	void fill_number(int number);				// заполнение указаным числом
	void diagonal();							// обнуление всех элементов кроме тех что лежат на диогонали
	std::string get_string();					// возращает матрицу в виде строки 
	void transposition();					//транспонирование квадратной матрицы
	int get_cols() const;						// возращает cols матрицы
	int get_rows() const;						// возращает rows матрицы
	int determinant();							// Возращает определитель
	Matrix();									// Конструктор по умолчанию
	~Matrix();									// деконструктор
	Matrix(int new_rows, int new_cols);			// конструктор с параметрами
	Matrix(const Matrix& other);				// конструктор копиравнием

	void apply(func3param func);
};

