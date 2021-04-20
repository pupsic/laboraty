#include <iostream>
#include"LIST.h"
#include <string>
#include <cmath>
using namespace std;

void call_menu() {
    cout << "0 -" << "Manual list entry" << endl;
    cout << "1 -" << "File list entry" << endl;
    cout << "2 -" << "Sort" << endl;
    cout << "3 -" << "Print" << endl;
    cout << "4 -" << "Find element" << endl;
    cout << "5 -" << "Delete" << endl;
    cout << "6 -" << "Exit" << endl;
}

int main()
{
    int i = 0;
    linked_list a;
    linked_list::data* Data = new linked_list::data;
    /*for (bool status = 0; status < 1;)
    {
        system("cls");
        call_menu();*/

    //    int input;
    //    cin >> input;
    //    switch (input)
    //    {
    //    case 0:
    //        for (bool status_find = 0; status_find < 1;)
    //        {
    //            system("cls");
    //            cout << "0 - add to start" << endl;
    //            cout << "1 - add to end" << endl;
    //            cout << "2 - add node" << endl;
    //            cout << "3 - add to any place" << endl;
    //            cout << "4 - exit" << endl;
    //            int input;
    //            cin >> input;
    //            system("cls");

    //            string val;
    //            /*cout << "input Data: " << endl;
    //            cin >> Data->name;
    //            cin >> Data->type;
    //            cin >> Data->wet;
    //            cin >> Data->coef;*/
    //            
    //            Data->coef = i;
    //            a.addNode(Data);
    //            i++;


    //            system("cls");
    //            switch (input)
    //            {
    //            case 0:

    //                a.addBeginning(Data,a.get_head(),a.get_tail());
    //                break;
    //            case 1:
    //                a.addEnd(Data, a.get_head(), a.get_tail());
    //                break;
    //            case 2:
    //                a.addNode(Data);
    //                break;
    //            case 3:
    //                cout << "input id of place: " << endl;
    //                int id;
    //                cin >> id;
    //                if (id==0)
    //                {
    //                    a.addBeginning(Data, a.get_head(), a.get_tail());
    //                }else
    //                { 
    //                    id--;
    //                    a.insert(a.getNode(id, a.get_head()), Data); 
    //                }
    //                

    //                break;
    //            case 4:
    //                status_find = 1;
    //                break;
    //            default:
    //                cout << "Error";
    //                system("pause");
    //                break;
    //            }
    //            break;
    //        }
    //        system("cls");
    //        break;
    //    case 1:

    //        break;
    //    case 2:


    //        break;
    //    case 3:
    //        a.printTable(a.get_head());
    //        break;
    //    case 4:
    //        search_collection(a);
    //        break;
    //    case 5:

    //        break;
    //    case 6:
    //        status = 1;
    //        break;
    //    default:
    //        cout << "Error";
    //        system("pause");
    //        break;
    //    }
    //}
    

    for (int i = 0; i < 5; i++)
    {
        Data->coef = i;
        a.addBeginning(&a.get_head(), Data);
    }
    Data->coef = 7;

    a.insert(a.getNode(5, a.get_head()),Data);
    for (int i = 0; i < 5; i++)
    {
        Data->coef = i;
        a.addEnd(&a.get_head(), Data);
    }
   // a.printTable(a.get_head());
    
}


