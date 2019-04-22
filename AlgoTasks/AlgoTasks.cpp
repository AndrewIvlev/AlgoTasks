#include <iostream>
#include <locale.h>

using namespace std;

#define N 5
//TODO: 1)Добавить вывод среднего арифметического всех положительных чисел, всех чисел
// 2)Найти среднее от двух чисел (+ и -)=среднему всех чисел
int main()
{
	setlocale(LC_CTYPE, "Russian");

	int a[N];
	int i;

	for (i = 0; i < N; i++)
		cin >> a[i];
	double averagePositive = 0;
	double averageNegative = 0;
	double averageAll = 0;
	int sumNegative = 0;
	int sumPositive = 0;
	int numNegative = 0;
	int numPositive = 0;
	for (i = 0; i < N; i++)
	{
		if (a[i] < 0)
		{
			numNegative++;
			sumNegative += a[i];
		}
		if (a[i] > 0)
		{
			numPositive++;
			sumPositive += a[i];
		}
	}
	if (numNegative == 0)
	{
		numNegative = 0;
		cout << "Oтрицательных элементов нет";
	}
	if (numPositive == 0)
	{
		numPositive = 0;
		cout << "Положительных элементов нет";
	}
	if (numNegative > 0)
	{
		averageNegative = (double)sumNegative / numNegative;
		cout << "Среднее арифметическое отрицательных чисел в массиве: " << averageNegative;
	}
	cout << endl;
	if (numPositive > 0)
	{
		averagePositive = (double)sumPositive / numPositive;
		cout << "Среднее арифметическое положительных чисел в массиве: " << averagePositive;
	}
	cout << endl;
	if (averageNegative == 0)
	{
		averageAll = averagePositive;
		cout << "Среднее арифметическое всех чисел (без Отрицательных): " << averagePositive;
		cout << endl;
	}
	if (averagePositive == 0)
	{
		averageAll = averageNegative;
		cout << "Среднее арифметическое всех чисел (без Положительных): " << averageNegative;
		cout << endl;
	}
	if (averageNegative < 0 && averagePositive > 0)
	{
		averageAll = (averageNegative + averagePositive) / 2;
		cout << "Среднее арифметическое всех чисел: " << averageAll;
		cout << endl;
	}
}