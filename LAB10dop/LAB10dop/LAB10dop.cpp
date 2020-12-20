#include <iostream>
#include<ctime>
#include<stdio.h>
using namespace std;

double avr(int** arr, int rows, int columns) {
	double avrage=0;
	for (int i = 0; i < rows; ++i)
	{
		int min = arr[0][i];
		for (int j = 0; j < columns ; j++) {
			if (arr[j][i] < min)
				min = arr[j][i];
		}

		cout << min << endl;
		avrage = min + avrage;
	}
	avrage /= rows;

	return avrage;
}

void make_2d_arr(int *arr, int rows, int columns) {
	int** arr2d = new int* [rows];
	if (rows>columns)
	{
		
		for (int i = 0; i < rows; i++)
			arr2d[i] = new int[columns];
	}
	if (rows < columns)
	{
		for (int i = 0; i < columns; i++)
			arr2d[i] = new int[rows];
	}
	

	int temp=0;
	cout << endl;
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++) {
			arr2d[i][j] = arr[temp++];
		}
	}
	cout << endl;

	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++) {
			cout<< arr2d[i][j] <<' ';
		}
		cout << endl;
	}
	printf("%f", avr(arr2d, rows, columns));
}


int main() {
	int Size;
	int columns, rows;
	srand(time(NULL));
	cout << "input number of rows and columns : "<<endl;
	cin >> rows;
	cin >> columns;
	Size = rows * columns;
	int* arr = new int[Size];
	for (int i = 0; i < Size; i++) 
		arr[i] = rand() % 10 ;

	for (int i = 0; i < Size; i++)
		cout<<arr[i]<<' ';

	make_2d_arr(arr, rows, columns);
	
}
