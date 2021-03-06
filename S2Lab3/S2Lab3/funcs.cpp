#include "funcs.h"
#include "globals.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime> 
#include <cmath> // ��� round
#include <sstream> 
using namespace std;
HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int exis_struct = 0;

FCT* fct = new FCT[NUM_OF_STRUCT];

string id(int index){
    stringstream ss;
    ss << index;
    string s;
    ss >> s;
    return s;
}

int find_collection(mon* mc, int n) {
    int index = 0;
    SetConsoleTextAttribute(hConsole, 10);
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
        system("cls");
        switch (input)
        {
        case 0:
            index = find_element_name(mc, n);
            break;
        case 1:
            index =find_element_type(mc, n);
            break;
        case 2:
            index = find_element_wet(mc, n);
            break;
        case 3:
            index = find_element_coef(mc, n);
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
    system("cls");
    return index;
}

void full_info(mon* mc, int n,FCT *fct_) {
    system("cls");
    cout << "Number of all elements at the moment: " << n << endl;
    cout << "Number of all existing elements:      " << exis_struct << endl;
    cout << "Time of making element at the moment: " << endl;
    for (int i = 0; i < n; i++)
    {
        char str[26];
        ctime_s(str, sizeof(str), &mc[i].timeinfo);
        cout << setw(12) << mc[i].name << " :";
        cout << ("%s", str);

    }
    cout << "Number of calling functions:          " << endl;
    for (int i = 0; !fct_[i].id.empty(); i++)
    {
        cout<< setw(12) << fct[i].name<<": "<< fct[i].time_called<<endl;
    }
    system("pause");
}


int find_element_name(mon* mc,int n) {

    system("cls");
    string title; //string to store the title of the book that should be removed 
    cout << "Enter the title of the substance you want to find:\n";
    cin >> title;
    system("cls");
    SetConsoleTextAttribute(hConsole, 8);
    cout<<("--------------------------------------------------\n");
    cout << ("|Coefficients of thermal conductivity of materials|\n");
    cout << ("|-------------------------------------------------|\n");
    cout << ("|   Substance   |   Type   |  Wet  | Coefficients |\n");
    cout << ("|---------------|----------|-------|--------------|\n");
    int find = 0;
    for (int i = 0; i < n; i++)
    {
        if (!mc[i].name.find(title)) //if this is the book
        {
            print_line(mc, i);
            find = i;
        }
    }
    cout << "------------------------------------------------\n";
    system("pause");
    return find;
}

void change_element(mon* mc, int n) {
    for (bool status_del = 0; status_del < 1;)
    {
        system("cls");
        SetConsoleTextAttribute(hConsole, 6);
        int  index = find_collection(mc,n);
        SetConsoleTextAttribute(hConsole, 6);
        cout << "0 - change name" << endl;
        cout << "1 - change type" << endl;
        cout << "2 - change wet" << endl;
        cout << "3 - change coefficient" << endl;
        cout << "4 - exit" << endl;
        
        int input;
        cin >> input;
        system("cls");
        switch (input)
        {
        case 0:
            cout << "Enter Substance: ";
            cin >> mc[index].name;
            break;
        case 1:
            cout << "Enter type: ";
            cin >> mc[index].type;
            break;
        case 2:
            cout << "Enter wet: ";
            cin >> mc[index].wet;
            break;
        case 3:
            cout << "Enter coefficient: ";
            cin >> mc[index].coef;
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
}


int find_element_type(mon* mc, int n) {

    system("cls");
    string title; //string to store the title of the book that should be removed 

    cout << "Enter the title of the substance you want to find:\n";
    cin >> title;
    SetConsoleTextAttribute(hConsole, 8);
    system("cls");
    cout << ("--------------------------------------------------\n");
    cout << ("|Coefficients of thermal conductivity of materials|\n");
    cout << ("|-------------------------------------------------|\n");
    cout << ("|   Substance   |   Type   |  Wet  | Coefficients |\n");
    cout << ("|---------------|----------|-------|--------------|\n");
    
    int find = 0;
    for (int i = 0; i < n; i++)
    {
        if (mc[i].type == title) //if this is the book
        {
            print_line(mc, i);
            find = i;
        }
    }
    cout << "------------------------------------------------\n";
    system("pause");
    return find;
}

int find_element_wet(mon* mc, int n) {

    system("cls");
    int title; //string to store the title of the book that should be removed 

    cout << "Enter the title of the substance you want to find:\n";
    cin >> title;
    system("cls");
    SetConsoleTextAttribute(hConsole, 8);
    cout << ("--------------------------------------------------\n");
    cout << ("|Coefficients of thermal conductivity of materials|\n");
    cout << ("|-------------------------------------------------|\n");
    cout << ("|   Substance   |   Type   |  Wet  | Coefficients |\n");
    cout << ("|---------------|----------|-------|--------------|\n");
    int find = 0;
    for (int i = 0; i < n; i++)
    {
        if (mc[i].wet == title) //if this is the book
        {
            print_line(mc, i);
            find = i;
        }
    }
    cout << "------------------------------------------------\n";
    system("pause");
    return find;
}

int find_element_coef(mon* mc, int n) {

    system("cls");
    double title; //string to store the title of the book that should be removed 

    cout << "Enter the title of the substance you want to find:\n";
    cin >> title;
    system("cls");
    SetConsoleTextAttribute(hConsole, 8);
    cout << ("--------------------------------------------------\n");
    cout << ("|Coefficients of thermal conductivity of materials|\n");
    cout << ("|-------------------------------------------------|\n");
    cout << ("|   Substance   |   Type   |  Wet  | Coefficients |\n");
    cout << ("|---------------|----------|-------|--------------|\n");
    int find = 0;
    for (int i = 0; i < n; i++)
    {
        if (mc[i].coef == title) //if this is the book
        {
            print_line(mc, i);
            find = i;
        }
    }
    cout << "------------------------------------------------\n";
    system("pause");
    return find;
}

void print_line(mon* mc, int i){
    SetConsoleTextAttribute(hConsole, 15);
    cout << "|" << setw(15) << mc[i].name << "|" << setw(10) << mc[i].type << "|"
        << setw(7) << mc[i].wet << "|" << setw(14) << mc[i].coef << "|\n";
    SetConsoleTextAttribute(hConsole, 8);
}

int delete_all_stract(mon* mc, int n) {
    system("cls");
    delete [] mc;
    n = 0;
    return n;
}

int delete_stract_by_name(mon* mc, int n) {
    system("cls");
    string title; //string to store the title of the book that should be removed 
    SetConsoleTextAttribute(hConsole, 4);
    cout << "Enter the title of the substance you want to delete:\n";
    cin >> title;
    for (int i = 0; i < n; i++)
    {
        if (mc[i].name == title) //if this is the book
        {
            //go through all books and place them one place back
            for (int j = i; j < n - 1; j++)
            {
                mc[j].name = mc[j + 1].name;
                mc[j].type = mc[j + 1].type;
                mc[j].wet = mc[j + 1].wet;
                mc[j].coef = mc[j + 1].coef;
                
            }
            system("cls");
            n--; //one book is deleted; substract one from size
            //break; //break out the loop
        }
    }
    int index = 1;

    return n;
}

int delete_stract_by_type(mon* mc, int n) {
    system("cls");
    string title; //string to store the title of the book that should be removed 
    SetConsoleTextAttribute(hConsole, 8);
    cout << "Enter the type of the substance you want to delete:\n";
    cin >> title;
    for (int i = 0; i < n; i++)
    {
        if (mc[i].type == title)
        {
            for (int j = i; j < n - 1; j++)
            {
                mc[j].name = mc[j + 1].name;
                mc[j].type = mc[j + 1].type;
                mc[j].wet = mc[j + 1].wet;
                mc[j].coef = mc[j + 1].coef;

            }
            system("cls");
            n--;
        }
    }
    return n;
}

int delete_stract_by_wet(mon* mc, int n) {
    system("cls");
    int title; //string to store the title of the book that should be removed 
    SetConsoleTextAttribute(hConsole, 8);
    cout << "Enter the value of the wet you want to delete:\n";
    cin >> title;
    for (int i = 0; i < n; i++)
    {
        if (mc[i].wet == title) //if this is the book
        {

            //go through all books and place them one place back
            for (int j = i; j < n - 1; j++)
            {
                mc[j].name = mc[j + 1].name;
                mc[j].type = mc[j + 1].type;
                mc[j].wet = mc[j + 1].wet;
                mc[j].coef = mc[j + 1].coef;

            }
            system("cls");
            n--; //one book is deleted; substract one from size
            //break; //break out the loop
        }
    }

    return n;
}

int delete_stract_by_coefficient(mon* mc, int n) {
    system("cls");
    double title; //string to store the title of the book that should be removed 
    SetConsoleTextAttribute(hConsole, 8);
    cout << "Enter the value of coefficient you want to delete:\n";
    cin >> title;
    for (int i = 0; i < n; i++)
    {
        if (mc[i].coef == title) //if this is the book
        {
            
            //go through all books and place them one place back
            for (int  j = i; j < n - 1; j++)
            {
                mc[j].name = mc[j + 1].name;
                mc[j].type = mc[j + 1].type;
                mc[j].wet = mc[j + 1].wet;
                mc[j].coef = mc[j + 1].coef;

            }
            system("cls");
            n--; //one book is deleted; substract one from size
            //break; //break out the loop
            
        }
    }
    return n;
}


int enter_keyboard(mon* mc, int n)
{
    SetConsoleTextAttribute(hConsole, 10);
    system("cls");
    for (n; ; n++)
    {
        cout << "To stop typing, enter '<'" << endl;
        cout << "Enter Substance: ";
        cin >> mc[n].name;
        if (mc[n].name == "<") break;
        cout << "\nEnter type: ";
        cin >> mc[n].type;
        cout << "\nEnter wet: ";
        cin >> mc[n].wet;
        cout << "\nEnter coefficient: ";
        cin >> mc[n].coef;
        system("cls");
    }

    return n;
}

int enter_random(mon* mc, int n)
{

    srand(time(NULL));
    string myText;
    ifstream MyReadFile("name_of_sub.txt");
    int i = 0;
    for (; getline(MyReadFile, myText); i++)
        ;
    MyReadFile.close();

    ifstream MyReadFile1("name_of_sub.txt");
    string myText1;
    int rand_sub = 1 + rand() % i;

    for (int j=0; j<= rand_sub; j++)
    {
        getline(MyReadFile1, myText1);
    }
    mc[n].name = myText1;
    MyReadFile1.close();

    mc[n].type = rand() % 25 + 65;
    mc[n].wet = rand() % 100 + 0;
    float a = 1000.0;
    double temp = (float(rand()) / float((RAND_MAX)) * a);
    mc[n].coef = round(temp * 1000) / 1000;
    
    n++;
    return n;
}

void print(mon* mc, int n)
{
    system("cls");
    SetConsoleTextAttribute(hConsole, 8);
    cout << ("--------------------------------------------------\n");
    cout << ("|Coefficients of thermal conductivity of materials|\n");
    cout << ("|-------------------------------------------------|\n");
    cout << ("|   Substance   |   Type   |  Wet  | Coefficients |\n");
    cout << ("|---------------|----------|-------|--------------|\n");
    for (int i = 0; i < n; i++)
    {

        print_line(mc, i);
    }
    cout << "--------------------------------------------------\n";
    system("pause");

}

void sortirovka_by_name_down(mon* mc, int n)
{
    mon temp;
    int m;
    for (int i = 0; i < n - 1; i++) {
        m = i; /* ����������� ������� - ������ */
        for (int j = i + 1; j < n; j++)
            /* ���� ������� ������� < ������������,
               �� ���������� ����������� */
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

void sortirovka_by_type_down(mon* mc, int n)
{
    mon temp;
    int m;
    for (int i = 0; i < n - 1; i++) {
        m = i; /* ����������� ������� - ������ */
        for (int j = i + 1; j < n; j++)
            /* ���� ������� ������� < ������������,
               �� ���������� ����������� */
            if (mc[m].type > mc[j].type)
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

void sortirovka_by_wet_down(mon* mc, int n)
{
    mon temp;
    int m;
    for (int i = 0; i < n - 1; i++) {
        m = i; /* ����������� ������� - ������ */
        for (int j = i + 1; j < n; j++)
            /* ���� ������� ������� < ������������,
               �� ���������� ����������� */
            if (mc[m].wet > mc[j].wet)
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

void sortirovka_by_coef_down(mon* mc, int n)
{
    mon temp;
    int m;
    for (int i = 0; i < n - 1; i++) {
        m = i; /* ����������� ������� - ������ */
        for (int j = i + 1; j < n; j++)
            /* ���� ������� ������� < ������������,
               �� ���������� ����������� */
            if (mc[m].coef > mc[j].coef)
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

void sortirovka_by_name_up(mon* mc, int n)
{
    mon temp;
    int m;
    for (int i = 0; i < n - 1; i++) {
        m = i; /* ����������� ������� - ������ */
        for (int j = i + 1; j < n; j++)
            /* ���� ������� ������� < ������������,
               �� ���������� ����������� */
            if (mc[m].name < mc[j].name)
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

void sortirovka_by_type_up(mon* mc, int n)
{
    mon temp;
    int m;
    for (int i = 0; i < n - 1; i++) {
        m = i; /* ����������� ������� - ������ */
        for (int j = i + 1; j < n; j++)
            /* ���� ������� ������� < ������������,
               �� ���������� ����������� */
            if (mc[m].type < mc[j].type)
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

void sortirovka_by_wet_up(mon* mc, int n)
{
    mon temp;
    int m;
    for (int i = 0; i < n - 1; i++) {
        m = i; /* ����������� ������� - ������ */
        for (int j = i + 1; j < n; j++)
            /* ���� ������� ������� < ������������,
               �� ���������� ����������� */
            if (mc[m].wet < mc[j].wet)
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

void sortirovka_by_coef_up(mon* mc, int n)
{
    mon temp;
    int m;
    for (int i = 0; i < n - 1; i++) {
        m = i; /* ����������� ������� - ������ */
        for (int j = i + 1; j < n; j++)
            /* ���� ������� ������� < ������������,
               �� ���������� ����������� */
            if (mc[m].coef < mc[j].coef)
            {
                m = j;
            }
        if (m > i) {
            temp = mc[i];
            mc[i] = mc[m];
            mc[m] = temp;
        }
    }
    int index = 5;

}
