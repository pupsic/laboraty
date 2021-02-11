#include <iostream>
#include <windows.h>;
#include <iomanip>;
#include <crtdbg.h>

using namespace std;
struct mon
{
    string name;
    string type;
    unsigned int wet = 0;
    double coef = 0;
};

int enter_keyboard(mon* mc, int n)
{
    system("cls");
    for (n; ; n++)
    {
        cout << "Чтобы прекратить ввод введите '<'" << endl;
        cout << "Введите имя: ";
        cin >> mc[n].name;
        if (mc[n].name == "<") break;
        cout << "\nВведите тип культуры: ";
        cin >> mc[n].type;
        cout << "\nВведите площадь культуры: ";
        cin >> mc[n].wet;
        cout << "\nВведите урожайность культуры: ";
        cin >> mc[n].coef;
        system("cls");
    }

    return n;
}

int enter_random(mon* mc, int n)
{
    system("cls");
    for (n; n < n + rand() % 7; n++)
    {
        mc[n].name = rand() % 25 + 65;
        for (int i = 0; i < rand() % 5 + 4; i++) mc[n].name += rand() % 25 + 97;
        mc[n].type = rand() % 25 + 65;
        mc[n].wet = rand() % 100+0;
        float a = 1000.0;
        mc[n].coef = (float(rand()) / float((RAND_MAX)) * a);
    }

    return n;
}

void print(mon* mc, int n)
{
    system("cls");

    printf("---------------------------------------------\n");
    printf("| Коэффициенты теплопроводимости материаллов |\n");
    printf("|--------------------------------------------|\n");
    printf("|   Вещество   | Тип |Влажность | Коэффициент|\n");
    printf("|              |     |          |            |\n");
    printf("|--------------|-----|----------|------------|\n");
    for (int i = 0; i < n; i++)
    {
        cout << "|" << setw(14) << mc[i].name << "|" << setw(5) << mc[i].type << "|"
            << setw(10) << mc[i].wet << "|" << setw(12) << mc[i].coef << "|\n";
    }
    cout << "---------------------------------------------\n";
    system("pause");
}

void sortirovka(mon* mc, int n)
{
    mon temp;
    int m;
    for (int i = 0; i < n - 1; i++) {
        m = i; /* минимальный элемент - первый */
        for (int j = i + 1; j < n; j++)
            /* если текущий элемент < минимального,
               он становится минимальным */
            if (mc[m].name > mc[j].name)
            {
                m = j;
            }
        if (m > i) {
            temp = mc[i];
            mc[i] = mc[m];
            mc[m] = temp;
        }
    }
}

int main(void)
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    mon* mc = new mon[100];
    int n = 0;
    for (bool status = 0; status < 1;)
    {
        system("cls");
        cout << "1 - Ручной ввод списка" << endl;
        cout << "2 - Автоматический ввод списка" << endl;
        cout << "3 - Сортировка" << endl;
        cout << "4 - Печать" << endl;
        cout << "5 - Выход" << endl;
        int input;
        cin >> input;
        switch (input)
        {
        case 1:
            n = enter_keyboard(mc, n);
            break;
        case 2:
            n = enter_random(mc, n);
            break;
        case 3:
            sortirovka(mc, n);
            break;
        case 4:
            print(mc, n);
            break;
        case 5:
            status = 1;
            break;
        default:
            cout << "Error";
            system("pause");
            break;
        }

    }
    delete mc;
    _CrtDumpMemoryLeaks();
    return 0;
}