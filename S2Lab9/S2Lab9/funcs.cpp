#include "LIST.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

void search_collection(linked_list a) {

    for (bool status_find = 0; status_find < 1;)
    {
        system("cls");
        cout << "0 - find by name" << endl;
        cout << "1 - find by type" << endl;
        cout << "2 - find by wet" << endl;
        cout << "3 - find by coef" << endl;
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
            a.search("str", val, a.get_head());
            break;
        case 1:
            a.search("char", val, a.get_head());
            break;
        case 2:
            a.search("int", val, a.get_head());
            break;
        case 3:
            a.search("double", val, a.get_head());
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

}


void linked_list::search(string type,string input, node* head)
{
    messageErrorEmpty(head);
    node* temp = head;
    system("cls");
    cout << ("--------------------------------------------------\n");
    cout << ("|Coefficients of thermal conductivity of materials|\n");
    cout << ("|-------------------------------------------------|\n");
    cout << ("|   Substance   |   Type   |  Wet  | Coefficients |\n");
    cout << ("|---------------|----------|-------|--------------|\n");
    if (type == "str") {
        for (; temp!=NULL; temp = temp->next)
        {
            if (temp->name==input) {
                printLine(temp);
            }           
        }
    }
    if (type == "char") {
        for (; temp != NULL; temp = temp->next)
        {
            if (temp->type == input[0]) {
                printLine(temp);
            }
        }
    }
    if (type == "int") {
        for (; temp != NULL; temp = temp->next)
        {
            if (temp->wet== stoi(input)) {
                printLine(temp);
            }
        }
    }
    
    if (type == "double") {
        for (; temp != NULL; temp = temp->next)
        {
            if (temp->coef == stod(input)) {
                printLine(temp);
            }
        }
    }
    cout << "------------------------------------------------\n";
    system("pause");
}

void linked_list::printTable(node* n) {
    system("cls");
    cout << ("--------------------------------------------------\n");
    cout << ("|Coefficients of thermal conductivity of materials|\n");
    cout << ("|-------------------------------------------------|\n");
    cout << ("|   Substance   |   Type   |  Wet  | Coefficients |\n");
    cout << ("|---------------|----------|-------|--------------|\n");
    while (n != NULL) {
        printLine(n);
        n = n->next;
    }
    cout << "------------------------------------------------\n";
    system("pause");
}

linked_list::node* linked_list::getNode(int id, node*& n) {

    node*& copy = n;
    for (int i = 0; i < id; i++)
    {
        if (copy != NULL) {
            copy = copy->next;
        }
    }
    return copy;
}
void linked_list::printLine(node* n)
{
    cout << "|" << setw(15) << n->name << "|" << setw(10) << n->type << "|"
        << setw(7) << n->wet << "|" << setw(14) << n->coef << "|\n";
}

void linked_list::insert(node* prev_node,data*& Data){
    node* newNode = new node;
    newNode->name = Data->name;
    newNode->type = Data->type;
    newNode->wet = Data->wet;
    newNode->coef = Data->coef;


    if (head == NULL)
    {
        cout << "Not exist node";
        return;
    }
    else if (prev_node == NULL)
    {
        cout << "the given previous node cannot be NULL";
        return;
    }

    newNode->next = prev_node->next;
    prev_node->next = newNode;
    



    
    
}

void linked_list::addNode(data*& Data)
{
    node* newNode = new node;
    newNode->name = Data->name;
    newNode->type = Data->type;
    newNode->wet =  Data->wet;
    newNode->coef = Data->coef;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = tail->next;
    }
}


void linked_list::addEnd(data*& Data, node*& head, node*& tail)
{
    node* newNode = new node;
    newNode->name = Data->name;
    newNode->type = Data->type;
    newNode->wet = Data->wet;
    newNode->coef = Data->coef;
    newNode->next = nullptr;
    if (head == nullptr) head = tail = newNode;
    else { 
        tail->next = newNode;
        tail = newNode;
    }
}

