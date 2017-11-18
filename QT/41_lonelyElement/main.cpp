#include <iostream>
#include <map>

using namespace std;

/*
Implementieren Sie eine Methode getLonelyElement welche als Parameter einen string bekommt.
Jeder Character in diesem string kommt zweimal vor, ausser eines.
Die Methode soll das Element zuruekliefern, welches nur einmal vorkommt.
*/

class StringUtil {
public:
static char getLonelyElement(string input);
};

int main() {
    cout << endl;
    int len = 100;
    string s = "abcdedcba11";


    for (int i = 0; i < len; ++i) {
        int randomChar = rand()%26;

        if (randomChar < 25) {
            s[i] = 'a' + (char)randomChar;
            cout << s[i];
        }
    }
    cout << endl;

    s[len] = 'z';

    StringUtil search;
    search.getLonelyElement(s); // Ergebnis: z
    return 0;
}

char StringUtil::getLonelyElement(string input) {
    int ascii[256] {};
    char output;

    for (int i = 0; i < input.size(); i++) {
        ascii[input[i]]++;
        cout << input[i] << endl;
    }

    for (int i = 0; i < 256; i++ ) {
        if (ascii[input[i]] == 1) {
            output = input[i];
            cout << output << endl;
            return output;
        }
    }

    return output;
}
