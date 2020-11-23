// LAB10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

int main(void) {
    setlocale(LC_ALL, "Rus");
    int size;                   /* размер массива */
    int* Ar;       /* указатель на начало массива */

    srand(time(NULL));
    size = rand() % 201 - 50;
    printf("size=%d\n", size);

    /* выделения памяти */
    Ar = (int *)malloc(size * sizeof(int));
    int i, j;    /* индексы в массиве */
    int nn; /* количество эл-тов в последовательности */
    int ib;      /* индекс начала последовательности */
    int copy_chek;
    /* заполнение массива случайными числами */
    for (i = 0; i < size; Ar[i++] = rand() % 101 - 50);
    /* вывод начального массива */
    printf("Начальный массив:\n");
    for (i = 0; i < size; printf("%3d  ", Ar[i++]));
    putchar('\n');
    putchar('\n');

    for (nn = i = 0; i < size; i++) { /* перебор массива */
        if (Ar[i] >= 0) {//проверка на положительные числа
            ib = i;
            for (int chek = ib, copy_chek = chek; Ar[chek] >= 0; chek++)
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
    printf("результат:%d\n",nn);
    
    putchar('\n');
    /* освобождение памяти */
    free(Ar);
    return 0;
}
