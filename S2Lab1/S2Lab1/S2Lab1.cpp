#include <iostream>
using namespace std;


int counter(int low, int max)
{
    if (max == low)
        return low;
    return max + counter(low, max - 1);

}

int print_range(int min, int n) {
    if (min == n+1) {
        return 1;
    }
    
    for (int i = 0; i < min; i++)
    {
        cout << min << ' ';
    }
    return print_range(min+1,n);
}

int main()
{
	int check;
	bool status = 1;
	for (;;)
	{
		if (status == 0) break;
		cout << "\n1 - LAB1\n";
		cout << "2 - LAB1A\n";
		cout << "0 - Out\n";
		cout << "Enter> ";
		cin >> check;
		switch (check)
		{
		case 1:
			int n;
			int m;
			cout << "min: ";
			cin >> n;
			cout << "max: ";
			cin >> m;
			cout << counter(n, m) << endl;
			break;
		case 2:
			int range;
			cout << "enter range: ";
			cin >> range;
			print_range(0, range);
			break;
		case 0:
			status = 0;
			break;
		default:
			cout << "\nWrong input";
			break;

		}
	}

}
