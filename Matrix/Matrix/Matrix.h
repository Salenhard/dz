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
	void init(int new_rows, int new_cols);		//������� ������� �������� rowsxcols
	Matrix& operator += (const Matrix& b);				// ��������
	Matrix& operator *= (const Matrix& b);				// ���������
	Matrix& operator *= (int number);				// ���������
	Matrix& operator -= (const Matrix& b);				// ���������
	Matrix& operator = (const Matrix& b);		// �����������
	void fill_rand();							// ���������� ���������� �������
	void fill_number(int number);				// ���������� �������� ������
	void diagonal();							// ��������� ���� ��������� ����� ��� ��� ����� �� ���������
	std::string get_string();					// ��������� ������� � ���� ������ 
	void transposition();					//���������������� ���������� �������
	int get_cols() const;						// ��������� cols �������
	int get_rows() const;						// ��������� rows �������
	int determinant();							// ��������� ������������
	Matrix();									// ����������� �� ���������
	~Matrix();									// �������������
	Matrix(int new_rows, int new_cols);			// ����������� � �����������
	Matrix(const Matrix& other);				// ����������� �����������

	void apply(func3param func);
};

