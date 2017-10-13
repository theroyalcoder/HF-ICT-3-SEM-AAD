#include <iostream>
using namespace std;

class Trader { public: int calculateMaxProfit(const int *values, const int ARRAY_SIZE); };

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    const int array_size(5);
    int stockprices[array_size]{};


//    Random Zahlen in Array generieren und ausgeben
    for (int i=0; i < array_size; i++) {
//        stockprices[i] = rand() % 1000 - 500;
        stockprices[i] = rand() % 10;
        cout << i << ":\t" << stockprices[i] << endl;
    };
    cout << endl;

    Trader prognosis;
    prognosis.calculateMaxProfit(stockprices, array_size);

    return 0;
}

int Trader::calculateMaxProfit(const int *values, const int ARRAY_SIZE) {
    int buy = values[0];
    int sell(0);
    int buyPos(0);
    int sellPos(buyPos);

//  kleinsten Wert im Array finden -> Wert und Position speichern
    for (int i = 1; i < ARRAY_SIZE-1; i++) {
        if(buy > values[i]) {
            buy = values[i];
            buyPos = i;
        }
    }

//    todo: grössten Wert im Array finden -> Wert und Position speichern
    for (int j = buyPos+1; j < ARRAY_SIZE; j++) {
        cout << j << endl;
        if (sell < values[j]) {
            sell = values[j];
            sellPos = j;
        }
    }

    cout << "buy: \t" << buyPos << "\t" << buy << endl;
    cout << "sell: \t" << sellPos << "\t" << sell << endl;

    return 0;
}
