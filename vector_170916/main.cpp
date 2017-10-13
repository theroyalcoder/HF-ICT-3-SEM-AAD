#include <iostream>
using namespace std;

class CoinCombination {
public:
    static void printCoinCombination( double value, const double *coins, const int ARRAY_SIZE);
};

void CoinCombination::printCoinCombination(double value, const double *coins, const int ARRAY_SIZE) {

}


int main() {
    double value = 23;
    int ARRAY_SIZE = 7;
    double *coins;
    coins = new double[ARRAY_SIZE];

    CoinCombination combine;
    combine.printCoinCombination(value, coins, ARRAY_SIZE);

    return 0;
}
