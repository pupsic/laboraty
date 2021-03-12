#ifndef __FUNCS_H__
#define __FUNCS_H__
#include"globals.h"

 
int enter_keyboard(mon* mc, int n);

int enter_random(mon* mc, int n);

void print(mon* mc, int n);

void sortirovka_by_name_down(mon* mc, int n);
void sortirovka_by_type_down(mon* mc, int n);
void sortirovka_by_wet_down(mon* mc, int n);
void sortirovka_by_coef_down(mon* mc, int n);

void sortirovka_by_name_up(mon* mc, int n);
void sortirovka_by_wet_up(mon* mc, int n);
void sortirovka_by_type_up(mon* mc, int n);
void sortirovka_by_coef_up(mon* mc, int n);

int delete_stract_by_name(mon* mc,int n);

int delete_stract_by_wet(mon* mc, int n);

int delete_stract_by_type(mon* mc, int n);

int delete_stract_by_coefficient(mon* mc, int n);

int delete_all_stract(mon* mc, int n);
void print_line(mon* mc, int i);
void find_element_name(mon*mc, int n);
void find_element_type(mon* mc, int n);
void find_element_wet(mon* mc, int n);
void find_element_coef(mon* mc, int n);

void full_info(mon* mc, int n,FCT* fct);

string id(int index);

#endif // __FUNCS_H__