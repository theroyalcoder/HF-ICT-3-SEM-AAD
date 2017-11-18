#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <cstdlib>
#include <iterator>
using namespace std;

string createRandomString(int n) {
    string result = "";
    for (int i = 0; i<n; i++) {
        char ch = 'A' + rand()%26;
        result += ch;
    }
    //return result;
}

int main()
{
    set<char> set1;
    string s = createRandomString(10);

    for (int i= 0; i < s.length(); i++) {
        set1.insert(s.at(i));
    }

    cout << s << endl;
    cout << set1.size() << endl;

    /*
    for(it = cc.begin(); it!=cc.end(); it++) {
        char key = it->first;
        int value = it->second;
        cout << key << ":" << value << endl;
    }
    */

    return 0;
}
