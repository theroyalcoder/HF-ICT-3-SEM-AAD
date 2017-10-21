#include <iostream>
using namespace std;

class Vector {
private:
    int a, b, c;
public:
    Vector(int a, int b, int c) : a(a), b(b), c(c) {};
    Vector add(const Vector &obj);
    void print();
};

Vector Vector::add(const Vector & obj) {
    Vector result(a+obj.a, b+obj.b, c+obj.c);
    return result;
}

void Vector::print() {
cout << "a=" << a << ",b=" << b << ",c=" << c << endl;
}

template <class T>
T add(T&obj1, T&obj2) {
return obj1 + obj2;
}

int main( int argc, char **argv) {
    Vector v1(1 ,2 ,3);
    Vector v2(4 ,5 ,6);
    Vector v3 = add<Vector>(v1, v2);
    v3.print();
    return 0;
}
