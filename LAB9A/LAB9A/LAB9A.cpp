#include <iostream>
#include<stdio.h>
#include <ctime>
#include<iomanip>
using namespace std;
#define S 9
int arr[S][S];

void print_m(int arr[S][S]) {
	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < S; j++) {
			printf("%3d", arr[i][j]);
		}
		cout << endl;
	}
}

int main()
{
	//A:
	srand(time(NULL));
	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < S; j++) {
			arr[i][j] = rand() % 51 + 1;
		}
	}
	
	for (int i = 0; i < S; i++)
	{
		int max = arr[i][0];
		for (int j = 0; j < S; j++) {
			if (arr[i][j] > max)
				max = arr[i][j];
		}
		arr[i][0] = max;
	}
	print_m(arr);
	cout << endl;
	//B
	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < S; j++) {
			arr[i][j] = rand() % 51 + 1;
		}
	}
	for (int i = 0; i < S; i++)
	{
		int min = arr[i][0];
		for (int j = 0; j < S; j++) {
			if (arr[j][i] < min)
				min = arr[j][i];
		}
		arr[0][i] = min;
	}
	print_m(arr);
	//умножение матриц


    int a[10][10], b[10][10], mult[10][10], r1, c1, r2, c2, i, j, k;

    cout << "Введите строки и столбцы для первой матрицы: ";
    cin >> r1 >> c1;
    cout << "Введите строки и столбцы для второй матрицы : ";
    cin >> r2 >> c2;
    // Если столбец первой матрицы не равен строке второй матрицы,
    // просим пользователя снова ввести размер матрицы.
    while (c1 != r2)
    {
        cout << "Ошибка! столбец первой матрицы не равен строке второй.";
        cout << "Введите строки и столбцы для первой матрицы:";
        cin >> r1 >> c1;
        cout << "Введите строки и столбцы для второй матрицы:";
        cin >> r2 >> c2;
    }

    // Сохраняем элементы первой матрицы.
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c1; ++j)
        {
            a[i][j]= rand() % 11 - 10;
        }

    // Сохраняем элементы первой матрицы.
    cout << endl << "Enter elements of matrix 2:" << endl;
    for (i = 0; i < r2; ++i)
        for (j = 0; j < c2; ++j)
        {
            b[i][j] = rand() % 11 - 10;;
        }
    // Инициализируем элементы матрицы mult до 0.
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c2; ++j)
        {
            mult[i][j] = 0;
        }

    // Умножение матрицы a и b и сохранение в массиве mult.
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c2; ++j)
            for (k = 0; k < c1; ++k)
            {
                mult[i][j] += a[i][k] * b[k][j];
            }

    // Отображение матрицы умножения двух.
    cout << endl << "матрица: " << endl;
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c2; ++j)
            {
            cout << " " << mult[i][j];
            if (j == c2 - 1)
                cout << endl;
            }
    return 0;
    
}

