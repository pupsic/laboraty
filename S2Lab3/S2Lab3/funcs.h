#ifndef __FUNCS_H__
#define __FUNCS_H__
#include"globals.h"

 
int enter_keyboard(mon* mc, int n);

int enter_random(mon* mc, int n);

void print(mon* mc, int n);

void sortirovka(mon* mc, int n);

int delete_stract(mon* mc,int n);

int delete_all_stract(mon* mc, int n);

void find_element(mon*mc, int n);

void full_info(mon* mc, int n,FCT* fct);

string id(int index);

#endif // __FUNCS_H__