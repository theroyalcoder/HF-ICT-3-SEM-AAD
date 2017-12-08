#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <ctime>
#include <string>
using namespace std;


int longestChar(string input) {
    int ascii[255]{0};
    int output = 0;

    cout << "Input: \t" << input << endl;

    for (int i = 0; i < input.size(); ++i) {
        ascii[input[i]] += 1;
    }

    for (int j = 0; j < 255; ++j) {
        if (ascii[j] > output) {
            output = ascii[j];
        }
    }
    return output;

}


/*
bool wordGame(string s1, string s2) {
    cout << "Input s1: " << s1 << endl;
    cout << "Input s2: " << s2 << endl;

    map<string, int> myMap;
    map<string, int>::iterator iter;
    map<string, int> myMap2;
    map<string, int>::iterator iter2;
    char space = ' ';
    unsigned long pos = s1.find(space);
    unsigned long initialPos = 0;

//  Einzelne woerter in map einfuellen von s1
    while(pos != std::string::npos) {
        myMap.find(s1.substr(initialPos, pos - initialPos + 1))->second += 1;

        myMap.insert(pair<string, int>(s1.substr(initialPos, pos - initialPos + 1), 1));
        initialPos = pos + 1;

        pos = s1.find( space, initialPos );
    }

    // Add the last one
    myMap.find(s1.substr(initialPos, pos - initialPos + 1))->second += 1;
    myMap.insert(pair<string, int>(s1.substr( initialPos, std::min( pos, s1.size() ) - initialPos + 1 ), 1));

    //  Einzelne woerter in map einfuellen von s2
    pos = s2.find(space);
    initialPos = 0;

    while(pos != std::string::npos) {
        myMap2.find(s2.substr(initialPos, pos - initialPos + 1))->second += 1;

        myMap2.insert(pair<string, int>(s2.substr(initialPos, pos - initialPos + 1), 1));
        initialPos = pos + 1;

        pos = s2.find( space, initialPos );
    }

    // Add the last one
    myMap2.find(s2.substr(initialPos, pos - initialPos + 1))->second += 1;
    myMap2.insert(pair<string, int>(s2.substr( initialPos, std::min( pos, s2.size() ) - initialPos + 1 ), 1));


//    // loop through elements
//    for (iter=myMap.begin(); iter!=myMap.end(); iter++) {
//        string key = iter->first;
//        int value = iter->second;
//    }


//    For-Schleife zum vergleichen von den beiden maps, Zeit hat nicht gereicht
    /*for (iter2 = myMap2.begin(); iter2 != myMap2.end(); iter2++) {
        if (iter->second == myMap.find(iter->second)) {
        }
    }*/


    /*
//    Output s1
    for (iter = myMap.begin(); iter != myMap.end(); ++iter) {
        cout << "string: " << iter->first << "\t" << "value: " << iter->second << endl;

    }

    cout << endl;

//    Output s2
    for (iter2 = myMap2.begin(); iter2 != myMap2.end(); ++iter2) {
        cout << "string: " << iter2->first << "\t" << "value: " << iter2->second << endl;

    }

    return true;

}
*/


class Pair {
public:
    int min, max;
    Pair(int MIN, int MAX);

    void setMin(int min);
    void setMax(int max);
    int getMin() const;
    int getMax() const;

    friend ostream &operator << (ostream &output, Pair &obj){
        output << "Max: " << obj.max;
        output << ", Min: " << obj.min << endl;
        return output;
    }
};
Pair::Pair(int MIN, int MAX) {
    Pair::min = MIN;
    Pair::max = MAX;
}
void Pair::setMin(int min) {
    Pair::min = min;
}
void Pair::setMax(int max) {
    Pair::max = max;
}
int Pair::getMin() const {
    return min;
}
int Pair::getMax() const {
    return max;
}
Pair getMinMax(vector<int> values) {
    vector<int>::iterator iter_v;
    int max(0);
    int min(0);
    Pair obj(0, 0);

//    Sort the vector
    sort(values.begin(), values.end());


    //    Addition max
    for (iter_v=values.end()-1; iter_v!=values.end()-5; iter_v--) {
        max += *iter_v;
    }

    cout << "Max: " << max;


//    Addition min
    for (iter_v=values.begin(); iter_v!=values.begin()+4; iter_v++) {
        min += *iter_v;
    }
    cout << ", Min: " << min << endl;

//    Set and Get Min and Max
//    obj.setMin(min);
//    obj.setMax(max);
//    obj.getMin();
//    obj.getMax();

    return obj;
}

void getMinMaxTest() {
  int v1V [] = {1,2,3,4,5};
  vector<int> v1;
  for (int i=0; i<5; i++) {
    v1.push_back(v1V[i]);
  }
  Pair res = getMinMax(v1);
  cout << res.min << "," << res.max << endl;
  
  int v2V [] = {-1,-2,-3,4,-5};
  vector<int> v2;
  for (int i=0; i<5; i++) {
    v2.push_back(v2V[i]);
  }
  res = getMinMax(v2);
  cout << res.min << "," << res.max << endl;
  
  int v3V [] = {0, 0, 0, 0, 1};
  vector<int> v3;
  for (int i=0; i<5; i++) {
    v3.push_back(v3V[i]);
  }
  res = getMinMax(v3);
  cout << res.min << "," << res.max << endl;
}

void longestCharTest() {
  cout << longestChar("avvgfbbbbedd") << endl;
  cout << longestChar("aaabbbcccddd") << endl;
  cout << longestChar("") << endl;
  cout << longestChar("abc") << endl;
  cout << longestChar("abbc") << endl;
  cout << longestChar("abcdddeff") << endl;
}


int main(int argc,char **argv) {
  
  //getMinMaxTest();
  longestCharTest();
  
  /*
//    Aufgabe 1
    cout << "Aufgabe 1" << endl;

    int num = 0;

    num = longestChar("avvgfbbbbbedd");
    cout << "Output: " << num << endl;

    num = longestChar("aaabbbcccddd");
    cout << "Output: " << num << endl;

    num = longestChar("aaaafsflsdhgearkgjnasjk2345678&//&BBBBBB&+ç/57");
    cout << "Output: " << num << endl;


//    Aufgabe 2
    cout << endl << "Aufgabe 2" << endl;

    string s1 = "Heute ist ein schoener tag tag tag toll";
    string s2 = "heute tag super";
    wordGame(s1, s2);

//    string s3 = "heute tag tag";
//    wordGame(s1, s3);

//    Aufgabe 3
    cout << endl << "Aufgabe 3" << endl;

    
    vector<int> value;
    Pair obj(0, 0);

    for (int i = 0; i < 5; ++i) {
        value.push_back(i+1);
    }

    getMinMax(value);

    cout << obj;
*/
    return 0;
}