void linked_list::addBeginning(data*& Data, node*& head, node*& tail)
{
    node* newNode = new node;
    newNode->name = Data->name;
    newNode->type = Data->type;
    newNode->wet = Data->wet;
    newNode->coef = Data->coef;
    if (head == nullptr) {
        newNode->next = nullptr;
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}



void linked_list::messageErrorEmpty(node*& head) {
    if (head == nullptr) {
        std::cout << std::endl << std::endl;
        std::cout << "\t" << "ll-> the list is empty. deletion not possible.";
        std::cout << std::endl << std::endl;
        return;
    }
}

void linked_list::messageErrorFound(node*& node) {
    if (node->next == nullptr) {
        std::cout << std::endl << std::endl;
        std::cout << "\t" << "ll-> given node not found. deletion not possible.";
        std::cout << std::endl << std::endl;
        return;
    }
}

void linked_list::deleteBeginning(node*& head)
{
    if (head == nullptr) {
        std::cout << std::endl << std::endl;
        std::cout << "\t" << "LL-> The List Is Empty. Deletion Not Possible.";
        std::cout << std::endl << std::endl;
        return;
    }
    node* temp = head;
    if (temp->next == nullptr) {
        head = nullptr;
        delete temp;
    }
    else {
        head = head->next;
        delete temp;
    }

}

void linked_list::deleteEnd(node*& head, node*& tail)
{
    if (head == nullptr) {
        std::cout << std::endl << std::endl;
        std::cout << "\t" << "LL-> The List Is Empty. Deletion Not Possible.";
        std::cout << std::endl << std::endl;
        return;
    }
    node* temp = head;
    if (temp->next == nullptr) {
        head = nullptr;
        delete temp;
    }
    else {
        while (temp->next != tail) temp = temp->next;
        tail = temp;
        temp = temp->next;
        tail->next = nullptr;
        delete temp;
    }
}

void linked_list::deleteSpecificName(string node_location, node*& head, node*& tail)
{
    messageErrorEmpty(head);
    node* temp1 = head;
    node* temp2 = nullptr;
    while (temp1->name != node_location) {
        messageErrorFound(temp1);
        temp2 = temp1;
        temp1 = temp1->next;
    }    

    if (head == temp1 && tail == temp1) {
        head = nullptr;
        delete temp1;
    }
    else if (temp1 == head) {
        head = head->next;
        delete temp1;
    }
    else if (temp1 == tail) {
        temp2->next = nullptr;
        tail = temp2;
        delete temp1;
    }
    else {
        temp2->next = temp1->next;
        delete temp1;
    }
}

void linked_list::deleteSpecificType(char node_location, node*& head, node*& tail)
{
    messageErrorEmpty(head);
    node* temp1 = head;
    node* temp2 = nullptr;
    while (temp1->type != node_location) {
        messageErrorFound(temp1);
        temp2 = temp1;
        temp1 = temp1->next;
    }

    if (head == temp1 && tail == temp1) {
        head = nullptr;
        delete temp1;
    }
    else if (temp1 == head) {
        head = head->next;
        delete temp1;
    }
    else if (temp1 == tail) {
        temp2->next = nullptr;
        tail = temp2;
        delete temp1;
    }
    else {
        temp2->next = temp1->next;
        delete temp1;
    }
}

void linked_list::deleteSpecificWet(unsigned int node_location, node*& head, node*& tail)
{
    messageErrorEmpty(head);
    node* temp1 = head;
    node* temp2 = nullptr;
    while (temp1->wet != node_location) {
        messageErrorFound(temp1);
        temp2 = temp1;
        temp1 = temp1->next;
    }

    if (head == temp1 && tail == temp1) {
        head = nullptr;
        delete temp1;
    }
    else if (temp1 == head) {
        head = head->next;
        delete temp1;
    }
    else if (temp1 == tail) {
        temp2->next = nullptr;
        tail = temp2;
        delete temp1;
    }
    else {
        temp2->next = temp1->next;
        delete temp1;
    }
}

void linked_list::deleteSpecificCoef(double node_location, node*& head, node*& tail)
{
    messageErrorEmpty(head);
    node* temp1 = head;
    node* temp2 = nullptr;
    while (temp1->coef != node_location) {
        messageErrorFound(temp1);
        temp2 = temp1;
        temp1 = temp1->next;
    }

    if (head == temp1 && tail == temp1) {
        head = nullptr;
        delete temp1;
    }
    else if (temp1 == head) {
        head = head->next;
        delete temp1;
    }
    else if (temp1 == tail) {
        temp2->next = nullptr;
        tail = temp2;
        delete temp1;
    }
    else {
        temp2->next = temp1->next;
        delete temp1;
    }
}
