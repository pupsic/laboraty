#include <iostream>
#include <iomanip>
#include <malloc.h>
using namespace std;
int size = 10;


int* add(int arr[])
{
	int input, pos, len;
	//ввод позиции и длины
	cout << "\nВведите позицию ";
	cin >> pos;
	cout << "\nВведите длину ";
	cin >> len;
	if (pos > ::size)
	{
		cout << "\nНе попадает в приделы массива\n";
		return arr;
	}
	int* copy_arr = new int[::size + len];
	for (int i = 0; i < pos; i++)//копируем элементы до позиции с арр
		copy_arr[i] = arr[i];
	for (int i = pos; i < pos + len; i++)//ввод элементов
	{
		cout << "\nВведите елемент>";
		cin >> input;
		copy_arr[i] = input;
	}
	for (int i = pos + len; i < ::size + len; i++)//удаление лишних элементов с конца массива
	{
		copy_arr[i] = arr[i - len];
	}
	::size += len;//добавление к длине количество добавленных элементов
	return copy_arr;
}

int* remove(int arr[])
{
	int input, pos, len;
	//ввод позиции и длины
	cout << "\nВведите позицию ";
	cin >> pos;
	cout << "\nВведите длину ";
	cin >> len;

	//проверка на наличие элементов в массиве
	if (pos + len > ::size || pos < 0)
	{
		cout << "\nНе попадает в приделы\n";
		return arr;
	}
	int* copy_arr = new int[::size - len];//копия массива в заданных пределах
	int count = 0;
	for (int i = 0; i < ::size; i++)
	{
		if (i >= pos && i < pos + len)//проверка на не выход из диапазона
		{
			count++;
			continue;
		}
		copy_arr[i - count] = arr[i];//убираем элементы из арр
	}
	::size -= len;//вычитание их длины количество убранных элементов
	return copy_arr;
}

int main(void)
{
	setlocale(LC_ALL, "Rus");
	int* arr = new int[::size];
	for (int i = 0; i < ::size; i++) arr[i] = i;//изначально 5 элементов
	for (int i = 0; i < ::size; i++)//напечатать массив
		cout << arr[i] << setw(3);
	int doing;//выбор действия

	cout << "\n1 - Добавить елементы\n";
	cout << "2 - Удалить елементы\n";
	cin >> doing;
	switch (doing)
	{
	case 1:
		arr = add(arr);//добавить
		for (int i = 0; i < ::size; i++)//напечатать массив
			cout << arr[i] << setw(3);
		break;
	case 2:
		arr = remove(arr);//убрать
		for (int i = 0; i < ::size; i++)//напечатать массив
			cout << arr[i] << setw(3);
		break;
	case 0:
		break;
	default:
		cout << "\nНе попадает в приделы";
		break;

	}
	delete[] arr;
}