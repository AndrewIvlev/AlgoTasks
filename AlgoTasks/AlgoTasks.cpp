#include <iostream>
#include <locale.h>

using namespace std;

#define N 5						// количество всех чисел

int main()
{
	setlocale(LC_CTYPE, "Russian");

	int sumPositive = 0;		// сумма положительных чисел
	int sumNegative = 0;		// сумма отрицательных чисел
	int sumAllNumbers = 0;		// сумма всех чисел

	int numPositive = 0;        // количество положительных чисел
	int numNegative = 0;		// количество отрицательных чисел
	int a[N];					// массив чисел
	int i;						// текущий индекс

	// Ввод чисел с клавиатуры
	for (i = 0; i < N; i++)
		cin >> a[i];

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
		sumAllNumbers += a[i];
	}

	if (N == 0)
	{
		cout << "В массиве нет элементов\n";
		return 404;
	}
	else
	{
		cout << "Среднее арифметическое всех чисел в массиве: " << (double)sumAllNumbers / N << "\n";

		if (numNegative == 0)
			cout << "Oтрицательных элементов нет\n";
		else
			if (numPositive > 0)
				cout << "Среднее арифметическое положительных чисел в массиве: " << (double)sumPositive / numPositive << "\n";
		if (numPositive == 0)
			cout << "Положительных элементов нет\n";
		else 
			if (numNegative > 0)
				cout << "Среднее арифметическое отрицательных чисел в массиве: " << (double)sumNegative / numNegative << "\n";
	}

	// Дополнительное задание: если в массиве есть и положительные, и отрицательные числа,
	// то сложить ср. ариф. положительный со ср. арфиметическим отрицательных и поделить на два,
	// а результат сравнить со средним арифметическим всех чисел.
	if ( numPositive != 0 && numNegative != 0)
	{
		double averageNegative = (double)sumNegative / numNegative;
		double averagePositive = (double)sumPositive / numPositive;
		double averageAll = (averageNegative + averagePositive) / 2;
		if (averageAll == (double)sumAllNumbers / N)
			cout << "РАВНЫ\n";
		else
			cout << "НЕ РАВНЫ\n";
		// -3 2 -1 1 1 проверь, разберись и объясни почему такой результат
	}
}