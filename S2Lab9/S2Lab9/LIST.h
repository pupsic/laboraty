#ifndef LIST_H
#define LIST_H
#include <string>

using namespace std;



class linked_list
{
private:
    
    struct node
    {
        string name;
        char type;
        unsigned int wet = 0;
        double coef = 0;
        node* next;
      
    };
    node* head, * tail;
    void printLine(node* n);
public:
    struct data
    {
        string name;
        char type;
        unsigned int wet = 0;
        double coef = 0;

    };

    linked_list()
    {
        head = NULL;
        tail = NULL;

    }

    void search(string type, string input, node* head);

    void addNode(data*& Data);
    void insert(node* prev_node, data*& Data);
    void addEnd(node** head_ref, data*& Data);
    void addBeginning(node** head_ref, data*& Data);
    void deleteBeginning(node*& head);
    void deleteEnd(node*& head, node*& tail);

    void messageErrorEmpty(node*& head);
    void messageErrorFound(node*& head);

    int getSize(node*& head);
    void deleteSpecificName(string node_location, node*& head, node*& tail);
    void deleteSpecificType(char node_location, node*& head, node*& tail);
    void deleteSpecificWet(unsigned int node_location, node*& head, node*& tail);
    void deleteSpecificCoef(double node_location, node*& head, node*& tail);
    node* getNode(int index, node* head);
    void printTable(node* n);

    node*& get_head(){
        return head;
    }
    node*& get_tail() {
        return tail;
    }
    node*& get_node() {
        ;
    }
};

void search_collection(linked_list a);


#endif // __FUNCS_H__
