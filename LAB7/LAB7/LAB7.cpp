#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
int Ar[200];   /* массив, который обрабатывается */

int main(void) {
    setlocale(LC_ALL, "Rus");
    int i, j;    /* индексы в массиве */
    int nn; /* количество эл-тов в последовательности */
    int ib;      /* индекс начала последовательности */
    int copy_chek;
    srand(time(NULL));  /* инициализация rand */
    /* заполнение массива случайными числами */
    for (i = 0; i < 200; Ar[i++] = rand()%101 - 50);
    /* вывод начального массива */
    printf("Начальный массив:\n");
    for (i = 0; i < 200; printf("%3d  ", Ar[i++]));
    putchar('\n');
    putchar('\n');

    for (nn = i = 0; i < 200; i++) { /* перебор массива */
        if (Ar[i] >= 0) {//проверка на положительные числа
            ib = i;
            for (int chek = ib,copy_chek = chek;  Ar[chek] >= 0; chek++)
            {
                if (chek >= (copy_chek + 6)) {//проверка для нахождения ровно семи подряд элементов
                    for (; Ar[chek] >= 0; chek++);//находим все элементы которые положительные и больше этой поседовотельности
                    nn++;//найденна последовательность
                    i = chek;//ставим точку поиска в массиве
                    break;
                }
            }
        }
    }
    /* вывод результатов */
    printf("%d\n",nn);
    
    putchar('\n');

    return 0;
}