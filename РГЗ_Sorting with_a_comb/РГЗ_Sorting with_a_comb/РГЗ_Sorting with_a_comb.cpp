#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
#define N 5

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (true) {
        // Находим крайний левый элемент больше, чем
        // или равно pivot
        do {
            i++;
        } while (arr[i] < pivot);

        // Находим крайний правый элемент меньше, чем
         // или равно pivot
        do {
            j--;
        } while (arr[j] > pivot);

        // Если встретились два указателя.
        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}
/*Основная функция, реализующая QuickSort
arr[]->Массив для сортировки,
низкий->Начальный индекс,
высокий->Индекс окончания*/

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        /*pi - индекс разделения, теперь arr[p]
            в нужном месте*/
        int pi = partition(arr, low, high);
        // Отдельно сортировать элементы перед
        // разделoм и после раздела
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}




// Найти зазор между элементами
int getNextGap(int gap)
{
    // Усадочный зазор по коэффициенту 
    gap = (gap * 10) / 13;

    if (gap < 1)
        return 1;
    return gap;
}

// Функция для сортировки [0..n-1] с помощью Comb Sort
void combSort(int a[], int n)
{
    
    int gap = n;
    bool swapped = true;

    // Продолжаем работать, пока пробел больше 1 и последний
     // итерация вызвала обмен
    while (gap != 1 || swapped == true)
    {
        // Находим следующий пробел
        gap = getNextGap(gap);
        // Инициализируем замену как false, чтобы мы могли
         // проверяем, произошел ли своп или нет
        swapped = false;
        // Сравнить все элементы с текущим разрывом
        for (int i = 0; i < n - gap; i++)
        {
            if (a[i] > a[i + gap])
            {
                swap(a[i], a[i + gap]);
                swapped = true;
            }
        }
    }
}


int main()
{
    int a[N] ;
    //for (int i = 0; i < N; a[i++] = i);//Упорядоченный массив
    for (int i = 0; i < N; a[i++] = N-i);//Массив, упорядоченный в обратном порядке
    //for (int i = 0; i < N; a[i++] = rand() % 201 - 100);//Неупорядоченный массив

    auto start = high_resolution_clock::now();
    quickSort(a, 0, N - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    
    return 0;
}



