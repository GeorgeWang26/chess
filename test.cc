#include <memory>
#include <iostream>

using namespace std;

int main() {
    double d = 1;
    cout << d << endl;
    d += 0.5;
    d++;
    cout << d << endl;
    d += 0.5;
    cout << d << endl;
    float f = 1;
    cout << f << endl;
    f += 0.5;
    f++;
    cout << f << endl;
    f += 0.5;
    cout << f << endl;
    cout << sizeof(double) << " " << sizeof(float) << " " << sizeof(int) << endl;
}