#include "funcs.h"
#include "globals.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime> 
#include<sstream> 
using namespace std;

int exis_struct = 0;

FCT* fct = new FCT[NUM_OF_STRUCT];

string id(int index){
    stringstream ss;
    ss << index;
    string s;
    ss >> s;
    return s;
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
        printf("%s", str);
    }
    for (int i = 0; !fct_[i].id.empty(); i++)
    {
        cout<<fct[i].name<<' '<< fct[i].time_called<<endl;
    }
    system("pause");
}


void find_element(mon* mc,int n) {

    system("cls");
    string title; //string to store the title of the book that should be removed 

    cout << "Enter the title of the substance you want to find:\n";
    cin >> title;
    system("cls");
    printf("--------------------------------------------------\n");
    printf("|Coefficients of thermal conductivity of materials|\n");
    printf("|-------------------------------------------------|\n");
    printf("|   Substance   |   Type   |  Wet  | Coefficients |\n");
    printf("|---------------|----------|-------|--------------|\n");   
    for (int i = 0; i < n; i++)
    {
        if (mc[i].name == title) //if this is the book
        {

            cout << "|" << setw(15) << mc[i].name << "|" << setw(10) << mc[i].type << "|"
                << setw(7) << mc[i].wet << "|" << setw(14) << mc[i].coef << "|\n";

        }
    }
    cout << "------------------------------------------------\n";
    int index = 0;
    fct[index].id = id(index);
    fct[index].name = "find_element";
    fct[index].time_called++;
    system("pause");
}


int delete_stract(mon* mc, int n) {
    system("cls");
    string title; //string to store the title of the book that should be removed 
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
                
            }
            system("cls");
            n--; //one book is deleted; substract one from size
            //break; //break out the loop
        }
    }
    int index = 1;
    fct[index].id = id(index);
    fct[index].name = "delete_stract";
    fct[index].time_called++;
    return n;
}


int enter_keyboard(mon* mc, int n)
{

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

    int index = 2;
    fct[index].id = id(index);
    fct[index].name = "enter_keyboard";
    fct[index].time_called++;

    exis_struct++;
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
    mc[n].coef = (float(rand()) / float((RAND_MAX)) * a);
    
    time_t result = time(NULL);
    mc[n].timeinfo = result;

    exis_struct++;
    n++;
    int index = 3;
    fct[index].id = id(index);
    fct[index].name = "enter_random";
    fct[index].time_called++;

    return n;
}

void print(mon* mc, int n)
{
    system("cls");

    printf("--------------------------------------------------\n");
    printf("|Coefficients of thermal conductivity of materials|\n");
    printf("|-------------------------------------------------|\n");
    printf("|   Substance   |   Type   |  Wet  | Coefficients |\n");
    printf("|---------------|----------|-------|--------------|\n");
    for (int i = 0; i < n; i++)
    {
        cout << "|" << setw(15) << mc[i].name << "|" << setw(10) << mc[i].type << "|"
            << setw(7) << mc[i].wet << "|" << setw(14) << mc[i].coef << "|\n";
    }
    cout << "--------------------------------------------------\n";
    system("pause");

    int index = 4;
    fct[index].id = id(index);
    fct[index].name = "print";
    fct[index].time_called++;
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
    int index = 5;
    fct[index].id = id(index);
    fct[index].name = "sortirovka";
    fct[index].time_called++;

}