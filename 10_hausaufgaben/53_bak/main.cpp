// 53_VS.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Treeutil {
public:
    static void printMaximumPath(vector<int> values);
    static int calculateMaximumPath(vector<int> values, int index, int sumL, int sumR, int sumMax);
};

void Treeutil::printMaximumPath(vector<int> values) {
    int print(0);
    for (int i = 1; i < values.size(); i++) {
        print = calculateMaximumPath(values, i, values[i], values[i], print);
    }

    cout << print << endl;

    /*
    Node = i
    Node:Left = 2 * i + 1
    Node:Right = 2 * i + 2
    */
}

int Treeutil::calculateMaximumPath(vector<int> values, int index, int sumL, int sumR, int sumMax) {
    //Abbruchbedingung
    if (index < values.size()) {
        if (sumL > sumR) {
            cout << sumR << endl;
            return sumL;
        }
        else {
            cout << sumL << endl;
            return sumR;
        }
    }

    if (index % 2 == 0) {
        // I am the RIGHT element
        index = (index * 2) + 2;
        // values[index] = a parent element
        sumR += values[index];
    }

    if (index % 2 == 1) {
        // I am the LEFT element
        index = (index * 2) + 1;
        // values[index] = a parent element
        sumL += values[index];
    }
    //Auswahlverfahren L und R
    if (sumL > sumR) {
        //Uberprufen, ob L grosser als Max ist
        if (sumL > sumMax) {
            sumMax = sumL;
        }

    }
    else {
        //Uberprufen, ob R grosser als Max ist
        if (sumR > sumMax) {
            sumMax = sumR;
        }
    }


    return calculateMaximumPath(values, index, sumL, sumR, sumMax);
}

int main(int argc, char **argv) {
    const int s(7);
    int arr[s] = { 30, 20, 50, 2, 29, 47, 55 };
    int sum = 0;

    vector<int> vec;
    vec.reserve(s);

    for (int i = 0; i < s; ++i) {
        vec.push_back(arr[i]);
    }


    Treeutil tu;
    tu.printMaximumPath(vec);

    return 0;
}
