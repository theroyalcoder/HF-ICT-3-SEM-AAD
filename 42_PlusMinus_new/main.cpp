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
    int nPositive;
    int nZero;
    int nNegative;

    Result(int pos, int neg, int zer);

    friend ostream &operator << (ostream &output, Result &obj){
        float size = obj.nNegative + obj.nPositive + obj.nZero;
        output << "Negativ: " << (static_cast<float>(obj.nNegative)/size) * 100 << "%" << endl;
        output << "Positiv: " << (static_cast<float>(obj.nPositive)/size) * 100 << "%" << endl;
        output << "Zero: " << (static_cast<float>(obj.nZero)/size) * 100 << "%" << endl;
        return output;
    }


    /*const Result operator+(Result const& lhs, Result const& rhs)
    {
        *//* Erzeugen eines neuen Objektes, dessen Attribute gezielt einzeln gesetzt werden. Oder: *//*
        Result tmp(lhs); //Kopie des linken Operanden
        tmp += rhs; //Implementierung mittels des +=-Operators
        return tmp;
    }*/


};

Result::Result(int pos, int neg, int zer) {
    nPositive = pos;
    nNegative = neg;
    nZero = zer;
/*
    int size = pos + neg + zer;

    cout << "size" << nNegative/ size << endl;


    cout << "Negativ: " << (static_cast<float>(nNegative)/size) * 100 << "%" << endl;
    cout << "Positiv: " << (static_cast<float>(nPositive)/size) * 100 << "%" << endl;
    cout << "Zero: " << (static_cast<float>(nZero)/size) * 100 << "%" << endl;
*/
}

class ArrayUtil {
public :
    static Result analyseArray(vector<int> input, int size);
};

Result ArrayUtil::analyseArray(vector<int> input, int size) {
    int nPositive(0), nZero(0), nNegative(0);
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
            return Result(-999, -999, -999);
        }
    }

    return Result(nPositive, nNegative, nZero);
}

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

    Result obj1(0, 0, 0);
    Result result = ArrayUtil::analyseArray(input, VEC_SIZE);

    cout << result << endl;
    return 0;
}
