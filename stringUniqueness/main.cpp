#include <iostream>
using namespace std;

class StringUtil{ public: static bool checkUniqueness(string s); };

int main() {
    string s = "AABBCCD";

    StringUtil obj1;
    obj1.checkUniqueness(s);

    return 0;
}

bool StringUtil::checkUniqueness(string s) {
//    s.length() ist eine long Variable, durch '(int)' habe ich ein casting gemacht
    int str_length = (int) s.length();
    int letter(0);
    int arr[26] {0};

//    Jeden Buchstaben der kommt, wird in 'arr' im jeweiligen ASCII Bereich um 1 hochgezählt
    for (int i = 0; i < str_length; i++) {
        letter = s[i];
//        cout << letter << "." << endl;
        arr[letter - 65]++;
//        cout << arr[letter-65] << endl;
    }

    for (int j = 0; j < str_length; j++) {
//        if (s[j] == )
    }

//    Sucht im Array 'arr' nach dem ersten Element welches den Wert 1 hat und gibt den Buchstaben aus (k + 65) <--- ASCII
    for (int k = 0; k < 26; k++) {
//        cout << arr[k] << "." << endl;

        if (arr[k] == 1) {
            cout << (char) (k + 65) << endl;
            return true;
        }
    }
    return true;
}
