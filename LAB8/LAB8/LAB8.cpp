#include <stdio.h>
#include <iostream>
using namespace std;

#define S 11 // любое нечетное число
int Ar[S][S]; /* матрица */

int main(void) {
    short l, r;  /* текущие индексы */
    
    short even=0;    
    short odd=0;     /* текущий член ЛП */
    //центральные точки:
    l = S/2;
    r = S/2;
    int i = 0;//количество повторений
    short num = 0;//числа для заполнения матрицы
    //Ar[l][r] = 1;
    while (i < (S/2))
    {
        //с[и какое-то слово] копия для определения придела
        int down,cdown;
        for (down = l, cdown=(2*i+down); down < (cdown+2); down++)//вниз от центральной точки
        {
            Ar[down][r] = ++num;
        }
        l = --down;
        
        int left, cleft;
        for (left = r, cleft = (left-2*i); left > (cleft-1);)//влево от последней позиции
        {
            Ar[l][--left] = ++num;
        }
        r = left;

        int up, cup;
        for ( up = l, cup=(up-2*i); up > (cup-2); )//вверх от последней позиции
        {
            Ar[--up][r] = ++num;
        }
        l = up;

        int right, cright;
        for (right = r,cright=(2*i+right); right < (cright+1);)//вправо от последней позиции
        {
            Ar[l][++right] = ++num;
        }
        r = ++right;
        i++;
    }
    //последний цикл для заполнения вниз
    for (l; l< S; l++)
    {
        Ar[l][r] = ++num;
    }

    //вывод матрицы   
    for (l = 0; l < S; l++) {
        for (r = 0; r < S; r++) {
            printf("%4d", Ar[l][r]);
        }
        printf("\n");
    }
    return 0;
}