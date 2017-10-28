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
    // Der String, den man an diese Funktion übergibt, sollte man vorher mit s = "" initialisieren
    void fillRandomString(string& str, const int size);
};

char StringUtil::getLonelyElement(string input) {
    int ascii[255] {};
    char output = 0;

    cout << "input: \t" << input << endl;

    for (int i = 0; i < input.size(); i++) {
        ascii[input[i]]++;
        //cout << input[i];
    }

    for (int i = 0; i < 256; i++ ) {
        if (ascii[input[i]] == 1) {
            output = input[i];
            cout << "output: " << output << endl;
            return output;
        }
    }

    return output;
}

void StringUtil::fillRandomString(string& str, const int size) {
    for (int i = 0; i < size; i++) {
        str+= (char)((int)(rand() % 26) + (int)'a');
    }
}

int main() {
    cout << endl;
    int len = 10;
    string s1 = "abcdedcba11";
    string s2 = "lrfkqyuqfjkxyqvnrtys....frrmlygfveulqfpdbhlqdq+*ç%&rrcrwdnxeuoqqeklaitgdphczspijthbsfyfvladpbfudkklrwqaom";
    string s3 = "";

/*    s3.resize(len);
    cout << s3.size() << endl;

    for (int i = 0; i < len; ++i) {
        int randomChar = rand()%26;

        if (randomChar < 25) {
            s3.push_back('a' + (char)randomChar);
            cout << "array abgefüllt mit: " << s3[i] << endl;
        }
    }

    cout << endl;
    s3[len-1] = 'z';
    */

    StringUtil search;
    search.getLonelyElement(s1);
    search.getLonelyElement(s2);

    search.fillRandomString(s3, len);
    search.getLonelyElement(s3);

    return 0;
}
