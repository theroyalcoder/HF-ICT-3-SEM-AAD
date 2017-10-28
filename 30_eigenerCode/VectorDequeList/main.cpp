#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <map>
#include <queue>
using namespace std;

int main() {
    deque<int> deque1;

    // insert at the end
    deque1.push_back(rand());

    // insert at the start
    deque1.push_front(rand());

    // loop through elements
    deque<int>::iterator iter1;
    for (iter1=deque1.begin(); iter1!=deque1.end(); iter1++) {
        cout << *iter1 << endl;
    }

    vector<int> vector1;

    // insert at the end
    vector1.push_back(rand());

    // delete at a specific position
    auto iter2_d = vector1.begin();
    vector1.erase(iter2_d);

    // loop through elements
    vector<int>::iterator iter2;
    for (iter2=vector1.begin(); iter2!=vector1.end(); iter2++) {
        cout << *iter2 << endl;
    }

    list<int> list1;

    // insert at the end
    list1.push_back(rand());

    // insert at the start
    list1.push_front(rand());

    // insert at a specific position
    auto iter3_l = list1.begin(); iter3_l++;
    list1.insert(iter3_l, rand ( ) ) ;

    // loop through elements
    list<int>::iterator iter3;
    for (iter3=list1.begin(); iter3!=list1.end(); iter3++) {
        cout << *iter3 << endl;
    }


    map<int, string> Mapname;

    // insert
    Mapname[0] = "HERZIG";
    Mapname[1] = "BALE";
    Mapname[0] = "WAYNE"; // old value will be overwritten

    pair<map<int , string>::iterator, bool> ret;
    ret = Mapname.insert(pair<int , string>(2, "PARKER"));

    // ret.second is true
    ret = Mapname.insert(pair<int , string>(2, "CLARK")); // ret .second is false , because key 2 already exists

    // loop through elements
    map<int , string>::iterator iter;

    for (iter=Mapname.begin(); iter!=Mapname.end(); iter++) {
        int key  = iter->first;
        string value = iter->second;
    }

    for (iter = Mapname.begin(); iter != Mapname.end(); ++iter) {
        cout << iter->first << endl;
        cout << iter->second << endl;

    }

    class Queue {
    private :
        Klassenname values; // stack based queue private :
        Queue();
        Queue(const Klassenname & obj);
        Queue operator= (const Queue& obj);
        virtual ~Queue();
        bool deque( int & value);
        bool enque( int value);
        bool front( int & value);
        bool back( int & value);
        int size();
        bool isEmpty ( ) ;
    };

    class Klassenname {
    private :
        int *values; // array based stack int maxNumberOfElement ;
        int index ;
    private :
        Klassenname();
        Klassenname(const Klassenname & obj);
        Klassenname operator= ( const Klassenname & obj ) ; virtual ~Klassenname ( ) ;
        bool pop(int & value);
        bool push( int value);
        bool top(int & value);
        int size();
        bool isEmpty();
    };

    Klassenname Klassenname::operator= (const Klassenname& b) {

            this->length = b.length;
            this->breadth = b.breadth;
            this->height = b.height;

            return *this;
        }

    return 0;
};
