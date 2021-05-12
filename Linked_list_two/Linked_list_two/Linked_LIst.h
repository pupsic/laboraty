#pragma once
#ifndef LIST_H
#define LIST_H
#include <string>
using namespace std;

struct node {
	node* prev = NULL;
	string name;
	char type;
	float wet;
	float coef;
	node* next = NULL;
};

class linked_list {
private:

	node* head = NULL;
	node* tail = NULL;

	void frontBackSplit(node* theHead, node*& frontRef, node*& backRef);
	void sort(node*& theHead);
	node* sortedMerge(node* a, node* b);

	void frontBackSplitType(node* theHead, node*& frontRef, node*& backRef);
	void sortType(node*& theHead);
	node* sortedMergeType(node* a, node* b);

	void frontBackSplitWet(node* theHead, node*& frontRef, node*& backRef);
	void sortWet(node*& theHead);
	node* sortedMergeWet(node* a, node* b);

	void frontBackSplitCoef(node* theHead, node*& frontRef, node*& backRef);
	void sortPopulation(node*& theHead);
	node* sortedMergeCoef(node* a, node* b);
public:
	void sort();
	void sortType();
	void sortWet();
	void sortCoef();
	int GetSize();
	void insert_front(struct node** head);
	void PrintStart();
	void PrintEnd();
	void push();
	void insertAfter(node* prev_node);
	void deleteNode(struct node** head_ref, struct node* del);
	void deleteNodeAtGivenPosition(node** head_ref, int n);
	void PrintFile();
	void ReadFile();
	void printLine(node* n);
	void searchHead(string type, string input);
	void searchtTail(string type, string input);
	node* getNode(int index, node* head);
	node*& get_head() {
		return head;
	};

	void sortedInsert(struct node** head_ref, struct node* newNode);
	void insertionSort(struct node** head_ref);

};

void search_collection(linked_list a);
void search_collection_end(linked_list a);
#endif // __FUNCS_H__