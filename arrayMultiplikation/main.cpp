#include <iostream>
using namespace std;
class arrayUtil {
public:
    static long *multiplyArrayValues(const long *values, const int ARRAY_SIZE);
};

int main() {
    const int array_size(4);
    const long array[array_size] {1, 2, 3, 4};

    arrayUtil obj1;
    obj1.multiplyArrayValues(array, array_size);

    return 0;
}


long *arrayUtil::multiplyArrayValues(const long *values, const int ARRAY_SIZE) {
    long ergebnis[ARRAY_SIZE];
    long *arr1 = new long[ARRAY_SIZE];
    long *arr2 = new long[ARRAY_SIZE];

    arr1[0] = 1;
    for(int i = 1; i < ARRAY_SIZE; i++){
        arr1[i] = arr1[i-1] * values[i-1];
    }

    arr2[ARRAY_SIZE-1] = 1;
    for(int i = ARRAY_SIZE-2; i >= 0; i--){
        arr2[i] = arr2[i+1] * values[i+1];
    }

    for(int i = 0; i < ARRAY_SIZE; i++){
        ergebnis[i] = arr1[i] * arr2[i];
    }

    delete[] arr1;
    delete[] arr2;


    for (int j = 0; j < ARRAY_SIZE; ++j) {
        cout << ergebnis[j] << endl;
    }
    return nullptr;
}
