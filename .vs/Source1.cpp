#include <iostream>
#include <iomanip>
#include<string>

using namespace std;

const int ROW = 18;
const int COLUMN = 18;

int FillMatrix(int matrix[ROW][COLUMN], int ROW, int COLUMN)
{
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			matrix[i][j] = rand() % 27 - 13;
		}
	}
	return matrix[ROW][COLUMN];

}


void PrintMatrix(int matrix[ROW][COLUMN], int ROW, int COLUMN)
{
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			cout << setw(3) << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}
int SumOfElements(int matrix[ROW][COLUMN]) {
	int firstNumber, secondNumber;
	cout << '\n' << "Введи номер столбца первого числа" << '\n';
	cin >> firstNumber;
	cout << '\n' << "Введи номер столбца второго числа" << '\n';
	cin >> secondNumber;
	int sumOfElements = 0;
	for (firstNumber; firstNumber < secondNumber; firstNumber++) {
		for (int i = 0; i < ROW; i++) {
			sumOfElements = sumOfElements + matrix[i][firstNumber];
		}
	}
	return sumOfElements;
}
double SumOfUpperTriangularMatrix(int matrix[ROW][COLUMN]) {

	double sumOfUpperTriangularMatrix = 0;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			if (i >= j)
			{
				sumOfUpperTriangularMatrix = sumOfUpperTriangularMatrix + matrix[i][j];
			}
		}
	}
	cout << '\n';
	return sumOfUpperTriangularMatrix;
}
string HasPositive(int matrix[ROW][COLUMN]) {
	bool hasPositive = true;
	for (int i = 0; i < ROW; i++) {
		if (matrix[i][0] < 0)
		{
			hasPositive = false;
		}
	}
	string result;
	if (hasPositive == true)
	{
		result = "Результат пункта <Б> = Есть строка из положительных чисел";
	}
	else if (hasPositive == false)
	{
		result = "Результат пункта <Б> = Нет строки из положительных чисел";
	}
	return result;

}
int Menu() {
	setlocale(LC_ALL, "Rus");
	int matrix[ROW][COLUMN] = {};
	FillMatrix(matrix, ROW, COLUMN);
	PrintMatrix(matrix, ROW, COLUMN);
	cout << "\nВыберите пункт\n"
		"1. В каждой строке матрицы найти сумму элементов, находящихся в диапазоне между двумя заданными числами\n"
		"2. Проверить, есть ли в матрице строка из положительных чисел\n"
		"3. Вычислить сумму элементов матрицы, выделенных чёрным цветом(матрица квадратная)\n"
		"4. Вывести все пункты задания\n";

	int id;
	cin >> id;
	switch (id)
	{
	case 1:

		cout << SumOfElements(matrix);
		break;
	case 2:
		cout << HasPositive(matrix);
		break;
	case 3:
		cout << SumOfUpperTriangularMatrix(matrix);
		break;
	case 4:
		cout << "Результат пункта <А> = " << SumOfElements(matrix) << "\n";
		cout << HasPositive(matrix);
		cout << "Результат пункта <В> = " << SumOfUpperTriangularMatrix(matrix) << '\n';

		break;
	default:
		system("cls");
		cout << "Неверно выбранная команда меню\n";
		cout << "Попробуй выбрать число от 1 до 4\n";

		return Menu();
	}
	return 0;
}


int main()
{
	Menu();
	return 0;

}