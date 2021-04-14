#include <iostream>
#include"LIST.h"
#include <string>
using namespace std;



int main()
{
    linked_list a;

    for (int i = 0; i < 5; i++)
    {
        a.add_node("dsf", 'y', i, i);
    }
    //a.deleteBeginning(a.get_head());
    //a.deleteEnd(a.get_head(),a.get_tail());
    a.deleteSpecificName("dsf",a.get_head(), a.get_tail());
    a.deleteSpecificCoef(4, a.get_head(), a.get_tail());
    a.deleteSpecificWet(3, a.get_head(), a.get_tail());
    a.printList(a.get_head());

}


