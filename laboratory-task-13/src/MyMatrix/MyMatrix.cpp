#include "MyMatrix.hpp"


/*===========================================================================
=============================== Конструкторы ================================
===========================================================================*/

MyMatrix::MyMatrix() {
	matrixPtr = nullptr;
	rows = 0;
	columns = 0;
}

MyMatrix::MyMatrix(int32_t sqSize) {
	rows = sqSize;
	columns = sqSize;
	matrixPtr = new int32_t * [sqSize];
	for (int32_t i = 0; i < sqSize; ++i) {
		matrixPtr[i] = new int32_t[sqSize];
	}

	for (int32_t i = 0; i < sqSize; ++i) {
		for (int32_t j = 0; j < sqSize; ++j)
		matrixPtr[i][j] = 0;
	}
}

MyMatrix::MyMatrix(int32_t row, int32_t column) {
	rows = row;
	columns = column;
	matrixPtr = new int32_t * [row];
	for (int32_t i = 0; i < row; ++i) {
		matrixPtr[i] = new int32_t[column];
	}

	for (int32_t i = 0; i < row; ++i) {
		for (int32_t j = 0; j < column; ++j)
			matrixPtr[i][j] = 0;
	}
}

MyMatrix::MyMatrix(const MyMatrix& rhs) {
	rows = rhs.rows;
	columns = rhs.columns;
	if (rows > 0 && columns > 0) {

		matrixPtr = new int32_t * [rows];
		for (int32_t i = 0; i < rows; ++i) {
			matrixPtr[i] = new int32_t[columns];
		}

		for (int32_t i = 0; i < rows; ++i) {
			for (int32_t j = 0; j < columns; ++j) {
				matrixPtr[i][j] = rhs.matrixPtr[i][j];
			}
		}
	}
	else {
		matrixPtr = nullptr;
	}
}

/*===========================================================================
============================= Деструктор ====================================
===========================================================================*/

MyMatrix::~MyMatrix() {
	for (int32_t i = 0; i < rows; ++i)
	{
		delete[] matrixPtr[i];
	}
	delete[] matrixPtr;
}

/*===========================================================================
============================ Вывод матрицы ==================================
===========================================================================*/

