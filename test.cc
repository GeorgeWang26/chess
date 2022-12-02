#include <memory>
#include <iostream>

using namespace std;

class c1 {
public:
    int me() {
        return get();
    }
    virtual int get() {
        return 1;
    }
};

class c2: public c1 {
    int get() override {
        return 2;
    }
};

int main() {
    c2 obj;
    cout << obj.me() << endl;
    c1 objj;
    cout << objj.me() << endl;
    int i = 10;
    // cout << i + 33 << "asd\nasd" << endl;
    cout << "123" << endl;
    cout << "\n  abcdefgh\n" << endl;
    cout << "123" << endl;
}
