#include <iostream>
#include <windows.h>;
#include <iomanip>;
#include <crtdbg.h>
using namespace std;
struct Sel
{
    string name;
    string type;
    unsigned int s = 0;
    unsigned int yd = 0;
};

int manual(Sel* mc, int n)
{
    system("cls");
    for (n; ; n++)
    {
        cout << "Чтобы прекратить ввод введите *" << endl;
        cout << "Введите имя: ";
        cin >> mc[n].name;
        if (mc[n].name == "*") break;
        cout << "\nВведите тип культуры: ";
        cin >> mc[n].type;
        cout << "\nВведите площадь культуры: ";
        cin >> mc[n].s;
        cout << "\nВведите урожайность культуры: ";
        cin >> mc[n].yd;
        system("cls");
    }

    return n;
}

int avto(Sel* mc, int n)
{
    system("cls");
    for (n; n < n + rand() % 7; n++)
    {
        mc[n].name = rand() % 25 + 65;
        for (int i = 0; i < rand() % 5 + 4; i++) mc[n].name += rand() % 25 + 97;
        mc[n].type = rand() % 25 + 65;
        mc[n].s = rand() % 20000 + 2000;
        mc[n].yd = rand() % 20000 + 2000;
    }

    return n;
}

void print(Sel* mc, int n)
{
    system("cls");

    cout << "\n---------------------------------------------------------\n";
    cout << ("|               Сельскохозяйственные культуры           |\n");
    cout << ("|-------------------------------------------------------|\n");
    cout << ("| Наименование | Тип | Посевная площадь |  Урожайность  |\n");
    cout << ("|              |     |       (га)       |    (ц/га)     |\n");
    cout << ("---------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        cout << "|" << setw(14) << mc[i].name << "|" << setw(5) << mc[i].type << "|"
            << setw(18) << mc[i].s << "|" << setw(15) << mc[i].yd << "|\n";
    }
    cout << "---------------------------------------------------------\n";
    system("pause");
}

void sortirovka(Sel* mc, int n)
{
    Sel temp;
    int m;
    for (int i = 0; i < n - 1; i++) {
        m = i; /* минимальный элемент - первый */
        for (int j = i + 1; j < n; j++)
            /* если текущий элемент < минимального,
               он становится минимальным */
            if (mc[m].name > mc[j].name)
            {
                m = j;
                //cout << mc[i].name << " " << mc[j].name;
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
    Sel* mc = new Sel[100];
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
            n = manual(mc, n);
            break;
        case 2:
            n = avto(mc, n);
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