#include <iostream>
#include <vector>
using namespace std;

/*
 Implementieren Sie eine Methode analyseArray welche als Parameter einen vector mit Integer Werten bekommt.
 Diese Werte sind entweder Positiv, Negativ oder Null.
 Die Methode soll nun berechnen, wie viel Prozent der Werte Positiv, Negativ resp. Null sind.
 Diese drei Werte werden als Objekt der Klasse Result zurückgeliefert.
*/

class Result {
public :
    double nPositive;
    double nZero;
    double nNegative;
    int SIZE;
    Result(double pos, double neg, double zer, int size);
};

Result::Result(double pos, double neg, double zer, int size) {
    nPositive = pos;
    nNegative = neg;
    nZero = zer;
    SIZE = size;

    cout << "Negativ: " << nNegative / size * 100 << "%" << endl;
    cout << "Positiv: " << nPositive / size * 100 << "%" << endl;
    cout << "Zero: " << nZero / size * 100 << "%" << endl;

}

class ArrayUtil {
public :
    static Result analyseArray(vector<int> input, int size);
};

int main() {
    srand((unsigned)time(0));
    unsigned long VEC_SIZE = 100000;

    vector<int> input;
    input.reserve(VEC_SIZE);
    vector<int>::iterator iter;

    //Randomzahlen in Vector schreiben
    for (int i = 0; i < VEC_SIZE; ++i) {
        input.push_back(rand()%200-100);
    }

    //Alle Zahlen vom Vector ausgeben
    /*cout << "Input: " << endl;
    for (iter = input.begin(); iter != input.end(); ++iter) {
        cout << *iter << ", ";
    }
    cout << endl;*/

    ArrayUtil obj1;
    obj1.analyseArray(input, static_cast<int>(VEC_SIZE));

    return 0;
}

Result ArrayUtil::analyseArray(vector<int> input, int size) {
    int nPositive(0), nZero(0), nNegative(0);
    double tmp(0);
    vector<int>::iterator iter;

    for (iter = input.begin(); iter != input.end(); ++iter){
        if (*iter < 0) {
            nNegative++;
        } else if (*iter > 0) {
            nPositive++;
        } else if (*iter == 0) {
            nZero++;
        } else {
            cout << *iter << "\t" << ": this is not a number." << endl;
            return Result(-999, -999, -999, -999);
        }
    }

    return Result(nNegative, nPositive, nZero, size);
}
