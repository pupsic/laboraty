#include <iostream>  
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int n, sum = 0, m;
	int sum_of_num = 0;
	cout << "Введите число: "<<endl;
	cin >> n;
	int copy = n;
	while (n > 0)
	{
		m = n % 10;
		sum = sum + m;
		n = n / 10;
		sum_of_num++;
	}
	cout << "Сумма=           " << sum << endl;
	cout << "Всего чисел=     " << sum_of_num << endl;

	int reversedNumber = 0, remainder;
	while (copy != 0) {
		remainder = copy % 10;
		reversedNumber = reversedNumber * 10 + remainder;
		copy /= 10;
	}
	cout << "Число 	наоборот= " << reversedNumber;

	return 0;
}