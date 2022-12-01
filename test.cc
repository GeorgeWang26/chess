#include <memory>
#include <iostream>

using namespace std;

class A{
public:
    int a;
    int arr[2];
    A(int a, int ar1, int ar2):
        a{a}, arr{ar1, ar2} 
    {}
};

int main() {
    A b {1, 2, 3};
    A c = b;
    cout << b.a << b.arr[0] << b.arr[1] << endl;
    cout << c.a << c.arr[0] << c.arr[1] << endl;
    b.a = 7;
    b.arr[0] = 8;
    b.arr[1] = 9;
    c.a = 4;
    c.arr[0] = 5;
    c.arr[1] = 6;
    cout << b.a << b.arr[0] << b.arr[1] << endl;
    cout << c.a << c.arr[0] << c.arr[1] << endl;
    cout << abs(-3) << endl;
}
