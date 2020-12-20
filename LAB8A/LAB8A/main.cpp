#include<iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	int yes=0, no=5;
	for (int i = 0; i < 10; )
	{
		char answer[3];
		cin >> answer;
		char letter = answer[0];
		if (letter== 'Y' && yes<5) {
			yes++;
			cout<<"Занято место: "<<yes<<endl;
			i++;
		}
		else if (letter == 'N' && no < 10) {
			no++;
			cout << "Занято место: " << no << endl;
			i++;
		}
		else {
			cout << "Нет мест " << endl;
		}
	}
	return 0;
}
