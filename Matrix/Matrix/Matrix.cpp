#include <string>
#include "Matrix.h"
#include <iostream>

void Matrix::init(int new_rows, int new_cols)          // ������������� ��������
{
		if (this->matrix != nullptr)
		{
			for (int i = 0; i < rows; i++)
			{
				delete this->matrix[i];
			}
			delete[] this->matrix;
		}
		this->rows = new_rows;
		this->cols = new_cols;
		this->matrix = new int* [this->rows];
		for (int i = 0; i < this->rows; i++)
			this->matrix[i] = new int[this->cols];
}

void Matrix::fill_rand() {													// ����������� ������� ���������� �������
	for (int i = 0; i < this->rows; i++)
	{
		for (int k = 0; k < this->cols; k++)
		{
			this->matrix[i][k] = rand() % 100;
		}
	}
}

std::string Matrix::get_string()                                                   // ����� ������� � �������
{
	std::string str;
	for (int i = 0; i < this->rows; i++)
	{
		for (int k = 0; k < this->cols; k++)
		{
			str = str + std::to_string(this->matrix[i][k]) + " ";
		}
		str = str + "\n";
	}
	return str;
}

Matrix::~Matrix()										// �������������
{
	for (int i = 0; i < rows; i++)
	{
		delete[] this->matrix[i];
	}
	delete[] this->matrix;

}

void Matrix::fill_number(int number)				// ��������� ������� ������(number)
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int k = 0; k < this->cols; k++)
		{
			this->matrix[i][k] = number;
		}
	}
}

void Matrix::diagonal()							// ��������� ������� ������� ����� ���������
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int k = 0; k < this->cols; k++)
		{
			if (i != k)
				this->matrix[i][k] = 0;
		}
	}
}

Matrix& Matrix::operator *= (int number)							// �������� ������� �� �����
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int k = 0; k < this->cols; k++)
		{
			this->matrix[i][k] = this->matrix[i][k] * number;
		}
	}
	return *this;
}

Matrix& Matrix::operator += (const Matrix& b)							// ���������� �������
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int k = 0; k < this->cols; k++)
		{
			this->matrix[i][k] = this->matrix[i][k] + b.matrix[i][k];
		}
	}
	return *this;
}

Matrix& Matrix::operator -= (const Matrix& b)			// �������� ������� �� �������
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int k = 0; k < this->cols; k++)
		{
			this->matrix[i][k] = this->matrix[i][k] - b.matrix[i][k];
		}
	}
	return *this;
}

Matrix& Matrix::operator *= (const Matrix& b)  // ��������� �� �������
{
	Matrix c;
	c.init(this->rows,b.cols);
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < b.cols; j++)
		{
			c.matrix[i][j] = 0;
			for (int k = 0; k < b.rows; k++)
			{
				c.matrix[i][j] += this->matrix[i][k] * b.matrix[k][j];
			}
		}
	}
	*this = c;
	return *this;
}

Matrix& Matrix::operator = (const Matrix& b) 		// �����������
{
	for (int i = 0; i < this->rows; i++) // �������� �������
	{
		delete this->matrix[i];
	}
	delete[] this->matrix;
	this->rows = b.rows;
	this->cols = b.cols;
	this->matrix = new int* [this->rows];
	for (int i = 0; i < this->rows; i++)
		this->matrix[i] = new int[this->cols];
	for (int i = 0; i < this->rows; i++)
	{
		for (int k = 0; k < this->rows; k++)
		{
			this->matrix[i][k] = b.matrix[i][k];
		}
	}
	return *this;
}

void Matrix::transposition() // ���������������� ���������� �������
{
	int t;
	for (int i = 0; i < this->rows; i++)
	{
		for (int k = i; k < this->cols; k++)
		{
			t = this->matrix[i][k];
			this->matrix[i][k] = this->matrix[k][i];
			this->matrix[k][i] = t;
		}
	}
}

int Matrix::get_cols() const					// ��������� cols �������
{
	return this->cols;
}
int Matrix::get_rows() const					// ��������� rows �������
{
	return this->rows;
}

int Matrix::determinant()								// ��������� ������������
{
	Matrix c{this->rows,this->cols};
	for (int i = 0; i < this->rows; i++)		
	{
		for (int k = 0; k < this->rows; k++)
		{
		c.matrix[i][k] = this->matrix[i][k];		
		}
	}
	int tmp;
	for (int k = 0; k < this->rows - 1; k++){
		for (int i = k + 1; i < this->cols; i++){
			tmp = -c.matrix[i][k] / c.matrix[k][k];
			for (int j = 0; j < this->rows; j++) {
				c.matrix[i][j] += c.matrix[k][j] * tmp;
			}
		}
	}
	int d = 1;
	for (int i = 0; i < this->rows; i++){
		d *= c.matrix[i][i];
	}
	return d;
}

Matrix::Matrix()									// ����������� �� ���������
{
	init(1, 1);
}
Matrix::Matrix(int new_rows, int new_cols)			// ����������� � �����������
{
	init(new_rows, new_cols);
}
Matrix::Matrix(const Matrix& other)
{
	*this = other;
}

void Matrix::apply(func3param func)
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int k = 0; k < this->cols; k++)
		{
			this->matrix[i][k] = func(this->matrix[i][k], i, k);
		}
	}
}
 