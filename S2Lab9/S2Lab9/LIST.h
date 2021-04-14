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

public:


    linked_list()
    {
        head = NULL;
        tail = NULL;

    }

    void add_node(string name, char type, unsigned int wet, double coef);
    void deleteBeginning(node*& head);
    void deleteEnd(node*& head, node*& tail);


    void deleteSpecificName(string node_location, node*& head, node*& tail);
    void deleteSpecificType(char node_location, node*& head, node*& tail);
    void deleteSpecificWet(unsigned int node_location, node*& head, node*& tail);
    void deleteSpecificCoef(double node_location, node*& head, node*& tail);
    void printList(node* n);
    node*& get_head(){
        return head;
    }
    node*& get_tail() {
        return tail;
    }

};


#endif // __FUNCS_H__