void MyMatrix::print() {
	for (int32_t i = 0; i < rows; ++i)
	{
		for (int32_t j = 0; j < columns; ++j)
		{
			std::cout << std::setw(8) << matrixPtr[i][j];
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

/*===========================================================================
=========================== Оператор присваивания ===========================
===========================================================================*/

MyMatrix MyMatrix::operator=(const MyMatrix& rhs) {
	    if (this == &rhs){
        return *this;
    }
	if (rows > 0)
	{
		for (int32_t i = 0; i < rows; i++) {
			delete[] matrixPtr[i];
		}
	}

	if (columns > 0)
	{
		delete[] matrixPtr;
	}

	rows = rhs.rows;
	columns = rhs.columns;

	matrixPtr = new int32_t* [rows];
	for (int32_t i = 0; i < rows; i++) {
		matrixPtr[i] =new int32_t[columns];
	}

	for (int32_t i = 0; i < rows; i++) {
		for (int32_t j = 0; j < columns; j++){
			matrixPtr[i][j] = rhs.matrixPtr[i][j];
		}
	}
	return *this;
}

/*===========================================================================
================================= Геттеры ===================================
===========================================================================*/

int32_t MyMatrix::getElement(int32_t coord) {
	if (coord <= rows && coord <= columns) {
		return matrixPtr[coord][coord];
	}
	else throw std::runtime_error("coordinates are out of bounds!\n");
}

int32_t MyMatrix::getElement(int32_t coordRow, int32_t coordColumn) {
	if (coordRow <= rows && coordColumn <= columns) {
		return matrixPtr[coordRow][coordColumn];
	}
	else throw std::runtime_error("coordinates are out of bounds!\n");
}

int32_t MyMatrix::getRows(){
	return this->rows;
}
int32_t MyMatrix::getColumns(){
	return this->columns;
}


/*===========================================================================
================================= Сеттеры ===================================
===========================================================================*/

void MyMatrix::setElement(int32_t item, int32_t coord) {
	if (coord <= rows && coord <= columns) {
		matrixPtr[coord][coord] = item;
	} else throw std::runtime_error("coordinates are out of bounds!\n");
}

void MyMatrix::setElement(int32_t item, int32_t coordRow, int32_t coordColumn) {
	if (coordRow <= rows && coordColumn <= columns) {
		matrixPtr[coordRow][coordColumn] = item;
	}
	else throw std::runtime_error("coordinates are out of bounds!\n");
}

void MyMatrix::setRows(int32_t rhs){
	if (rhs < 0){
		throw std::invalid_argument("Rows must be more than zero!");
	}
 this->rows = rhs;
}
void MyMatrix::setColumns(int32_t rhs){
	if (rhs < 0){
		throw std::invalid_argument("Rows must be more than zero!");
	}
 this->columns = rhs;
}

/*===========================================================================
============================ Бинарные операторы =============================
===========================================================================*/

MyMatrix MyMatrix::operator*(const int32_t rhs)
{
	for (int32_t i = 0; i < rows; ++i) {
		for (int32_t j = 0; j < columns; ++j) {
			matrixPtr[i][j] *= rhs;
		}
	}
	return *this;
}

MyMatrix MyMatrix::operator/(const int32_t rhs)
{
	for (int32_t i = 0; i < rows; ++i) {
		for (int32_t j = 0; j < columns; ++j) {
			matrixPtr[i][j] /= rhs;
		}
	}
	return *this;
}

MyMatrix MyMatrix::operator+(const MyMatrix& rhs)
{
	if (rows != rhs.rows || columns != rhs.columns) {
		throw std::runtime_error("operation possible only with equal sizes!\n");
	}
	for (int32_t i = 0; i < rows; ++i) {
		for (int32_t j = 0; j < columns; ++j) {
			matrixPtr[i][j] = matrixPtr[i][j] + rhs.matrixPtr[i][j];
		}
	}
	return *this;
}

MyMatrix MyMatrix::operator-(const MyMatrix& rhs)
{
	if (rows != rhs.rows || columns != rhs.columns) {
		throw std::runtime_error("operation possible only with equal sizes!\n");
	}
	for (int32_t i = 0; i < rows; ++i) {
		for (int32_t j = 0; j < columns; ++j) {
			matrixPtr[i][j] = matrixPtr[i][j] - rhs.matrixPtr[i][j];
		}
	}
	return *this;
}

MyMatrix MyMatrix::operator*(const MyMatrix& rhs)
{
	if (columns != rhs.rows) {
		throw std::runtime_error("Incorrect parameters!(amount of Columns of first must be equal to amount of Rows of second)\n");
	}
	MyMatrix result(rows, rhs.columns);
	for (int32_t i = 0; i < rows; ++i) {
		for (int32_t j = 0; j < rhs.columns; ++j) {
			for (int32_t k = 0; k < columns; ++k) {
				result.matrixPtr[i][j] = result.matrixPtr[i][j] + matrixPtr[i][k] * rhs.matrixPtr[k][j];
			}
		}
	}
	return result;
}

/*===========================================================================
===================== Составные операторы присваивания ======================
===========================================================================*/

MyMatrix MyMatrix::operator/=(const int32_t rhs)
{
	for (int32_t i = 0; i < rows; ++i) {
		for (int32_t j = 0; j < columns; ++j) {
			matrixPtr[i][j] /= rhs;
		}
	}
	return *this;
}

MyMatrix MyMatrix::operator+=(const MyMatrix& rhs)
{
	if (rows != rhs.rows || columns != rhs.columns) {
		throw std::runtime_error("operation possible only with equal sizes!\n");
	}
	for (int32_t i = 0; i < rows; ++i) {
		for (int32_t j = 0; j < columns; ++j) {
			matrixPtr[i][j] = matrixPtr[i][j] + rhs.matrixPtr[i][j];
		}
	}
	return *this;
}

MyMatrix MyMatrix::operator-=(const MyMatrix& rhs)
{
	if (rows != rhs.rows || columns != rhs.columns) {
		throw std::runtime_error("operation possible only with equal sizes!\n");
	}
	for (int32_t i = 0; i < rows; ++i) {
		for (int32_t j = 0; j < columns; ++j) {
			matrixPtr[i][j] = matrixPtr[i][j] - rhs.matrixPtr[i][j];
		}
	}
	return *this;
}

MyMatrix MyMatrix::operator*=(const MyMatrix& rhs)
{
	if (columns != rhs.rows) {
		throw std::runtime_error("Incorrect parameters!(amount of Columns of first must be equal to amount of Rows of second)\n");
	}
	MyMatrix result(rows, rhs.columns);
	for (int32_t i = 0; i < rows; ++i) {
		for (int32_t j = 0; j < rhs.columns; ++j) {
			for (int32_t k = 0; k < columns; ++k) {
				result.matrixPtr[i][j] = result.matrixPtr[i][j] + matrixPtr[i][k] * rhs.matrixPtr[k][j];
			}
		}
	}
	return result;
}

MyMatrix& operator*=(MyMatrix& a,const int32_t rhs)
{
	for (int32_t i = 0; i < a.rows; ++i) {
		for (int32_t j = 0; j < a.columns; ++j) {
			a.matrixPtr[i][j] *= rhs;
		}
	}
	return a;
}

MyMatrix operator * (const int32_t rhs, MyMatrix& a)
{
	for (int32_t i = 0; i < a.rows; ++i) {
		for (int32_t j = 0; j < a.columns; ++j) {
			a.matrixPtr[i][j] *= rhs;
		}
	}

	return a;
}

MyMatrix operator * (MyMatrix& a, const int32_t rhs)
{
	for (int32_t i = 0; i < a.rows; ++i) {
		for (int32_t j = 0; j < a.columns; ++j) {
			a.matrixPtr[i][j] *= rhs;
		}
	}

	return a;
}

/*===========================================================================
=========================== операторы сравнения =============================
===========================================================================*/

bool MyMatrix::operator==(const MyMatrix& rhs)
{
	if (rows == rhs.rows && columns == rhs.columns) {
		bool isEqual = true;
		for (int32_t i = 0; i < rows; ++i) {
			for (int32_t j = 0; j < columns; ++i) {
				if (matrixPtr[i][j] != rhs.matrixPtr[i][j]) {
					isEqual = false;
					return isEqual;
				}
			}
		}
		return isEqual;
	}
	else throw std::runtime_error("Only can operate with same size Matrixs!");
}

bool MyMatrix::operator!=(const MyMatrix& rhs)
{
	return !(*this == rhs);
}

/*===========================================================================
==================== Перегрузка операторов ввода/вывода =====================
===========================================================================*/

std::ostream& operator<<(std::ostream& out, const MyMatrix& rhs)
{
	for (int32_t i = 0; i < rhs.rows; ++i)
	{
		for (int32_t j = 0; j < rhs.columns; ++j)
		{
			out << std::setw(8) << rhs.matrixPtr[i][j];
		}
		out << '\n';
	}
	out << '\n';
	return out;
}

std::istream& operator>>(std::istream& in, MyMatrix& rhs)
{
	bool hadRows = true;
	bool hadColumns = true;
	if (rhs.rows == 0) {
		std::cout << "Enter amount of rows: ";
		std::cin >> rhs.rows;
		hadRows = false;
		hadColumns = false;
	}
	if (rhs.columns == 0) {
		std::cout << "Enter amount of columns: ";
		std::cin >> rhs.columns;
		hadColumns = false;
	}
	if (hadRows && hadColumns) {
		std::cout << "Enter elements for [ " << rhs.rows << " ] [ " << rhs.columns <<" ] matrix: \n";
		for (int32_t i = 0; i < rhs.rows; ++i)
		{
			for (int32_t j = 0; j < rhs.columns; ++j)
			{
				in >> rhs.matrixPtr[i][j];
			}
		}
	}
	else {
		rhs.matrixPtr = new int32_t * [rhs.rows];
		std::cout << "Enter elements for [ " << rhs.rows << " ] [ " << rhs.columns << " ] matrix: \n";
		for (int32_t i = 0; i < rhs.rows; ++i) {
			rhs.matrixPtr[i] = new int32_t[rhs.columns];
		}

		for (int32_t i = 0; i < rhs.rows; ++i) {
			for (int32_t j = 0; j < rhs.columns; ++j)
				in >> rhs.matrixPtr[i][j];
		}
	}
	return in;
}
