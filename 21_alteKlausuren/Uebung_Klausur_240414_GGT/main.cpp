#include <iostream>
using namespace std;

int ggt(int a, int b);

int main(int argc, char *argv[]) {
    int a(100), b(225);
    ggt(a, b);

    return 0;
}

int ggt(int a, int b) {
    if (a != b) {
        if ( a > b) {
            a -= b;
            return ggt(a, b);
        } else {
            b -= a;
            return ggt(a, b);
        }
    } else {
        cout << a << endl;
        return a;
    }


}
