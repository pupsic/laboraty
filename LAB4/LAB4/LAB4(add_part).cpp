#include <time.h>
#include <iostream>
#include <stdio.h>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Rus");
    setlocale(LC_ALL, "Rus");
    double x;
    double y;
    printf("Ввидите х: ");

    cin >> x;
    printf("Ввидите у: ");
    cin >> y;
    /* вывод только что введенных значений */
    printf("x=%6.3lf;  y=%6.3lf\n", x, y);
    /* проверка условий */
    if (((x * y <= 1) && (x * y >= 0))/*1 и 3 координатная четверть*/
        && /*попадает ли в круг 3-й четверти ИЛИ попадет ли в квадрат в 1-ой четверти*/
        (((x * x + y * y) <= 1)//проверка для круга
            ||
            (((x <= 1) && (x >= 0)) && ((y <= 1) && (y >= 0)))//проверка для квадрата
            )
        )
    {
        printf("Точка попадает в область\n");
    }

    else printf("Точка не попадает в область\n");
}


