#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int main(void) {
    short n;        /* �������� �������� ����� */
    double x, y;    /* �������� � �������� ������� */
    short h;        /* ������� ����� �� ������ */
    setlocale(LC_ALL, "Rus");
    for (n = 0; n < 5; n++) {  
        printf("|   x   |      y     |\n");
        printf("|-------|------------|\n");
        for (x = 0; x <= 4; x += 0.25) {
            /* 1-� ������� */
            if (x <= 2) y = sqrt(4-pow((x-2),2));
            /* 2-� ������� */
            else y = 4 - x;
            /* ����� ������ ������� */
            printf("| %5.2lf | %10.7lf |", x + n * 4, y);
            /* ����������� ������� ����� */
            h = (y + 1) * 10;
            if (y - 1 - h * 10 > 0.5) h++;
            /* ����� ����� ������� */
            for (; h > 0; h--) printf(" ");
            printf("*\n");
        }  /* ����� ����������� ����� */
      /* ����� �� ������� ��������� */
        printf("������� ������� Enter...");
        getchar();
    }  /* ����� �������� ����� */
    return 0;
} /* ����� ��������� */
