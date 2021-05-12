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

void linked_list::frontBackSplit(node* theHead, node*& frontRef, node*& backRef)
{
	node* fast;
	node* slow;

	// If the list is empty, both front and back points to null
	// If there is only one element, front points to it and back points
	//  to null.
	if (theHead == nullptr || theHead->next == nullptr) {
		frontRef = theHead;
		backRef = nullptr;
	}
	else {
		slow = theHead;
		fast = theHead->next;

		// Fast advances 2 nodes while slow advances 1 node
		while (fast != nullptr) {
			fast = fast->next;

			if (fast != nullptr) {
				slow = slow->next;
				fast = fast->next;
			}
		}

		// slow should be pointing right before midpoint. Split at this point
		frontRef = theHead;
		backRef = slow->next;

		// Update the prev and next pointers
		backRef->prev = nullptr;
		slow->next = nullptr;
	}
}


void linked_list::sort(node*& theHead)
{
	node* a = nullptr;
	node* b = nullptr;

	// Base case
	if (theHead == nullptr || theHead->next == nullptr) {
		return;
	}

	// Split the list in half
	// For odd number of nodes, the extra node will be in the first half.
	frontBackSplit(theHead, a, b);

	// Recursively break the list down until the sublist contains 1 element (Sorted)
	sort(a);
	sort(b);

	// Merge the two sorted lists
	theHead = sortedMerge(a, b);
}


node* linked_list::sortedMerge(node* a, node* b)
{
	node* headOfMerged;

	// If one of the node is nullptr, return the other node
	// No merging occurs this this case
	if (a == nullptr) {
		return b;
	}
	else if (b == nullptr) {
		return a;
	}

	// First element in list, a, is less than the first element in b
	if (a->name <= b->name) {
		headOfMerged = a;

		while (b != nullptr) {
			if (a->name <= b->name) {
				if (a->next == nullptr) {
					a->next = b;
					b->prev = a;
					break;
				}
				a = a->next;
			}
			else {
				node* toAdd = b;
				b = b->next;
				toAdd->prev = a->prev;
				a->prev->next = toAdd;
				toAdd->next = a;
				a->prev = toAdd;
			}
		}
	}
	// First element in list, b, is less than the first element in a
	else {
		headOfMerged = b;

		while (a != nullptr) {
			if (b->name <= a->name) {
				if (b->next == nullptr) {
					b->next = a;
					a->prev = b;
					break;
				}
				b = b->next;
			}
			else {
				node* toAdd = a;
				a = a->next;
				toAdd->prev = b->prev;
				b->prev->next = toAdd;
				toAdd->next = b;
				b->prev = toAdd;
			}
		}
	}

	return headOfMerged;
}


void linked_list::sort()
{
	sort(head);

	// After the merge sort, tail pointer will be pointing to incorrect node
	// Update the tail (*** Need a better way to update tail ***)
	node* findTail = head;
	while (findTail != nullptr) {
		if (findTail->next == nullptr) {
			tail = findTail;
		}

		findTail = findTail->next;
	}
}




/// ////////////////////////////////////////////////////////////////////////



void linked_list::frontBackSplitType(node* theHead, node*& frontRef, node*& backRef)
{
	node* fast;
	node* slow;

	// If the list is empty, both front and back points to null
	// If there is only one element, front points to it and back points
	//  to null.
	if (theHead == nullptr || theHead->next == nullptr) {
		frontRef = theHead;
		backRef = nullptr;
	}
	else {
		slow = theHead;
		fast = theHead->next;

		// Fast advances 2 nodes while slow advances 1 node
		while (fast != nullptr) {
			fast = fast->next;

			if (fast != nullptr) {
				slow = slow->next;
				fast = fast->next;
			}
		}

		// slow should be pointing right before midpoint. Split at this point
		frontRef = theHead;
		backRef = slow->next;

		// Update the prev and next pointers
		backRef->prev = nullptr;
		slow->next = nullptr;
	}
}


