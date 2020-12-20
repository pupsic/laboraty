#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	//Б:
	int a, b;
	int mark = 0;
	srand(time(0));
	int guess = 0;

	for (int i = 0; i < 10; i++)
	{
		a = rand() % 10 + 1; // случайное число от 1 до 10
		b = rand() % 10 + 1; // случайное число от 1 до 10
		cout << a << "*" << b << "=?" << endl;
		cin >> guess;
		if (guess == a * b) {
			mark++;
		}
	}
	return 0;
}
