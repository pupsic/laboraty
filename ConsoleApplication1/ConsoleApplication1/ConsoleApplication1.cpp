#include<iostream>
#include<ctime>

using namespace std;






int main()
{
	int a = 0;
	for (int i = 0; i <=10000 ; i++)
	{
		if (i%2==0 || i%3==0 ) {
			a++;
		}
	}
	cout << a;
    return 0;
}



