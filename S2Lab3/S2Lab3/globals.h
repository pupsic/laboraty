#ifndef __GLOBALS_H__
#define __GLOBALS_H__
#include <iomanip>;
#include <time.h>
#include <string>
#define NUM_OF_STRUCT 100
using namespace std;



struct mon
{
    string name;
    string type;
    unsigned int wet = 0;
    double coef = 0;
    time_t timeinfo;
};       // глобальная переменная

#endif // __GLOBALS_H__