void linked_list::sortType(node*& theHead)
{
	node* a = nullptr;
	node* b = nullptr;

	// Base case
	if (theHead == nullptr || theHead->next == nullptr) {
		return;
	}

	// Split the list in half
	// For odd number of nodes, the extra node will be in the first half.
	frontBackSplitType(theHead, a, b);

	// Recursively break the list down until the sublist contains 1 element (Sorted)
	sortType(a);
	sortType(b);

	// Merge the two sorted lists
	theHead = sortedMergeType(a, b);
}


node* linked_list::sortedMergeType(node* a, node* b)
{
	node* headOfMerged;

	// If one of the node is nullptr, return the other node
	// No merging occurs this this case
	if (a == nullptr) {
		return b;
	}
	else if (b == nullptr) {
		return a;
	}

	// First element in list, a, is less than the first element in b
	if (a->type <= b->type) {
		headOfMerged = a;

		while (b != nullptr) {
			if (a->type <= b->type) {
				if (a->next == nullptr) {
					a->next = b;
					b->prev = a;
					break;
				}
				a = a->next;
			}
			else {
				node* toAdd = b;
				b = b->next;
				toAdd->prev = a->prev;
				a->prev->next = toAdd;
				toAdd->next = a;
				a->prev = toAdd;
			}
		}
	}
	// First element in list, b, is less than the first element in a
	else {
		headOfMerged = b;

		while (a != nullptr) {
			if (b->type <= a->type) {
				if (b->next == nullptr) {
					b->next = a;
					a->prev = b;
					break;
				}
				b = b->next;
			}
			else {
				node* toAdd = a;
				a = a->next;
				toAdd->prev = b->prev;
				b->prev->next = toAdd;
				toAdd->next = b;
				b->prev = toAdd;
			}
		}
	}

	return headOfMerged;
}


