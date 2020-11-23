#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

/* strcpy: копирует t в s; версия 3 (с указателями) */
void custom_strcpy(char* s, char* t)
{
    while (*s++ = *t++);
}
/* Описание структуры, которая представляет монастырь */
struct mon {
    char Substance[15]; /* Вещество */
    char type;       /* Тип */
    int wet;       /* Влажность */
    float Coef;      /* Коэффициент */
} mm[10]; /* определение массива Вещества */
int main(void) {
    setlocale(LC_ALL, "Rus");
    struct mon x; /* рабочая переменная */
    int n;    /* количество элементов в массиве */
    int i, j; /* текущие индексы в массиве */
    int m;    /* индекс минимального элемента */
    float sqx;/* рабочая переменная */
     /* Ввод данных */
    for (n = 0; n < 10; n++) {
        printf("%d. Введите: Вещество, Тип, Влажность(%), Коэффициент >",
            n + 1);
        cin >> mm[n].Substance;
        if (!strcmp(mm[n].Substance, "***")) break;
        cin >> mm[n].type;
        cin >> mm[n].wet;
        /* Внимание! Мы обходим ошибку в системе программирования */
        cin >> sqx; mm[n].Coef = sqx;
    }
    /* Вывод таблицы */
    printf("---------------------------------------------\n");
    printf("| Коэффициенты теплопроводимости материаллов |\n");
    printf("|--------------------------------------------|\n");
    printf("| Вещество  | Тип   |Влажность | Коэффициент |\n");
    printf("|           |       |          |             |\n");
    printf("|-----------|-------|----------|-------------|\n");
    /* вывод строк фактических данных */
    for (i = 0; i < n; i++)
        printf("| %9s |   %c   |      %3d | %-5.1f       |\n",
            mm[i].Substance, mm[i].type, mm[i].wet, mm[i].Coef);
    printf("---------------------------------------------\n");
    /* сортировка массива */
    for (i = 0; i < n - 1; i++) {
        m = i; /* минимальный элемент - первый */
        for (j = i + 1; j < n; j++)
            /* если текущий элемент > минимального,
               он становится минимальным */
            if (strcmp(mm[m].Substance, mm[j].Substance) > 0) m = j;
        if (m > i) {
            /* перестановка первого и минимального элементов */
            custom_strcpy(x.Substance, mm[i].Substance); x.type = mm[i].type;
            x.wet = mm[i].wet; x.Coef = mm[i].Coef;
            custom_strcpy(mm[i].Substance, mm[m].Substance); mm[i].type = mm[m].type;
            mm[i].wet = mm[m].wet; mm[i].Coef = mm[m].Coef;
            custom_strcpy(mm[m].Substance, x.Substance); mm[m].type = x.type;
            mm[m].wet = x.wet; mm[m].Coef = x.Coef;
        }
    }
    /* Вывод таблицы */
    printf("---------------------------------------------\n");
    printf("| Коэффициенты теплопроводимости материаллов |\n");
    printf("|--------------------------------------------|\n");
    printf("| Вещество  | Тип   |Влажность | Коэффициент |\n");
    printf("|           |       |          |             |\n");
    printf("|-----------|-------|----------|-------------|\n");
    for (i = 0; i < n; i++)
        printf("| %9s |   %c   |      %3d | %-5.1f       |\n",
            mm[i].Substance, mm[i].type, mm[i].wet, mm[i].Coef);
    printf("---------------------------------------------\n");
    return 0;
}
