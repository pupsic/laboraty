#include<iostream>
using namespace std;


int findArea(int lenght, int width = 0) {
	if (width == 0) {
		return lenght * lenght;
	}
	else
	{
		return lenght * width;
	}
}


void swapWithLink(int& a, int& b, int& c)
{
	if ((a >= b) && (a >= c)) {
		if (b >= c) {
			int temp = c;
			c = a;
			a = temp;
		}
		else if (b < c) {
			int temp = b;
			b = a;
			a = temp;
		}
	}
	else if ((b >= a) && (b >= c)) {
		if (a >= c) {
			int temp = c;
			c = b;
			b = temp;
		}
		else if (a < c) {
			int temp = a;
			a = b;
			b = temp;
		}
	}
	else if ((c >= a) && (c >= b)) {
		if (a >= b) {
			int temp = b;
			b = c;
			c = temp;
		}
		else if (a < b) {
			int temp = a;
			a = c;
			c = temp;
		}
	}
}

void swapWithPointer(int* a, int* b, int* c)
{
	if ((*a >= *b) && (*a >= *c)) {
		if (*b >= *c) {
			int temp = *c;
			*c = *a;
			*a = temp;
		}
		else if (*b < *c) {
			int temp = *b;
			*b = *a;
			*a = temp;
		}
	}
	else if ((*b >= *a) && (*b >= *c)) {
		if (*a >= *c) {
			int temp = *c;
			*c = *b;
			*b = temp;
		}
		else if (*a < *c) {
			int temp = *a;
			*a = *b;
			*b = temp;
		}
	}
	else if ((*c >= *a) && (*c >= *b)) {
		if (*a >= *b) {
			int temp = *b;
			*b = *c;
			*c = temp;
		}
		else if (*a < *b) {
			int temp = *a;
			*a = *c;
			*c = temp;
		}
	}
}


class SUM
{
private:
	int x;
	int y;
	int sum = NULL;
public:

	SUM(int x, int y) {
		this->x = x;
		this->y = y;

	}
	SUM() {
		this->x = 0;
		this->y = 0;
	}
	void setVars(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void displayVars() {
		cout << "x: " << this->x << endl;
		cout << "y: " << this->y << endl;
		cout << "sum: " << this->sum << endl;
	}
	int summ() {
		this->sum = x + y;
		cout <<"Display from inside class: "<< this->sum <<endl;
		return this->sum;
	}
};

class TIMER
{
private:
	int seconds=0;
public:

	TIMER(int seconds) {
		this->seconds = seconds;
	}
	TIMER(int minuts, int seconds) {
		this->seconds = 60*minuts + seconds;
	}
	TIMER(const TIMER& ob) {
		seconds = ob.seconds;
	}
	void display() {
		cout << "seconds: " <<this->seconds << endl;
	}
};



int main() {


	for (int i = 0; i != 1; )
	{
		cout << "1-Task 1" << endl;
		cout << "2-Task 2" << endl;
		cout << "3-Task 3" << endl;
		cout << "4-Task 4" << endl;
		int index;
		cin >> index;
		if (index ==1) {
			system("cls");
			cout << "1-input two vars" << endl;
			cout << "2-input one vars" << endl;
			cin >> index;
			int a, b;
			if (index == 1) {
				cin >> a;
				cin >> b;
				cout << "area" << findArea(a,b) << endl;
			}
			if (index == 2) {
				cin >> a;
				cout <<"area"<< findArea(a)<<endl;
			}
			system("pause");
			system("cls");

			continue;
		}
		else if (index == 2) {
			system("cls");
			cout << "1-by Pointer" << endl;
			cout << "2-by Link" << endl;
			cin >> index;
			system("cls");
			cout << "input 3 numbers: " << endl;
			int a, b,c;
			cin >> a;
			cin >> b;
			cin >> c;
			cout << a << " " << b << " " << c << endl;
			if (index == 1) {
				swapWithPointer(&a, &b, &c);
				cout << a << " " << b << " " << c << endl;
			}
			if (index == 2) {
				swapWithLink(a, b, c);
				cout << a << " " << b << " " << c << endl;
			}
			system("pause");
			system("cls");
			continue;
		}
		else if (index == 3) {
			system("cls");
			SUM sum;
			for (int j = 0; j != 1; ) {
				cout << "1-default constructor" << endl;
				cout << "2-constructor with parametrs" << endl;
				cout << "3-Set x and y" << endl;
				cout << "4-display all vars" << endl;
				cout << "5-display summa" << endl;
				cout << "6-exit" << endl;
				cin >> index;
				system("cls");

				if (index == 1) {
					sum = SUM();
				}
				if (index == 2) {
					system("cls");
					cout << "input 2 numbers: " << endl;
					int a, b;
					cin >> a;
					cin >> b;
					sum = SUM(a, b);
					SUM* Psum = &sum;
				}
				if (index == 3) {
					system("cls");
					cout << "input x and y: " << endl;
					int a, b;
					cin >> a;
					cin >> b;
					sum.setVars(a, b);
				}
				if (index == 4) {
					system("cls");
					sum.displayVars();
				}
				if (index == 5) {
					system("cls");
					sum.summ();
				}
				if (index == 6) {
					break;
				}
				system("pause");
				system("cls");
				continue;
			}
			continue;
		}
		else if (index == 4) {
			TIMER timer = TIMER(0);
			for (int j = 0; j != 1; ) {
				system("cls");
				cout << "1-input only seconds" << endl;
				cout << "2-input minuts and seconds" << endl;
				cout << "3-Copy" << endl;
				cout << "4-Display" << endl;
				cout << "5-exit" << endl;
				cin >> index;
				system("cls");

				if (index == 1) {
					cout << "input seconds: " << endl;
					int seconds;
					cin >> seconds;
					timer = TIMER(seconds);
				}
				if (index == 2) {
					cout << "input minuts and seconds: " << endl;
					int seconds, minuts;
					cin >> seconds;
					cin >> minuts;
					timer = TIMER(minuts, seconds);
				}
				if (index == 3) {

					TIMER copy = TIMER(timer);

				}
				if (index == 4) {
					timer.display();
				}
				if (index == 5) {
					break;
				}
				system("pause");
				system("cls");
				continue;
			}
			continue;
		}
	}

	return 1;
}


