#include <iostream>
using namespace std;

int ggt(int a, int b) {
    //Abbruchbedingung
    if (a == b) return a;

    if (a!=b) {
        if (a > b) {
            return ggt(a - b, b);
        }
        else {
            return ggt(a, b - a);
        }
    }
}


int main() {
    cout << ggt(10, 15);
    return 0;
}