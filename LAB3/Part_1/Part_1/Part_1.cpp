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
    printf("Введите номер канала таймера (0 - 3) >");
    cin >> c;
    printf("Введите форма сигнала (0 - 3) >");
    cin >> f;
    printf("Введите коэффициент деления опорной частоты (0 - 4095) >");
    cin >> d;

    /* формирование упакованного кода */
    UnitStateWord = ((unsigned int)c & 3) << 14; //накладываем маску и сдвигаем полученный
    UnitStateWord |= ((unsigned int)f & 3) << 12;//результат на 14 и 12 разрядов соотвтствено 

    UnitStateWord |= d & 0xFFF;
    /* вывод результата */
    printf("\nСлово состояния устройства = %04x\n", UnitStateWord);
    return 0;
}
