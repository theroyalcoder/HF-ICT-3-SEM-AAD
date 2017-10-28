#include <iostream>
using namespace std;

class ArrayUtil { public: static long *multiplyArrayValues(const long *values, const int ARRAY_SIZE); };

int main() {
    const int array_size(4);
    const long array[array_size] = {2, 4, 6, 8};

    ArrayUtil obj1;
    obj1.multiplyArrayValues(array, array_size);

    return 0;
}

long *ArrayUtil::multiplyArrayValues(const long *values, const int ARRAY_SIZE) {
    long *arr2 = new long[ARRAY_SIZE]{};

    for (int l = 0; l < ARRAY_SIZE; l++) {
        arr2[l] = 1;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            if (i != j) {
                arr2[i] *= values[j];
            }
        }
    }

    for (int k = 0; k < ARRAY_SIZE; ++k) {
        cout << arr2[k] << endl;
    }

    delete [] arr2;
    return nullptr;
}
