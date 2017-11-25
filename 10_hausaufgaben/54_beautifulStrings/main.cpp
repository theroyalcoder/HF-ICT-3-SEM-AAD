#include <iostream>
#include <algorithm>

using namespace std;

int calculate(string input) {
    int sum(0);
    int num(26);
    int asciiArr[26]{};

    //In Kleinbuchstaben konvertieren
    transform(input.begin(),input.end(),input.begin(), ::tolower);

    for(auto i : input){
        //Uberprufen, ob inputelemente zwischen a - z sind
        if((i >= 'a') && (i <= 'z')) asciiArr[static_cast<unsigned int>(i - 'a')] += 1;
        //cout << asciiArr[static_cast<unsigned int>(i-'a')];
    }

    //Nach der grösse sortieren
    sort(std::begin(asciiArr), std::end(asciiArr), std::greater<int>());

    for (auto j : asciiArr) {
        if (j != 0) {
            sum += j * (num);
            --num;
        }
    }
    return sum;
}

int main(int argc, char **argv) {
    string str = "ABBCCC"; //152
    cout << "Die Zeichenkette '" << str << "' hat die Schoenheit " << calculate(str) << endl;

    str = "Sometimes test cases are hard to make up."; //729
    cout << "Die Zeichenkette " << str << " hat die Schoenheit " << calculate(str) << endl;

    return 0;
}