void linked_list::sortType()
{
	sortType(head);

	// After the merge sort, tail pointer will be pointing to incorrect node
	// Update the tail (*** Need a better way to update tail ***)
	node* findTail = head;
	while (findTail != nullptr) {
		if (findTail->next == nullptr) {
			tail = findTail;
		}

		findTail = findTail->next;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void linked_list::frontBackSplitWet(node* theHead, node*& frontRef, node*& backRef)
{
	node* fast;
	node* slow;

	// If the list is empty, both front and back points to null
	// If there is only one element, front points to it and back points
	//  to null.
	if (theHead == nullptr || theHead->next == nullptr) {
		frontRef = theHead;
		backRef = nullptr;
	}
	else {
		slow = theHead;
		fast = theHead->next;

		// Fast advances 2 nodes while slow advances 1 node
		while (fast != nullptr) {
			fast = fast->next;

			if (fast != nullptr) {
				slow = slow->next;
				fast = fast->next;
			}
		}

		// slow should be pointing right before midpoint. Split at this point
		frontRef = theHead;
		backRef = slow->next;

		// Update the prev and next pointers
		backRef->prev = nullptr;
		slow->next = nullptr;
	}
}


void linked_list::sortWet(node*& theHead)
{
	node* a = nullptr;
	node* b = nullptr;

	// Base case
	if (theHead == nullptr || theHead->next == nullptr) {
		return;
	}

	// Split the list in half
	// For odd number of nodes, the extra node will be in the first half.
	frontBackSplitWet(theHead, a, b);

	// Recursively break the list down until the sublist contains 1 element (Sorted)
	sortWet(a);
	sortWet(b);

	// Merge the two sorted lists
	theHead = sortedMergeWet(a, b);
}


node* linked_list::sortedMergeWet(node* a, node* b)
{
	node* headOfMerged;

	// If one of the node is nullptr, return the other node
	// No merging occurs this this case
	if (a == nullptr) {
		return b;
	}
	else if (b == nullptr) {
		return a;
	}

	// First element in list, a, is less than the first element in b
	if (a->wet <= b->wet) {
		headOfMerged = a;

		while (b != nullptr) {
			if (a->wet <= b->wet) {
				if (a->next == nullptr) {
					a->next = b;
					b->prev = a;
					break;
				}
				a = a->next;
			}
			else {
				node* toAdd = b;
				b = b->next;
				toAdd->prev = a->prev;
				a->prev->next = toAdd;
				toAdd->next = a;
				a->prev = toAdd;
			}
		}
	}
	// First element in list, b, is less than the first element in a
	else {
		headOfMerged = b;

		while (a != nullptr) {
			if (b->wet <= a->wet) {
				if (b->next == nullptr) {
					b->next = a;
					a->prev = b;
					break;
				}
				b = b->next;
			}
			else {
				node* toAdd = a;
				a = a->next;
				toAdd->prev = b->prev;
				b->prev->next = toAdd;
				toAdd->next = b;
				b->prev = toAdd;
			}
		}
	}

	return headOfMerged;
}


void linked_list::sortWet()
{
	sortWet(head);

	// After the merge sort, tail pointer will be pointing to incorrect node
	// Update the tail (*** Need a better way to update tail ***)
	node* findTail = head;
	while (findTail != nullptr) {
		if (findTail->next == nullptr) {
			tail = findTail;
		}

		findTail = findTail->next;
	}
}



/////////////////////////////////////////////////////////////////////////////////////////////////////


void linked_list::frontBackSplitCoef(node* theHead, node*& frontRef, node*& backRef)
{
	node* fast;
	node* slow;

	// If the list is empty, both front and back points to null
	// If there is only one element, front points to it and back points
	//  to null.
	if (theHead == nullptr || theHead->next == nullptr) {
		frontRef = theHead;
		backRef = nullptr;
	}
	else {
		slow = theHead;
		fast = theHead->next;

		// Fast advances 2 nodes while slow advances 1 node
		while (fast != nullptr) {
			fast = fast->next;

			if (fast != nullptr) {
				slow = slow->next;
				fast = fast->next;
			}
		}

		// slow should be pointing right before midpoint. Split at this point
		frontRef = theHead;
		backRef = slow->next;

		// Update the prev and next pointers
		backRef->prev = nullptr;
		slow->next = nullptr;
	}
}


void linked_list::sortPopulation(node*& theHead)
{
	node* a = nullptr;
	node* b = nullptr;

	// Base case
	if (theHead == nullptr || theHead->next == nullptr) {
		return;
	}

	// Split the list in half
	// For odd number of nodes, the extra node will be in the first half.
	frontBackSplitCoef(theHead, a, b);

	// Recursively break the list down until the sublist contains 1 element (Sorted)
	sortPopulation(a);
	sortPopulation(b);

	// Merge the two sorted lists
	theHead = sortedMergeCoef(a, b);
}


node* linked_list::sortedMergeCoef(node* a, node* b)
{
	node* headOfMerged;

	// If one of the node is nullptr, return the other node
	// No merging occurs this this case
	if (a == nullptr) {
		return b;
	}
	else if (b == nullptr) {
		return a;
	}

	// First element in list, a, is less than the first element in b
	if (a->coef <= b->coef) {
		headOfMerged = a;

		while (b != nullptr) {
			if (a->coef <= b->coef) {
				if (a->next == nullptr) {
					a->next = b;
					b->prev = a;
					break;
				}
				a = a->next;
			}
			else {
				node* toAdd = b;
				b = b->next;
				toAdd->prev = a->prev;
				a->prev->next = toAdd;
				toAdd->next = a;
				a->prev = toAdd;
			}
		}
	}
	// First element in list, b, is less than the first element in a
	else {
		headOfMerged = b;

		while (a != nullptr) {
			if (b->coef <= a->coef) {
				if (b->next == nullptr) {
					b->next = a;
					a->prev = b;
					break;
				}
				b = b->next;
			}
			else {
				node* toAdd = a;
				a = a->next;
				toAdd->prev = b->prev;
				b->prev->next = toAdd;
				toAdd->next = b;
				b->prev = toAdd;
			}
		}
	}

	return headOfMerged;
}


void linked_list::sortCoef()
{
	sortPopulation(head);

	// After the merge sort, tail pointer will be pointing to incorrect node
	// Update the tail (*** Need a better way to update tail ***)
	node* findTail = head;
	while (findTail != nullptr) {
		if (findTail->next == nullptr) {
			tail = findTail;
		}

		findTail = findTail->next;
	}
}