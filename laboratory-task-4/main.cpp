/*
Индивидуальное задание № 4

Тема: МАТРИЦЫ

При решении следующих задач использовать динамический массив. При
необходимости заполнения массива предусмотреть два способа: ввод с клавиатуры и
заполнение с помощью датчика случайных чисел. В последнем случае перед заполнением
массива ввести границы интервала, которому должны принадлежать элементы массива.
Вывести результаты расчетов. Если по каким-либо причинам решение задачи
невозможно, вывести соответствующее сообщение.
Вариант 13
В целочисленной прямоугольной матрице A(mxn) найти:
- номер первой из строк, содержащей хотя бы один нуль;
- координаты всех ее седловых точек, если таковые имеются
*/

#include <iostream>
#include <exception>
#include <ctime>
void initParams(size_t& rows, size_t& columns)
{
	std::cout << "\nEnter amount of rows:";
	std::cin >> rows;
	if (rows < 1 || static_cast<size_t>(rows) != rows)
		throw std::exception("Invalid parametre of matrix!");
	std::cout << "\nEnter amount of columns:";
	std::cin >> columns;
	if (columns < 1|| static_cast<size_t>(columns) != columns)
		throw std::exception("Invalid parametre of matrix!");
	std::cout << "\nrows: " << rows;
	std::cout << "\ncolumns: " << columns;
}
void matrixInit(int32_t**& matrix, size_t& columns, size_t& rows)
{
	initParams(rows, columns);
	matrix = new int32_t*[rows];
	for (size_t i = 0; i < columns; ++i)
	{
		matrix[i] = new int32_t[columns];
	}
}
// Функция, которая возвращает номер первой из строк, содержащей хотя бы один нуль
void findFirstZero(int** matrix, int rows, int columns) {
	// Проверяем, что матрица не пустая
	if (matrix == nullptr || rows == 0 || columns == 0) {
		std::cout << "Matrix is empty" << '\n';
	}
	size_t temp = 0;
	// Проходим по строкам матрицы
	for (int i = 0; i < rows; i++) {
		// Проходим по элементам строки
		for (int j = 0; j < columns; j++) {
			if (matrix[i][j] == 0 && temp == 0) {
				std::cout << "\nfirst row with zero is " << i;
				++temp;
			}
		}
	}
	if (temp == 0)
	std::cout << "\n0 not detected!";
}

void matrixDelete(int32_t**& matrix, size_t columns)
{
	for (size_t i = 0; i < columns; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
void sedlo(size_t columns, size_t rows, int32_t** matrix)
{
	// Создаем динамические массивы для хранения минимумов по строкам и максимумов по столбцам
	int* row_mins = new int[rows];
	int* col_maxs = new int[columns];
	// Заполняем массивы максимальными и минимальными значениями
	for (int i = 0; i < rows; i++) {
		row_mins[i] = INT_MAX;
	}
	for (int j = 0; j < columns; j++) {
		col_maxs[j] = INT_MIN;
	}
	// Проходим по матрице и обновляем массивы
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			row_mins[i] = std::min(row_mins[i], matrix[i][j]);
			col_maxs[j] = std::max(col_maxs[j], matrix[i][j]);
		}
	}
	// Проходим по матрице еще раз и проверяем, является ли элемент седловой точкой
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			// Если элемент равен минимуму в своей строке и максимуму в своем столбце, то он седловой
			if (matrix[i][j] == row_mins[i] && matrix[i][j] == col_maxs[j]) {
				std::cout << "Saddle point found at (" << i << ", " << j << ") with value " << matrix[i][j] << '\n';

			}
		}
	}
	// Освобождаем память, выделенную для массивов
	delete[] row_mins;
	delete[] col_maxs;
}
void randParams(int32_t& left, int32_t& right)
{
	std::cout << "\nEnter left border: ";
	std::cin >> left;
	if (static_cast<int32_t>(left) != left)
		throw std::exception("\nInvalid random left border!");
	std::cout << "\nEnter right border: ";
	if (static_cast<int32_t>(right) != right)
		throw std::exception("\nInvalid random right border!");
	std::cin >> right;
	if (left > right)
	{
		std::swap(left, right);
	}
}
void randFill(int32_t** matrix, size_t rows, size_t columns, int32_t& left, int32_t& right)
{
	randParams(left, right);
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			matrix[i][j] = rand() % (right - left) + left;
		}

	}
}

void manFill(int32_t** matrix, size_t rows, size_t columns)
{
	std::cout << "\nEnter elements:";
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			std::cin >> matrix[i][j];
		}
		std::cout << '\n';
	}
}
bool methodIsRand()
{
	char inp = '0';
	std::cout << "\nHow u want to enter matrix? (1-random, 0-manual)";
	std::cin >> inp;
	switch (inp)
	{
	case '1':
		return true;
		break;
	case '0':
		return false;
		break;
	default:
		methodIsRand();
		break;
	}
}
void matrixOut(int32_t** matrix, size_t rows, size_t columns)
{
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << '\n';
	}
}
int32_t main()
{
	srand(time(nullptr));
	try {
	size_t rows = 0, columns = 0;
	int32_t left = 0, right = 0;
	int32_t** matrix = nullptr;
	matrixInit(matrix, columns, rows);
	if (methodIsRand())
	{
		randFill(matrix, rows, columns, left, right);
	}
	else
	{
		manFill(matrix, rows, columns);
	}
	matrixOut(matrix, rows, columns);
	sedlo(columns, rows, matrix);
	findFirstZero(matrix, rows, columns);
	matrixDelete(matrix, columns);
	return 0;
	}
	catch (std::exception e)
	{
		std::cerr << "OOPS! Exception: " << e.what();
		return -1;
	}
}