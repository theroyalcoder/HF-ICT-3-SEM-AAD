#include <iostream>
using namespace std;
class StringUtil {
public :
    static char getLonelyElement(string input) ;
};

/*Implementieren Sie eine Methode getLonelyElement welche als Parameter einen string bekommt.
 * Jeder Character in diesem string kommt zweimal vor, ausser eines. Die Methode soll das Element zuru ̈ckliefern,
 * welches nur einmal vorkommt.
*/
char StringUtil::getLonelyElement(string input) {
    auto *ascii = new int[255]{};
    char opt = NULL;

    for (char i : input) {
        cout << i << "\t";
        ascii[i] ++;
    }
    cout << endl;

    for (int j = 0; j < 255; ++j) {
        if (ascii[j] == 1) {
            opt = static_cast<char>(j);
            cout << ascii[j] << "\t (" << opt << ") \t";
            return opt;
        }
    }

    return 0;
}

int main() {
    string input = "abcdedcba11"; // e
    auto *ST = new StringUtil;
    ST->getLonelyElement(input);
    return 0;
}