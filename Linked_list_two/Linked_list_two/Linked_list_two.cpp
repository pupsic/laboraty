# include <iostream>;
# include <iostream>;
# include <fstream>;
# include <iomanip>;
#include "Linked_LIst.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	linked_list* list = NULL;
	int count = 0;
dd:
	int n = 0;
	system("cls");
	cout << "1- Create a list" << endl;
	cout << "2- Print the list beginning" << endl;
	cout << "3- Print the list end" << endl;
	cout << "4- Search by criteria beginning list" << endl;
	cout << "5- Search by criteria end list" << endl;
	cout << "6- Add node" << endl;
	cout << "7- Deleting node" << endl;
	cout << "8- Sort." << endl;
	cout << "9- Write a new list to a file." << endl;
	cout << "10- Print a new list from a file." << endl;
	cout << "11- Exit the program." << endl;
	cin >> n;
	switch (n) {
	case 1:
		list = new linked_list();
		list->push();
		break;
	case 2:

		list->PrintStart();
		break;
	case 3:

		list->PrintEnd();
		break;
	case 4:
		search_collection(*list);
		break;
	case 5:
		search_collection_end(*list);
		break;
	case 6:
		cout << "input id of place: " << endl;
		int id;
		cin >> id;
		if (id == 0)
		{
			list->insert_front(&list->get_head());
		}
		else
		{
			id--;
			list->insertAfter(list->getNode(id, list->get_head()));
		}
		break;
	case 7:
		cout << "input id of place: " << endl;
		int del;
		cin >> del;
		list->deleteNodeAtGivenPosition(&list->get_head(), del);
		break;
	case 8:
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
				list->sort();
				break;
			case 1:
				list->sortWet();
				break;
			case 2:
				list->sortWet();
				break;
			case 3:
				list->sortCoef();
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
	case 9:

		list->PrintFile();
		break;
	case 10:
		list = new linked_list();
		list->ReadFile();
		break;
	case 11:
		return 0;
		break;
	default:
		cout << "Invalid value";
		goto dd;
		break;
	}
	goto dd;
}
