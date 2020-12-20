#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    //1)

    int inum_of_byte;
    int snum_of_byte;
    int lnum_of_byte;
    int cnum_of_byte;
    int fnum_of_byte;
    int dnum_of_byte;
    inum_of_byte = sizeof(int);
    snum_of_byte = sizeof(short);
    lnum_of_byte = sizeof(long);
    cnum_of_byte = sizeof(char);
    fnum_of_byte = sizeof(float);
    dnum_of_byte = sizeof(double);
    //2)
    int a, b, c;
    float s, p;
    a = 3;
    b = 4;
    c = 5;
    p = (a + b + c) / 2;
    s = sqrt(p * (p - a) * (p - b) * (p - c));
    cout << "Square: " << s << endl;
    //3)
    int x = 2;
    x = x * x;
    x = x * x;
    x = x * x;
    cout << "2 in 8: " << x << endl;
    //4)temp
    int temp;
    cout<<"temp: " << b << ' ' << a << endl;
    temp = b;
    b = a;
    a = temp;
    cout << b << ' ' << a << endl;
    //4)without temp
    cout <<"without temp: "<< c << ' ' << a << endl;
    a = a + c;
    c = a - c;
    a = a - c;
    cout << c << ' ' << a << endl;
    //5)
    cout << "input number: ";
    cin >> a;
    cout << "User input:" << a << "\n PC output:" << a + 10 << "\nPc WIN!!!";
    //6)
    cout << "\nInput year:";
    cin >> a;
    a = a * 365 * 3600 * 24;
    cout << a;
}


