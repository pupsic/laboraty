#include <iostream>
#include"LIST.h"
#include <string>
#include <cmath>
#include "libxl.h"
using namespace libxl;
using namespace std;

void call_menu() {
    cout << "0 -" << "Manual list entry" << endl;
    cout << "1 -" << "File list entry" << endl;
    cout << "2 -" << "Sort" << endl;
    cout << "3 -" << "Print" << endl;
    cout << "4 -" << "Find element" << endl;
    cout << "5 -" << "Delete" << endl;
    cout << "6 -" << "Write to file" << endl;
    cout << "7 -" << "Exit" << endl;
}

int main()
{
    int i = 0;
    linked_list a;
    linked_list::data* Data = new linked_list::data;
    for (bool status = 0; status < 1;)
    {
        system("cls");
        call_menu();

        int input;
        cin >> input;
        switch (input)
        {
        case 0:
            for (bool status_find = 0; status_find < 1;)
            {
                system("cls");
                cout << "0 - add to start" << endl;
                cout << "1 - add to end" << endl;
                cout << "2 - add to any place" << endl;
                cout << "3 - exit" << endl;
                int input;
                cin >> input;
                system("cls");

                string val;
                cout << "input data: " << endl;
                cin >> Data->name;
                cin >> Data->type;
                cin >> Data->wet;
                cin >> Data->coef;
                
                system("cls");
                switch (input)
                {
                case 0:

                    a.addBeginning(&a.get_head(), Data);
                    break;
                case 1:
                    a.addEnd(&a.get_head(), Data);
                    break;
                case 2:
                    cout << "input id of place: " << endl;
                    int id;
                    cin >> id;
                    if (id==0)
                    {
                        a.addBeginning(&a.get_head(), Data);
                    }else
                    { 
                        id--;
                        a.insert(a.getNode(id, a.get_head()), Data); 
                    }
                    break;
                case 3:
                    status_find = 1;
                    break;
                default:
                    cout << "Error";
                    system("pause");
                    break;
                }
                break;
            }
            system("cls");
            break;
        case 1:
            
            break;
        case 2:

            for (bool status_sort = 0; status_sort < 1;)
            {
                system("cls");
                cout << "0 - sort by name" << endl;
                cout << "1 - sort by type" << endl;
                cout << "2 - sort by wet" << endl;
                cout << "3 - sort by coef" << endl;
                cout << "4 - exit" << endl;
                int input;
                cin >> input;

                system("cls");
                switch (input)
                {
                case 0:
                    a.MergeSort("name", &a.get_head());
                    break;
                case 1:
                    a.MergeSort("type", &a.get_head());
                    break;
                case 2:
                    a.MergeSort("wet", &a.get_head());
                    break;
                case 3:
                    a.MergeSort("coef", &a.get_head());
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
            system("cls");

            break;
        case 3:
            a.printTable(a.get_head());
            break;
        case 4:
            search_collection(a);
            break;
        case 5:
            for (bool status_delete = 0; status_delete < 1;)
            {
                system("cls");
                cout << "0 - delete to start" << endl;
                cout << "1 - delete to end" << endl;
                cout << "2 - delete by column name" << endl;
                cout << "3 - exit" << endl;
                int input;
                cin >> input;
                system("cls");
                switch (input)
                {
                case 0:

                    a.deleteBeginning(a.get_head());
                    break;
                case 1:
                    a.deleteNode(a.get_head(), a.getNode(a.getSize(a.get_head()) - 1, a.get_head()));
                    break;
                case 2:
                    for (bool status_delete = 0; status_delete < 1;)
                    {
                        system("cls");
                        cout << "0 - delete by name" << endl;
                        cout << "1 - delete by type" << endl;
                        cout << "2 - delete by wet" << endl;
                        cout << "3 - delete by coef" << endl;
                        cout << "4 - exit" << endl;
                        int input;
                        cin >> input;
                        system("cls");

                        string val;
                        cout << "input value: " << endl;
                        cin >> val;
                        system("cls");
                        switch (input)
                        {
                        case 0:
                            a.deleteSpecificName(val, a.get_head(), a.get_tail());
                            break;
                        case 1:
                            a.deleteSpecificName(val, a.get_head(), a.get_tail());
                            break;
                        case 2:
                            a.deleteSpecificName(val, a.get_head(), a.get_tail());
                            break;
                        case 3:
                            a.deleteSpecificName(val, a.get_head(), a.get_tail());
                            break;
                        case 4:
                            status_delete = 1;
                            break;
                        default:
                            cout << "Error";
                            system("pause");
                            break;
                        }
                        break;
                    }
                    system("cls");
                    break;
                case 3:
                    status_delete = 1;
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
            writeToFile(a);
            break;
        case 7:
            status = 1;
            break;
        default:
            cout << "Error";
            system("pause");
            break;
        }
    }
    //for (int i = 0; i < 5; i++)
    //{
    //    Data->coef = i;
    //    a.addEnd(&a.get_head(), Data);
    //}
    //for (int i = 0; i < 5; i++)
    //{
    //    a.deleteNode(a.get_head(), a.getNode(a.getSize(a.get_head()) - 1, a.get_head()));
    //}
    //for (int i = 0; i < 5; i++)
    //{
    //    Data->coef = i;
    //    a.addBeginning(&a.get_head(), Data);
    //}

    //for (int i = 0; i < 10 ; i++)
    //{
    //    Data->name = "hello";
    //    Data->coef = i;
    //    a.addBeginning(&a.get_head(), Data);
    //}
    //a.MergeSort("coef", &a.get_head());
    //a.printTable(a.get_head());
    
}


