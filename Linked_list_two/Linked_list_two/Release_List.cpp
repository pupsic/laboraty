#include "Linked_LIst.h"
# include <iostream>;
# include <iostream>;
# include <fstream>;
# include <iomanip>;
using namespace std;

int linked_list::GetSize() {
	int count = 0;
	while (head != NULL) {
		count++;
		head = head->next;
	}
	return count;
}


void linked_list::printLine(node* n)
{
	cout << "|" << setw(15) << n->name << "|" << setw(10) << n->type << "|"
		<< setw(7) << n->wet << "|" << setw(14) << n->coef << "|\n";
}

void linked_list::PrintStart() {
	node* cur = head;
	system("cls");
	cout << ("--------------------------------------------------\n");
	cout << ("|Coefficients of thermal conductivity of materials|\n");
	cout << ("|-------------------------------------------------|\n");
	cout << ("|   Substance   |   Type   |  Wet  | Coefficients |\n");
	cout << ("|---------------|----------|-------|--------------|\n");

	while (cur != NULL) {

		printLine(cur);
		cur = cur->next;
	}
	cout << "------------------------------------------------\n";
	system("pause");
}
void linked_list::PrintEnd() {
	node* cur = tail;
	system("cls");
	cout << ("--------------------------------------------------\n");
	cout << ("|Coefficients of thermal conductivity of materials|\n");
	cout << ("|-------------------------------------------------|\n");
	cout << ("|   Substance   |   Type   |  Wet  | Coefficients |\n");
	cout << ("|---------------|----------|-------|--------------|\n");
	while (cur != NULL) {

		printLine(cur);
		cur = cur->prev;
	}
	cout << "------------------------------------------------\n";
	system("pause");
}

