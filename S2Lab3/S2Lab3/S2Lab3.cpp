#include <iostream>
#include "funcs.h"
#include "globals.h"

using namespace std;



int main(void)
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    mon* mc = new mon[NUM_OF_STRUCT];

    int n = 0;
    for (bool status = 0; status < 1;)
    {
        system("cls");
        cout << "1 - Manual list entry" << endl;
        cout << "2 - Automatic list entry" << endl;
        cout << "3 - Sort" << endl;
        cout << "4 - Print" << endl;
        cout << "5 - Find element" << endl;
        cout << "6 - Delete" << endl;
        cout << "7 - Full information" << endl;
        cout << "8 - Exit" << endl;
        int input;
        cin >> input;
        switch (input)
        {
        case 1:
            n = enter_keyboard(mc, n);
            break;
        case 2:
            n=enter_random(mc,n);
            break;
        case 3:
            sortirovka(mc, n);
            break;
        case 4:
            print(mc, n);
            break;
        case 5:
            find_element(mc, n);
            break;
        case 6:
            n = delete_stract(mc,n);
            break;
        case 7:
            full_info(mc,n);

            break;
        case 8:
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