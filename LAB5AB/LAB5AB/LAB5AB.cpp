#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    //A:
    setlocale(LC_ALL, "Rus");
    float a, b, c, x1, x2, D, realPart, imaginaryPart;
    cout << "Введите коэффициенты a, b и c: ";
    cin >> a >> b >> c;
    D = b * b - 4 * a * c;

    if (D > 0) {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        cout << "Корни существуют и разные." << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }

    else if (D == 0) {
        cout << "Корни существуют и одинаковые" << endl;
        x1 = -b / (2 * a);
        cout << "x1 = x2 =" << x1 << endl;
    }

    else {
        cout << "Корни не существуют" << endl;
   
    }
    //B:
    int k;
    cin >> k;
    cout << "У меня "<<k<<"грибов"<<endl;
    return 0;
}