void search_collection_end(linked_list a) {

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
			a.searchtTail("str", val);
			break;
		case 1:
			a.searchtTail("char", val);
			break;
		case 2:
			a.searchtTail("int", val);
			break;
		case 3:
			a.searchtTail("double", val);
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
			a.searchHead("str", val );
			break;
		case 1:
			a.searchHead("char", val);
			break;
		case 2:
			a.searchHead("int", val);
			break;
		case 3:
			a.searchHead("double", val);
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

void linked_list::searchtTail(string type, string input)
{

	node* temp = tail;
	system("cls");
	cout << ("--------------------------------------------------\n");
	cout << ("|Coefficients of thermal conductivity of materials|\n");
	cout << ("|-------------------------------------------------|\n");
	cout << ("|   Substance   |   Type   |  Wet  | Coefficients |\n");
	cout << ("|---------------|----------|-------|--------------|\n");
	if (type == "str") {
		for (; temp != NULL; temp = temp->prev)
		{
			if (temp->name == input) {
				printLine(temp);
			}
		}
	}
	if (type == "char") {
		for (; temp != NULL; temp = temp->prev)
		{
			if (temp->type == input[0]) {
				printLine(temp);
			}
		}
	}
	if (type == "int") {
		for (; temp != NULL; temp = temp->prev)
		{
			if (temp->wet == stoi(input)) {
				printLine(temp);
			}
		}
	}

	if (type == "double") {
		for (; temp != NULL; temp = temp->prev)
		{
			if (temp->coef == stod(input)) {
				printLine(temp);
			}
		}
	}
	cout << "------------------------------------------------\n";
	system("pause");
}

void linked_list::searchHead(string type, string input)
{

	node* temp = head;
	system("cls");
	cout << ("--------------------------------------------------\n");
	cout << ("|Coefficients of thermal conductivity of materials|\n");
	cout << ("|-------------------------------------------------|\n");
	cout << ("|   Substance   |   Type   |  Wet  | Coefficients |\n");
	cout << ("|---------------|----------|-------|--------------|\n");
	if (type == "str") {
		for (; temp != NULL; temp = temp->next)
		{
			if (temp->name == input) {
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
			if (temp->wet == stoi(input)) {
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

void linked_list::insert_front(struct node** head)
{
	//allocate memory for New node
	struct node* newNode = new node;

	//assign data to new node
	cout << endl << "Enter substance:";
	cin >> tail->name;
	cout << endl << "Enter type:";
	cin >> tail->type;
	cout << endl << "Enter wet: ";
	cin >> tail->wet;
	cout << endl << "Enter corficient: ";
	cin >> tail->coef;

	//new node is head and previous is null, since we are adding at the front
	newNode->next = (*head);
	newNode->prev = NULL;

	//previous of head is new node
	if ((*head) != NULL)
		(*head)->prev = newNode;

	//head points to new node
	(*head) = newNode;
}


void linked_list::push()
{
p:
	system("cls");
	int count = 0;
	cout << "Enter the number of items: ";
	cin >> count;
	if (count < 1) {
		cout << "The number of elements must be greater than 0!" << endl;
		goto p;
	}
	head = new node();
	tail = head;
	for (int i = 0; i < count; i++) {
		cout << endl << "Enter substance:";
		cin >> tail->name;
		cout << endl << "Enter type:";
		cin >> tail->type;
		cout << endl << "Enter wet: ";
		cin >> tail->wet;
		cout << endl << "Enter corficient: ";
		cin >> tail->coef;
		if (i != count - 1) {
			tail->next = new node();
			tail->next->prev = tail;
			tail = tail->next;
		}
	}

	system("pause");
	return;
}
node* linked_list::getNode(int index, node* head)
{
	// allocating space
	node* nodeByIndex = head;

	for (int step = 0; step < index && nodeByIndex != NULL; step++)
	{

		nodeByIndex = nodeByIndex->next;

	}

	return nodeByIndex;
}
/* Given a node as next_node, insert a new node before the
 * given node */
void linked_list::insertAfter(node* prev_node)
{
	/*1. check if the given next_node is NULL */
	if (prev_node == NULL)
	{
		cout << "the given previous node cannot be NULL";
		return;
	}

	/* 2. allocate new node */
	node* new_node = new node();

	/* 3. put in the data */
	cout << endl << "Enter substance:";
	cin >> new_node->name;
	cout << endl << "Enter type:";
	cin >> new_node->type;
	cout << endl << "Enter wet: ";
	cin >> new_node->wet;
	cout << endl << "Enter corficient: ";
	cin >> new_node->coef;

	/* 4. Make next of new node as next of prev_node */
	new_node->next = prev_node->next;

	/* 5. Make the next of prev_node as new_node */
	prev_node->next = new_node;

	/* 6. Make prev_node as previous of new_node */
	new_node->prev = prev_node;

	/* 7. Change previous of new_node's next node */
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}
void linked_list::deleteNode(node** head_ref,  node* del) {
	if (*head_ref == NULL || del == NULL) {
		return;
	}
	// head node
	if (*head_ref == del) {
		*head_ref = del->next;
	}
	// middle node
	if (del->next != NULL) {
		del->next->prev = del->prev;
	}
	// end node
	if (del->prev != NULL) {
		del->prev->next = del->next;
	}
	free(del);
}
void linked_list::deleteNodeAtGivenPosition( node** head_ref, int n) {
	if (*head_ref == NULL || n <= 0) {
		return;
	}
	struct node* current = *head_ref;
	int i;
	for (int i = 1; current != NULL && i < n; i++) {
		current = current->next;
	}
	if (current == NULL) {
		return;
	}
	deleteNode(head_ref, current);
}

void linked_list::PrintFile() {
	ofstream fout("Output.txt");
	node* cur = head;
	while (cur != NULL) {
		fout << "  " << cur->name << "  " << cur->type << "  " << cur->wet << "  " << cur->coef << "  " << endl;
		cur = cur->next;
	}
	system("cls");
}
void linked_list::ReadFile() {
	head = new node();
	tail = NULL;
	ifstream fin("MasStruct.txt");
	while (!fin.eof()) {
		if (tail == NULL)
			tail = head;
		else {
			tail->next = new node();
			tail->next->prev = tail;
			tail = tail->next;
		}
		fin >> tail->name;
		fin >> tail->type;
		fin >> tail->wet;
		fin >> tail->coef;
	}
	system("cls");

}
void linked_list::bubbleSortCoef(node* start)
{
	int swapped, i;
	struct node* ptr1;
	struct node* lptr = NULL;

	/* Checking for empty list */
	if (start == NULL)
		return;

	do
	{
		swapped = 0;
		ptr1 = start;

		while (ptr1->next != lptr)
		{
			if (ptr1->coef > ptr1->next->coef)
			{
				swap(ptr1->name, ptr1->next->name);
				swap(ptr1->type, ptr1->next->type);
				swap(ptr1->wet, ptr1->next->wet);
				swap(ptr1->coef, ptr1->next->coef);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapped);
}
void linked_list::bubbleSortType(node* start)
{
	int swapped, i;
	struct node* ptr1;
	struct node* lptr = NULL;

	/* Checking for empty list */
	if (start == NULL)
		return;

	do
	{
		swapped = 0;
		ptr1 = start;

		while (ptr1->next != lptr)
		{
			if (ptr1->type > ptr1->next->type)
			{
				swap(ptr1->name, ptr1->next->name);
				swap(ptr1->type, ptr1->next->type);
				swap(ptr1->wet, ptr1->next->wet);
				swap(ptr1->coef, ptr1->next->coef);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapped);
}

void linked_list::bubbleSort(node* start)
{
	int swapped, i;
	struct node* ptr1;
	struct node* lptr = NULL;

	/* Checking for empty list */
	if (start == NULL)
		return;

	do
	{
		swapped = 0;
		ptr1 = start;

		while (ptr1->next != lptr)
		{
			if (ptr1->name > ptr1->next->name)
			{
				swap(ptr1->name, ptr1->next->name);
				swap(ptr1->type, ptr1->next->type);
				swap(ptr1->wet, ptr1->next->wet);
				swap(ptr1->coef, ptr1->next->coef);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}     while (swapped);
}

void linked_list::bubbleSortWet(node* start)
{
	int swapped, i;
	struct node* ptr1;
	struct node* lptr = NULL;

	/* Checking for empty list */
	if (start == NULL)
		return;

	do
	{
		swapped = 0;
		ptr1 = start;

		while (ptr1->next != lptr)
		{
			if (ptr1->wet > ptr1->next->wet)
			{
				swap(ptr1->name, ptr1->next->name);
				swap(ptr1->type, ptr1->next->type);
				swap(ptr1->wet, ptr1->next->wet);
				swap(ptr1->coef, ptr1->next->coef);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapped);
}

void linked_list::sortedInsert(node** head_ref, node* newNode)
{
	struct node* current;

	// if list is empty
	if (*head_ref == NULL)
		*head_ref = newNode;

	// if the node is to be inserted at the beginning
	// of the doubly linked list
	else if ((*head_ref)->type >= newNode->type) {
		newNode->next = *head_ref;
		newNode->next->prev = newNode;
		*head_ref = newNode;
	}

	else {
		current = *head_ref;

		// locate the node after which the new node
		// is to be inserted
		while (current->next != NULL &&
			current->next->type < newNode->type)
			current = current->next;

		/*Make the appropriate links */

		newNode->next = current->next;

		// if the new node is not inserted
		// at the end of the list
		if (current->next != NULL)
			newNode->next->prev = newNode;

		current->next = newNode;
		newNode->prev = current;
	}
}




// function to sort a doubly linked list using insertion sort
void linked_list::insertionSort(node** head_ref)
{
	// Initialize 'sorted' - a sorted doubly linked list
	struct node* sorted = NULL;

	// Traverse the given doubly linked list and
	// insert every node to 'sorted'
	struct node* current = *head_ref;
	while (current != NULL) {

		// Store next for next iteration
		struct node* next = current->next;

		// removing all the links so as to create 'current'
		// as a new node for insertion
		current->prev = current->next = NULL;

		// insert current in 'sorted' doubly linked list
		sortedInsert(&sorted, current);

		// Update current
		current = next;
	}

	// Update head_ref to point to sorted doubly linked list
	*head_ref = sorted;
}