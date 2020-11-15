#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {
    setlocale(LC_ALL, "Rus");
    char c; /* номер канала таймера */
    char f; /* форма сигнала */
    unsigned short d; /* коэффициент деления опорной частоты */
    unsigned int UnitStateWord; /* слово состояния */
     /* ввод составных частей */
    printf("Введите cлово состояния устройства \n");
    printf("(16-ричное число от 0 до 0xFFFF) >");
    cin >> hex >> UnitStateWord;//ввод данных в 16-ричной системе пр помощи hex
    /* Выделение составных частей */
    c = (UnitStateWord >> 14) & 3;
    f = (UnitStateWord >> 12) & 3;
    d = UnitStateWord & 0xFFF;
    /* вывод результатов */
    putchar('\n');
    printf("номер канала таймера                    = %d\n", c);
    printf("форма сигнала                           = %d\n", f);
    printf("коэффициент деления опорной частоты     = %d\n", d);
    
    return 0;
}
