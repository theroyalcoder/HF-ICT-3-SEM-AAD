#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

//char analyseNew(string s) {
//    int array[26] = {0};
//    char result = '$';
//
//    for (int i = 0; i < s.length(); ++i) {
//        array[s.at(i) -'A']++;
//    }
//
//    for (int j = s.length()-1; j >= 0; j--) {
//        if (array[s.at(j) -'A'] == 1) {
//            result = s.at(j);
//        }
//    }
//    return result;
//}

char analyseNewx(string s) {
    int array[26] = {0};
    char result = '$';

    for (int i = 0; i < s.length(); ++i) {
        array[s.at(i) -'A']++;
    }

    for (int j = s.length()-1; j >= 0; j--) {
        if (array[s.at(j) -'A'] == 1) {
            result = s.at(j);

        }
    }
    return result;
}

//char analyse(string s) {
//    for (int i = 0; i < s.length(); ++i) {
//        char rch= s.at(i);
//        bool additionalCharFound = false;
//        for (int j = 0; j < s.length(); ++j) {
//            if (i == j) continue;
//            if (rch == s.at(j)) {
//                additionalCharFound = true;
//            }
//        }
//        if (!additionalCharFound) return rch;
//    }
//    return '$';
//}

//string createString(int size) {
//    string result = "";
//    for (int i = 0; i < size; ++i) {
//        result += ('A' + rand() % 25);
//    }
//    result += "Z";
//    return result;
//}


int main() {
    clock_t start, stop;

    /*
    string s = createString(100);
    start = clock();

    char result = analyse(s);
    cout << s << endl;
    stop = clock();
    double time = (double) (stop-start) /CLOCKS_PER_SEC;
    cout << time << endl;
    */

    string s = "AABBE";
    char result = analyseNewx(s);
    cout << result << endl;

    /*
    string s = "AABBCCEFFHHZ";
    analyse(s);

    char result = analyse(s);
    cout << result << endl;
     */

    return 0;
}
