#include <iostream>
using namespace std;

//Bedingung das es funktioniert: Nur ASCII Zeichen bos 255 erlaubt


class StringUtil{ public: static bool anagrammCheck(string s1, string s2); };

int main() {
    string s1 = "HALLO. .*Mein Name ist Anu.+";
    string s2 = "OlLaH..+* NuA MeIn NaMe TsI.";

    StringUtil compare;
    compare.anagrammCheck(s1, s2);

    return 0;
}

bool StringUtil::anagrammCheck(string s1, string s2) {
    int SIZE(254);
    int *letterCount1 = new int[SIZE] {0};
    int *letterCount2 = new int[SIZE] {0};

//    Alle Buchstaben in Kleinbuchstaben konvertieren
    transform(s1.begin(), s1.end(), s1.begin(),(int (*)(int))tolower);
    transform(s2.begin(), s2.end(), s2.begin(),(int (*)(int))tolower);

//    Überprüfen, ob beide Strings gleich lange sind
    if (s1.length() == s2.length()) {

//         Für jeden Buchstaben in Array letterCount den Elemendindex erhöhen
        for (int i = 0; i < s1.length(); ++i) {
            letterCount1[s1[i]]++;
            letterCount2[s2[i]]++;
        }

//        Überprüft, ob von beiden Array die Werte vom Elementindex gleich gross sind
        for (int j = 0; j < SIZE; ++j) {
            if (letterCount1[j] != letterCount2[j]) {
                cout << "No Annagram" << endl;
                return  false;
            }
        }
        cout << "Yeah, it's an Annagram" << endl;

    } else {
        cout << "No Annagram" << endl;
        return false;
    }
    return false;
}
