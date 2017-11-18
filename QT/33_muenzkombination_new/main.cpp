#include <iostream>
using namespace std;

class CoinCombination { public: static void printCoinCombination( double value, const double *coins, const int ARRAY_SIZE); };

int main() {
    double value = 23.95;
    int ARRAY_SIZE = 7;
    double *coins;
    coins = new double[ARRAY_SIZE]{5, 2, 1, 0.50, 0.20, 0.10, 0.05};

    CoinCombination combine;
    combine.printCoinCombination(value, coins, ARRAY_SIZE);

    return 0;
}

void CoinCombination::printCoinCombination(double value, const double *coins, const int ARRAY_SIZE) {
    double startValue(0);
    int new_size(0);
    int count(0);

    while(startValue != value && count < 50) {
        if (startValue < value) {
            startValue += coins[new_size];

            if (startValue < value) {
                cout << "startValue" << startValue << endl;
                cout << "coins[new_size]" << coins[new_size] << endl;
            }
        } else {
            startValue -= coins[new_size];
            new_size++;
        }
        count++;
    }
}
