#include <iostream>
using namespace std;

class Trader { public: int calculateMaxProfit(const int *values, const int ARRAY_SIZE); };

int main(int args, const char **argv) {
    srand(time(NULL));
    const int array_size(10);
    int stockprices[array_size]{};

//    Random Zahlen in Array generieren
    for (int i=0; i < array_size; i++) {
//        stockprices[i] = rand() % 1000 - 500;
        stockprices[i] = rand() % 10;
    };

//    Ausgabe Randomzahlen
    for (int i = 0; i < array_size; ++i) {
        cout << i << ":\t" << stockprices[i] << endl;
    }
    cout << endl;

    Trader prognosis;
    prognosis.calculateMaxProfit(stockprices, array_size);

    return 0;
}

int Trader::calculateMaxProfit(const int * values, const int ARRAY_SIZE) {
//    Das erste speichert den Arrayindex von Array "values", das Zweite den Wert der Aktie
    int match_size = 2;
    int *matchIndex = new int[match_size] {};
    int *matchValue = new int[match_size] {};
    matchValue[0] = values[0];


//    Wir verglichen, ob arrayelement n kleiner ist als arrayelement m
    for (int i = 0; i < ARRAY_SIZE-1; i++) {
        if (values[i] < values[i+1]) {
            matchIndex[i] = i;
            matchValue[i] = values[i];
            matchIndex[i+1] = i+1;
            matchValue[i+1] = values[i+1];

            cout << i << ": " << values[i] << endl;
            cout << i + 1 << ": " << values[i + 1] << endl;

            //i++ Damit man nicht in der gleichen Minute kaufen und verkaufen kann
            i++;
            match_size += 2;
        }
    }

    cout << endl;


    for (int j = 0; j < match_size; ++j) {
        cout << matchIndex[j] << "value: \t" << matchValue[j] << endl;
    }

/*//    2x - 1x = dif -> grösste dif finden und ausgeben
    for (int j = match_size-1; j > 0; j--) {
        int res = 0;
        int tmp = 0;

        tmp = matchValue[j] - matchValue[j-1];

        cout << matchValue[j-1] << " - " << matchValue[j] << ": \t" << tmp << endl;



//        if (tmp > res) {
//            res = tmp;
//            cout << matchIndex[j-1] << " - " << matchIndex[j] << ": \t" << res << endl;
//            j--;
//        }
    }*/

    delete [] matchIndex;
    delete [] matchValue;
    return 0;
}
