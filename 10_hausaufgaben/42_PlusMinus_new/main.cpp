#include </Users/anuuthomson/ClionProjects/HF-ICT-AAD-1-SEM/stdc++.h> //Alle benötigten Includes
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
};


Result::Result(int pos, int neg, int zer) {
	nPositive = pos;
	nNegative = neg;
	nZero = zer;
}

class ArrayUtil {
public :
	static Result analyseArray(vector<int> input);
};


Result ArrayUtil::analyseArray(vector<int> input) {
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
	srand(static_cast<unsigned int>(time(nullptr)));
	unsigned int VEC_SIZE = 100000;
	vector<int> input;

	//Randomzahlen in Vector schreiben
	for (unsigned int i = 0; i < VEC_SIZE; ++i) {
		input.push_back(rand()%200-100);
	}

	Result result = ArrayUtil::analyseArray(input);
	cout.precision(3); //Ausgabe kürzen (auf 3 Stellen)
	cout << result << endl;
	return 0;
}
