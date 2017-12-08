#include <iostream>
#include <vector>
using namespace std;

/* Implementieren Sie eine Methode analyseArray welche als Parameter einen vector mit Integer Werten bekommt.
 * Diese Werte sind entweder Positiv, Negativ oder Null.
 * Die Methode soll nun berechnen, wie viel Prozent der Werte Positiv, Negativ resp. Null sind.
 * Diese drei Werte werden als Objekt der Klasse Result zuru ̈ ckgeliefert.*/

class Result {
public :
    int nPositive;
    int nNegative;
    int nZero;
    static void printResult(Result r);
};

void Result::printResult(Result r) {
    double max = r.nPositive + r.nNegative + r.nZero;

    std::cout.precision(3); //Nur 3 Zahlen ahzeigen, d.h. 1 Nachkommastele
    cout << "nPositive: " << (r.nPositive * 100) / max << "%" << endl;
    cout << "nNegative: " << (r.nNegative * 100) / max << "%" << endl;
    cout << "nZero: " << (r.nZero * 100) / max << "%" << endl;
}

class ArrayUtil {
public :
    static Result analyseArray(vector<int>input);
};

Result ArrayUtil::analyseArray(vector<int> input) {
    Result r{};

    r.nNegative = 0;
    r.nZero = 0;
    r.nPositive = 0;

    for (auto i : input) {
        if (i < 0) {
            r.nNegative++;
        } else if (i > 0) {
            r.nPositive++;
        } else if (i == 0) {
            r.nZero++;
        } else {
            cout << "Input in not a number - error" << endl;
            return r;
        }
    }

    return r;
}


int main() {
    vector<int> vec = {1, 10, 0, -6, -9, 2, 5};
    Result::printResult(ArrayUtil::analyseArray(vec));
    return 0;
}