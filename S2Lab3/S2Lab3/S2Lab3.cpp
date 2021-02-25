#include <iostream>
#include "funcs.h"
#include "globals.h"
using namespace std;

string menu[] = {
    "Manual list entry",
    "Automatic list entry",
    "Sort" ,
    "Print" ,
    "Find element",
    "Delete",
    "Delete all",
    "Full information",
    "Exit"
};

void call_menu(int elements_menu) {
    for (int i=0; i < elements_menu; i++)
    {
        cout << i << " - " << menu[i] << endl;
    }
}

int main(void)
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    mon* mc = new mon[NUM_OF_STRUCT];
    FCT* fct = new FCT[NUM_OF_STRUCT];
    int elements_menu = 9;
    int n = 0;
    for (bool status = 0; status < 1;)
    {
        system("cls");
        call_menu(elements_menu);

        int input;
        cin >> input;
        switch (input)
        {
        case 0:
            n = enter_keyboard(mc, n);
            break;
        case 1:
            n=enter_random(mc,n);
            break;
        case 2:
            sortirovka(mc, n);
            break;
        case 3:
            print(mc, n);
            break;
        case 4:
            find_element(mc, n);
            break;
        case 5:
            n = delete_stract(mc,n);
            break;
        case 6:
            n = delete_all_stract(mc, n);
            mc = new mon[NUM_OF_STRUCT];
            break;
        case 7:
            full_info(mc,n,fct);
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