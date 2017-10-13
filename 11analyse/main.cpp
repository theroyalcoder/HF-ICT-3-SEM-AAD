#include <iostream>
#include <ctime>
using namespace std;

void foo( int *array, int size) {
    int sum = 0;
    int product = 1;

    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    for (int i = 0; i < size; i++) {
        product *= array[i];
        cout << sum << "," << product << endl;
    }
}

int main() {
    int size(10000);
    int array[size];

    clock_t start, stop;

    start = clock();

    foo(array, size);

    stop = clock();

    double time = (double) (stop-start) /CLOCKS_PER_SEC;
    cout << time << endl;




    return 0;
}