#include "array.h"
#include <iostream>
#include <string>

using namespace std;

class xy{
    friend std::ostream& operator<<(std::ostream& stream,xy& obj);
    int n;
};

std::ostream& operator<<(std::ostream& stream,xy& obj){//!!
    stream << obj.n;
    return stream;
}

int main(int argc,char **argv){

    Array<xy> obj;
    xy test;
    obj.add(test);
    bool ok;
    //cout << obj.get(0,ok) << endl;
    cout << test;
    return 0;
}
