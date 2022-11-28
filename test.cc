#include <memory>
#include <iostream>

using namespace std;

struct A{
    int n;
    A (int n): n{n} {}
};

int main() {
    auto a = make_unique<A>(1);
    auto b = make_unique<A>(9);
    cout << a->n << "  " << b->n << endl;
    b = make_unique<A>(77);
    cout << a->n << "  " << b->n << endl;
    b.reset(new A {4});
    cout << a->n << "  " << b->n << endl;
    cout << (a==nullptr) << endl;
    a = nullptr;
    cout << (a==nullptr) << endl;
    // cant do a=b directly
    a.reset(new A {*b});
    cout << a->n << "  " << b->n << endl;
    a->n = 9;
    cout << a->n << "  " << b->n << endl;
    b->n = 10;
    cout << a->n << "  " << b->n << endl;
}
