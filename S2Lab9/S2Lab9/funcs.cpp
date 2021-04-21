#include "LIST.h"
#include <string>
#include <iostream>
#include <iomanip>

#include <fstream>


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

void writeToFile(linked_list a) {
    char text[200]="fdsafasdf sadf sa";

    fstream file;
    file.open("example.xls", ios::out | ios::in);

    cout << "Write text to be written on file." << endl;
    cin.getline(text, sizeof(text));

    // Writing on file
    file << text << endl;
    
    // Reding from file
    file >> text;
    cout << text << endl;
    file.close();
    system("pause");
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


void linked_list::MergeSort(string byColumn,node** headRef)
{
    node* head = *headRef;
    node* a;
    node* b;

    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);

    /* Recursively sort the sublists */
    MergeSort(byColumn, &a);
    MergeSort(byColumn, &b);

    /* answer = merge the two sorted lists together */
    if (byColumn == "name") {
        *headRef = SortedMergeName(a, b);
    }
    else if(byColumn == "type") {
        *headRef = SortedMergeType(a, b);
    }
    else if (byColumn == "wet") {
        *headRef = SortedMergeWet(a, b);
    }
    else if (byColumn == "coef") {
        *headRef = SortedMergeCoef(a, b);
    }
}


linked_list::node* linked_list::SortedMergeType(node* a, node* b)
{
    node* result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->type <= b->type) {
        result = a;
        result->next = SortedMergeType(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMergeType(a, b->next);
    }
    return (result);
}

linked_list::node* linked_list::SortedMergeWet(node* a, node* b)
{
    node* result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->wet <= b->wet) {
        result = a;
        result->next = SortedMergeWet(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMergeWet(a, b->next);
    }
    return (result);
}

linked_list::node* linked_list::SortedMergeCoef(node* a, node* b)
{
    node* result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->coef <= b->coef) {
        result = a;
        result->next = SortedMergeCoef(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMergeCoef(a, b->next);
    }
    return (result);
}

linked_list::node* linked_list::SortedMergeName(node* a, node* b)
{
    node* result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->name <= b->name) {
        result = a;
        result->next = SortedMergeName(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMergeName(a, b->next);
    }
    return (result);
}


void linked_list::FrontBackSplit(node* source,
    node** frontRef, node** backRef)
{
    node* fast;
    node* slow;
    slow = source;
    fast = source->next;

    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}



linked_list::node* linked_list::getNode(int index, node* head)
{
    // allocating space
    node* nodeByIndex = head;

    for (int step = 0; step < index && nodeByIndex != NULL; step++)
    {

        nodeByIndex = nodeByIndex->next;

    }

    return nodeByIndex;
}


int linked_list::getSize(node*& head) {

    node* copy = head;
    int size = 0;
    while (copy != NULL) {

        copy = copy->next;
        size++;
    }

    return size;
}
void linked_list::printLine(node* n)
{
    cout << "|" << setw(15) << n->name << "|" << setw(10) << n->type << "|"
        << setw(7) << n->wet << "|" << setw(14) << n->coef << "|\n";
}

void linked_list::insert(node* prev_node, data*& Data)
{


    /* 2. allocate new node */
    node* newNode = new node;

    /* 3. put in the data */
    newNode->name = Data->name;
    newNode->type = Data->type;
    newNode->wet = Data->wet;
    newNode->coef = Data->coef;
    newNode->next = NULL;
    /* 4. Make next of new node as next of prev_node */
    newNode->next = prev_node->next;

    /* 5. move the next of prev_node as new_node */
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


void linked_list::addEnd(node** head_ref, data*& Data)
{
    node* newNode = new node;

    node* last = *head_ref; /* used in step 5*/

    /* 2. put in the data */
    newNode->name = Data->name;
    newNode->type = Data->type;
    newNode->wet = Data->wet;
    newNode->coef = Data->coef;
    
    /* 3. This new node is going to be
    the last node, so make next of
    it as NULL*/
    newNode->next = NULL;

    /* 4. If the Linked List is empty,
    then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = newNode;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = newNode;
    return;
}

void linked_list::addBeginning(node** head_ref, data*& Data)
{
    node* newNode = new node;
    newNode->name = Data->name;
    newNode->type = Data->type;
    newNode->wet = Data->wet;
    newNode->coef = Data->coef;

    /* 3. Make next of new node as head */
    newNode->next = (*head_ref);

    /* 4. move the head to point to the new node */
    (*head_ref) = newNode;
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

void linked_list::deleteNode(node* head, node* n)
{
    // When node to be deleted is head node 
    if (head == n)
    {
        if (head->next == NULL)
        {
            cout << "There is only one node." <<
                " The list can't be made empty ";
            return;
        }

        /* Copy the data of next node to head */
        head->name = head->next->name;
        head->type = head->next->type;
        head->wet = head->next->wet;
        head->coef = head->next->coef;
        // store address of next node 
        n = head->next;

        // Remove the link of next node 
        head->next = head->next->next;

        // free memory 
        free(n);

        return;
    }


    // When not first node, follow 
    // the normal deletion process 

    // find the previous node 
    node* prev = head;
    while (prev->next != NULL && prev->next != n)
        prev = prev->next;

    // Check if node really exists in Linked List 
    if (prev->next == NULL)
    {
        cout << "\nGiven node is not present in Linked List";
        return;
    }

    // Remove node from Linked List 
    prev->next = prev->next->next;

    // Free memory 
    free(n);

    return;
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
