#include<iostream>
#include<ctime>
using namespace std;

void bubbleSort(int arr[], int n);
void printArray(int arr[], int n);

int main()
{
    srand(time(0));
    int size;
    cout << "entre size: " << endl;
    cin >> size;
    int* arr = new int(size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 50;
    }

    bubbleSort(arr, size-1);
    printf("Sorted array : \n");

    printArray(arr, size);
    return 0;
}
void bubbleSort(int arr[], int n)
{
    if (n == 1)
        return;

    // Один проход пузырьковой сортировки. После
    // этого прохода, самый большой элемент
    // перемещается  в конец.
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);

    // Самый большой элемент фиксирован,
    // повторить для оставшегося массива
    bubbleSort(arr, n - 1);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


