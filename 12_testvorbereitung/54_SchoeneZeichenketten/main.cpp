#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int calculate(string input) {
//
//    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    int sum = 0;
    int asciiBuchstabe[26]{};
//    vector<int> asciiBuchstabe;
//    asciiBuchstabe.reserve(26);

    for (auto i : input) {

        if( (i >= 'a') && (i <= 'z') ) {

            asciiBuchstabe[i-'a'] += 1;

        } else if( (i>='A')&&(i<='Z') ) {

            asciiBuchstabe[i-'A'] += 1;

        }
    }

    sort(asciiBuchstabe, asciiBuchstabe + 26);

//    for (auto i : asciiBuchstabe) {
//        cout << "i: " << i << "\t";
//    }

    for (int j = 26; j >= 1; --j) {
        if (asciiBuchstabe[j - 1] == 0) return sum;

        sum += asciiBuchstabe[j - 1] * j;
    }


    return sum;
}

int main() {
    string s1 = "ABBCCC";
    string s2 = "Sometimes test cases are hard to make up";

    cout << s1 << ": \t" << calculate(s1) << endl;

    cout << s2 << ": \t" << calculate(s2);


    return 0;
}