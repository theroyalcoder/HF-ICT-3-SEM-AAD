#include <iostream>
using namespace std;

class StringUtil{ public: static bool checkUniqueness(string s); };

int main() {
    string s = "SAERTZUIOILKUJZHTGXRFERGTIUOPHTGD";
    StringUtil obj1;
    obj1.checkUniqueness(s);
    return 0;
}

bool StringUtil::checkUniqueness(string s) {
    int *count;
    count = new int[s.length()]{};

/*
 * Ermitteln wieviel Mal Buchstabe im String vorkommt
 * Für jeden Buchstaben wird Element um 1 erhöht A -> array[0]++; B -> array[1]++ usw.
 */
    for (int i = 0; i < s.length(); i++) {
       int tmp = s[i] - 65;
        count[tmp]++;
    }

//    Buchstabe mit Array vergleich, ob im Array Wert 1 gesetzt ist
    for (int j = 0; j < s.length(); j++) {
        int tmp = s[j] - 65;
        if (count[tmp] == 1){
            cout << s[j] << endl;
            return true;
        }
    }
    delete [] count;
    return false;
}
