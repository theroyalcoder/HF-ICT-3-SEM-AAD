#include <iostream>
using namespace std;

class ArrayUtil { public: static int highestProduct(int *values, const int ARRAY_SIZE); };

int main() {
    const int array_size(4);
    int factors[array_size] {3, 7, 4, 9};

    ArrayUtil calc;
    calc.highestProduct(factors, array_size);

    return 0;
}

int ArrayUtil::highestProduct(int *values, const int ARRAY_SIZE) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        for (int j = i+1; j < ARRAY_SIZE; ++j) {
            if (values[j] > values[j+1]) {
                swap(values[j], values[j+1]);
            }
        }
    }

    int tmp(1);
    for (int k = ARRAY_SIZE-1; k > ARRAY_SIZE-4 ; k--) {
        tmp *= values[k];
        cout << tmp << endl;
    }
    return 0;
}
