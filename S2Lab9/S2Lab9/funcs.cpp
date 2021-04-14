#include "LIST.h"
#include <string>
#include <iostream>

int id = 0;
void linked_list::printList(node* n)
{
    while (n != NULL) {
        cout << n->wet << " ";
        n = n->next;
    }
}

void linked_list::add_node(string name, char type, unsigned int wet, double coef)
{
    node* tmp = new node;
    tmp->name = name;
    tmp->type = type;
    tmp->wet = wet;
    tmp->coef = coef;
    tmp->next = NULL;
    if (head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
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
    if (head == nullptr) {
        std::cout << std::endl << std::endl;
        std::cout << "\t" << "ll-> the list is empty. deletion not possible.";
        std::cout << std::endl << std::endl;
        return;
    }
    node* temp1 = head;
    node* temp2 = nullptr;
    while (temp1->name != node_location) {
        if (temp1->next == nullptr) {
            std::cout << std::endl << std::endl;
            std::cout << "\t" << "ll-> given node not found. deletion not possible.";
            std::cout << std::endl << std::endl;
            return;
        }
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
    if (head == nullptr) {
        std::cout << std::endl << std::endl;
        std::cout << "\t" << "ll-> the list is empty. deletion not possible.";
        std::cout << std::endl << std::endl;
        return;
    }
    node* temp1 = head;
    node* temp2 = nullptr;
    while (temp1->type != node_location) {
        if (temp1->next == nullptr) {
            std::cout << std::endl << std::endl;
            std::cout << "\t" << "ll-> given node not found. deletion not possible.";
            std::cout << std::endl << std::endl;
            return;
        }
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
    if (head == nullptr) {
        std::cout << std::endl << std::endl;
        std::cout << "\t" << "ll-> the list is empty. deletion not possible.";
        std::cout << std::endl << std::endl;
        return;
    }
    node* temp1 = head;
    node* temp2 = nullptr;
    while (temp1->wet != node_location) {
        if (temp1->next == nullptr) {
            std::cout << std::endl << std::endl;
            std::cout << "\t" << "ll-> given node not found. deletion not possible.";
            std::cout << std::endl << std::endl;
            return;
        }
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
    if (head == nullptr) {
        std::cout << std::endl << std::endl;
        std::cout << "\t" << "ll-> the list is empty. deletion not possible.";
        std::cout << std::endl << std::endl;
        return;
    }
    node* temp1 = head;
    node* temp2 = nullptr;
    while (temp1->coef != node_location) {
        if (temp1->next == nullptr) {
            std::cout << std::endl << std::endl;
            std::cout << "\t" << "ll-> given node not found. deletion not possible.";
            std::cout << std::endl << std::endl;
            return;
        }
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
