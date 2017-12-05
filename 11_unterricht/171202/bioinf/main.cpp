#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <map>
using namespace std;

string generateDNA(int size) {
    vector<char> v = {'A', 'C', 'G', 'T'};
    string result = "";
    for (int i=0; i<size; i++) {
        int r = rand() % v.size();
        result += v[r];
    }
    return result;
}

int match(string t, const string &p) {

    for (int i=0; i<t.size()-p.size()+1; i++) {
        string s = "";
        for (int j=0; j<p.size(); j++) {
            s += t[i+j];
        }

        if (s == p) {
            return i;
        }
    }
    return -1;
}

int bm(string t, const string &p) {
    // create map, preprocess pattern
    map<char, int> m;


    for (int k = 0; k < p.size(); ++k) {
        m.insert (pair<char,int>(p[k],k));
//        m.insert (pair<char,int>(p[k],p.size()-k-1));
    }

//    Testausgabe
    for (auto i : m) { cout << i.first << "\t" << i.second << endl; }

    for (int i = 0; i < t.size() - p.size() + 1; i++) {
        string s = "";
        for (int j = 0; j < p.size(); j++) {
            s += t[i+j];
        }

//        if (s[s.size()-1] == ) {
//
//        }

        cout << s << endl;
    }
    return -1;
}


int main(int argc, char **argv) {

    //string t = generateDNA(100000000);
    //string p = "GATGTAAGTATTA";

    string t = "er sagte abrakadabra aber";
    string p = "aber";

    clock_t start, stop;

    start = clock();
    int pos = bm(t, p);
    stop = clock();

    cout << pos << endl;
    cout << (double)(stop-start)/CLOCKS_PER_SEC << endl;

    return 0;
}

