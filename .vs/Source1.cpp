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
int FindSumOfElements(int matrix[ROW][COLUMN]) {
	int firstNumber, secondNumber;
	cout << '\n' << "����� ����� ������� ������� �����" << '\n';
	cin >> firstNumber;
	cout << '\n' << "����� ����� ������� ������� �����" << '\n';
	cin >> secondNumber;
	int sumOfElements = 0;
	for (firstNumber; firstNumber < secondNumber; firstNumber++) {
		for (int i = 0; i < ROW; i++) {
			sumOfElements = sumOfElements + matrix[i][firstNumber];
		}
	}
	return sumOfElements;
}
double FindSumOfUpperTriangularMatrix(int matrix[ROW][COLUMN]) {

	double sumOfUpperTriangularMatrix = 0;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			if (i >= j)
			{
				sumOfUpperTriangularMatrix = sumOfUpperTriangularMatrix +
					matrix[i][j];
			}
		}
	}
	cout << '\n';
	return sumOfUpperTriangularMatrix;
}
string CheckHasPositive(int matrix[ROW][COLUMN]) {
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
		result = "��������� ������ <�> = ���� ������ �� ������������� �����";
	}
	else if (hasPositive == false)
	{
		result = "��������� ������ <�> = ��� ������ �� ������������� �����";
	}
	return result;

}
int PrintMenu() {
	setlocale(LC_ALL, "Rus");
	int matrix[ROW][COLUMN] = {};
	FillMatrix(matrix, ROW, COLUMN);
	PrintMatrix(matrix, ROW, COLUMN);
	cout << "\n�������� �����\n"
		"1. � ������ ������ ������� ����� ����� ���������, ����������� � ��������� 
		����� ����� ��������� �������\n"
		"2. ���������, ���� �� � ������� ������ �� ������������� �����\n"
		"3. ��������� ����� ��������� �������, ���������� ������ ������(������� 
		����������)\n"
		"4. ������� ��� ������ �������\n";

	int id;
	cin >> id;
	switch (id)
	{
	case 1:

		cout << FindSumOfElements(matrix);
		break;
	case 2:
		cout << CheckHasPositive(matrix);
		break;
	case 3:
		cout << FindSumOfUpperTriangularMatrix(matrix);
		break;
	case 4:
		cout << "��������� ������ <�> = " << FindSumOfElements(matrix) << "\n";
		cout << CheckHasPositive(matrix);
		cout << "��������� ������ <�> = " << FindSumOfUpperTriangularMatrix(matrix) <<
			'\n';

		break;
	default:
		system("cls");
		cout << "������� ��������� ������� ����\n";
		cout << "�������� ������� ����� �� 1 �� 4\n";

		return PrintMenu();
	}
	return 0;
}

int main()
{
	PrintMenu();
	return 0;

}
