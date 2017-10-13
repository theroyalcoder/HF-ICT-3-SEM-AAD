#include <iostream>
using namespace std;

class A {
private:
    int m;
public:
    A(int m) : m(m) {
        cout << "A::constructor,m=" << m << endl;
    }

    void method() {
        cout << "A::method" << endl;
    }

    ~A() {
        cout << "A::desctructor" << endl;
    }
};

class B : public A {
private:
    int m;
public :
    B (int m) :A(m),m(m) {
        cout<<"B::constructor,m="<<m<<endl;
    }

    void method() {
        cout << "B::method" << endl;
    }

    ~B() {
        cout << "B::desctructor" << endl;
    }
};

int main(int argc, char **argv) {
    A *obj = new B(5);
    obj->method();

    delete obj;

    return 0;
}