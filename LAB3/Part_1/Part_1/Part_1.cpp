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
    printf("������� ����� ������ ������� (0 - 3) >");
    cin >> c;
    printf("������� ����� ������� (0 - 3) >");
    cin >> f;
    printf("������� ����������� ������� ������� ������� (0 - 4095) >");
    cin >> d;

    /* ������������ ������������ ���� */
    UnitStateWord = ((unsigned int)c & 3) << 14; //����������� ����� � �������� ����������
    UnitStateWord |= ((unsigned int)f & 3) << 12;//��������� �� 14 � 12 �������� ������������ 

    UnitStateWord |= d & 0xFFF;
    /* ����� ���������� */
    printf("\n����� ��������� ���������� = %04x\n", UnitStateWord);
    return 0;
}
