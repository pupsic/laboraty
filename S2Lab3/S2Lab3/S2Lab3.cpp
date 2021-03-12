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
    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
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
            sortirovka_by_name_down(mc, n);
            for (bool status_sort = 0; status_sort < 1;)
            {
                system("cls");
                cout << "0 - Sort by name" << endl;
                cout << "1 - Sort by type" << endl;
                cout << "2 - Sort by wet" << endl;
                cout << "3 - Sort by coefficient" << endl;
                cout << "4 - exit" << endl;

                int input;
                cin >> input;
                switch (input)
                {
                case 0:
                    for (bool status_sort_name = 0; status_sort_name < 1;)
                    {
                        system("cls");
                        cout << "0 - Down" << endl;
                        cout << "1 - Up" << endl;
                        cout << "2 - Exit" << endl;

                        int input;
                        cin >> input;
                        switch (input)
                        {
                        case 0:
                            sortirovka_by_name_up(mc, n);
                            break;
                        case 1:
                            sortirovka_by_name_down(mc, n);
                            break;
                        case 2:
                            status_sort_name = 1;
                            break;
                        default:
                            cout << "Error";
                            system("pause");
                            break;
                        }
                        break;
                    }
                    break;
                case 1:
                    
                    for (bool status_sort_name = 0; status_sort_name < 1;)
                    {
                        system("cls");
                        cout << "0 - Down" << endl;
                        cout << "1 - Up" << endl;
                        cout << "2 - Exit" << endl;

                        int input;
                        cin >> input;
                        switch (input)
                        {
                        case 0:
                            sortirovka_by_type_up(mc, n);
                            break;
                        case 1:
                            sortirovka_by_type_down(mc, n);
                            break;
                        case 2:
                            status_sort_name = 1;
                            break;
                        default:
                            cout << "Error";
                            system("pause");
                            break;
                        }
                        break;
                    }
                    break;
                case 2:
                    for (bool status_sort_name = 0; status_sort_name < 1;)
                    {
                        system("cls");
                        cout << "0 - Down" << endl;
                        cout << "1 - Up" << endl;
                        cout << "2 - Exit" << endl;

                        int input;
                        cin >> input;
                        switch (input)
                        {
                        case 0:
                            sortirovka_by_wet_up(mc, n);
                            break;
                        case 1:
                            sortirovka_by_wet_down(mc, n);
                            break;
                        case 2:
                            status_sort_name = 1;
                            break;
                        default:
                            cout << "Error";
                            system("pause");
                            break;
                        }
                        break;
                    }
                    break;
                case 3:
                    for (bool status_sort_name = 0; status_sort_name < 1;)
                    {
                        system("cls");
                        cout << "0 - Down" << endl;
                        cout << "1 - Up" << endl;
                        cout << "2 - Exit" << endl;

                        int input;
                        cin >> input;
                        switch (input)
                        {
                        case 0:
                            sortirovka_by_coef_up(mc, n);
                            break;
                        case 1:
                            sortirovka_by_coef_down(mc, n);
                            break;
                        case 2:
                            status_sort_name = 1;
                            break;
                        default:
                            cout << "Error";
                            system("pause");
                            break;
                        }
                        break;
                    }
                    break;
                case 4:
                    status_sort = 1;
                    break;
                default:
                    cout << "Error";
                    system("pause");
                    break;
                }
                break;
            }

            break;
        case 3:
            print(mc, n);
            break;
        case 4:
            
            for (bool status_find = 0; status_find < 1;)
            {
                system("cls");
                cout << "0 - find by name" << endl;
                cout << "1 - find by type" << endl;
                cout << "2 - find by wet" << endl;
                cout << "3 - find by coefficient" << endl;
                cout << "4 - exit" << endl;

                int input;
                cin >> input;
                switch (input)
                {
                case 0:
                    find_element_name(mc, n);
                    break;
                case 1:
                    find_element_type(mc, n);
                    break;
                case 2:
                    find_element_wet(mc, n);
                    break;
                case 3:
                    find_element_coef(mc, n);
                    break;
                case 4:
                    status_find = 1;
                    break;
                default:
                    cout << "Error";
                    system("pause");
                    break;
                }
                break;
            }

            break;
        case 5:
            
            for (bool status_del = 0; status_del < 1;)
            {
                system("cls");
                cout << "0 - delete by name"<<endl;
                cout << "1 - delete by type" << endl;
                cout << "2 - delete by wet" << endl;
                cout << "3 - delete by coefficient" << endl;
                cout << "4 - exit" << endl;
                
                int input;
                cin >> input;
                switch (input)
                {
                case 0:
                    n = delete_stract_by_name(mc, n);
                    break;
                case 1:
                    n = delete_stract_by_type(mc, n);
                    break;
                case 2:
                    n = delete_stract_by_wet(mc, n);
                    break;
                case 3:
                    n = delete_stract_by_coefficient(mc, n);
                    break;
                case 4:
                    status_del = 1;
                    break;
                default:
                    cout << "Error";
                    system("pause");
                    break;
                }
                break;
            }
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