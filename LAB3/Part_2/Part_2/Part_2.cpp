#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {
    setlocale(LC_ALL, "Rus");
    char c; /* ����� ������ ������� */
    char f; /* ����� ������� */
    unsigned short d; /* ����������� ������� ������� ������� */
    unsigned int UnitStateWord; /* ����� ��������� */
     /* ���� ��������� ������ */
    printf("������� c���� ��������� ���������� \n");
    printf("(16-������ ����� �� 0 �� 0xFFFF) >");
    cin >> hex >> UnitStateWord;//���� ������ � 16-������ ������� �� ������ hex
    /* ��������� ��������� ������ */
    c = (UnitStateWord >> 14) & 3;
    f = (UnitStateWord >> 12) & 3;
    d = UnitStateWord & 0xFFF;
    /* ����� ����������� */
    putchar('\n');
    printf("����� ������ �������                    = %d\n", c);
    printf("����� �������                           = %d\n", f);
    printf("����������� ������� ������� �������     = %d\n", d);
    
    return 0;
}
