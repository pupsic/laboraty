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
    printf("������� �: ");

    cin >> x;
    printf("������� �: ");
    cin >> y;
    /* ����� ������ ��� ��������� �������� */
    printf("x=%6.3lf;  y=%6.3lf\n", x, y);
    /* �������� ������� */
    if (((x * y <= 1) && (x * y >= 0))/*1 � 3 ������������ ��������*/
        && /*�������� �� � ���� 3-� �������� ��� ������� �� � ������� � 1-�� ��������*/
        (((x * x + y * y) <= 1)//�������� ��� �����
            ||
            (((x <= 1) && (x >= 0)) && ((y <= 1) && (y >= 0)))//�������� ��� ��������
            )
        )
    {
        printf("����� �������� � �������\n");
    }

    else printf("����� �� �������� � �������\n");
}


