#include <iostream>
using namespace std;

class StringUtil {public: static string lcs(string input1, string input2);};

int main() {
    string input1 = "abcdefef";
    string input2 = "bccccdef";

    StringUtil check;
    check.lcs(input1, input2);
    return 0;
}

string StringUtil::lcs(string input1, string input2) {
    string output1 = "";
    string output2 = "";
    string tmp1, tmp2, tmp3, tmp4;

    tmp3 = input1;
    tmp4 = input2;


    for (int j = 0; j < input1.length(); j++) {
        tmp2 =input2;

        for (int i = 0; i < input1.length(); i++) {
            if (input1.find(tmp2) != string::npos) {
                if (tmp2.length() > output1.length()) {
                    cout << "SS gefunden: \t" << tmp2 << endl;
                    output1 = tmp2;
                }
            } else {
                tmp2.pop_back();
                cout << "tmp2" << tmp2 << endl;
            }
        }

        input2.erase(0, 1);
        cout << input2 << endl;
    }

/*
    for (int j = 0; j < input2.length(); j++) {
        tmp3 = input1;

        for (int i = 0; i < input2.length(); i++) {
            if (input2.find(tmp3) != string::npos) {
                if (tmp3.length() > output2.length()) {
                    cout << "SS gefunden: \t" << tmp3 << endl;
                    output2 = tmp3;
                }
            } else {
                tmp3.pop_back();
                cout << "tmp3" << tmp3 << endl;
            }
        }
        input1.erase(0, 1);
        cout << input1 << endl;
    }
*/

    cout << "output1: \t" << output1 << endl;
    //cout << "output2: \t" << output2 << endl;

return output1;
}
