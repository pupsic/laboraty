#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int main(void) {
    short n;        /* параметр внешнего цикла */
    double x, y;    /* абсцисса и ордината графика */
    short h;        /* позиция точки на экране */
    setlocale(LC_ALL, "Rus");
    for (n = 0; n < 5; n++) {  
        printf("|   x   |      y     |\n");
        printf("|-------|------------|\n");
        for (x = 0; x <= 4; x += 0.25) {
            /* 1-й отрезок */
            if (x <= 2) y = sqrt(4-pow((x-2),2));
            /* 2-й отрезок */
            else y = 4 - x;
            /* вывод строки таблицы */
            printf("| %5.2lf | %10.7lf |", x + n * 4, y);
            /* определение позиции точки */
            h = (y + 1) * 10;
            if (y - 1 - h * 10 > 0.5) h++;
            /* вывод точки графика */
            for (; h > 0; h--) printf(" ");
            printf("*\n");
        }  /* конец внутреннего цикла */
      /* пауза до команды оператора */
        printf("Нажмите клавишу Enter...");
        getchar();
    }  /* конец внешнего цикла */
    return 0;
} /* конец программы */
