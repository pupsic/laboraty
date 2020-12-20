#include <iostream>
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
	//B
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
			if (arr[j][i] > max)
				max = arr[j][i];
		}
		printf("%3d", max);
		
	}
	cout <<endl<<endl;
	print_m(arr);
}


