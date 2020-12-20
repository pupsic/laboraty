#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	//А:
	setlocale(LC_ALL, "Rus");
	int num, guess, tries = 0;
	srand(time(0)); 
	num = rand() % 100 + 1; // случайное число от 1 до 100
	do
	{
		cout << "Введите число от 1 до 100 : ";
		cin >> guess;
		tries++;

		if (guess > num)
			cout << "Слишком мало!\n\n";
		else if (guess < num)
			cout << "Слишком много!\n\n";
		else
			cout << "\nВерно! Вы потратили на это " << tries << " попыток!\n";
	} while (guess != num);
	return 0;
}
