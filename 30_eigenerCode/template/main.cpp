#include <iostream>
using namespace std;
template <class T>

T getSmallest(T *array, int size) {
    T check = array[0];

    for (int i = 0; i < size; ++i) {
        if (array[i] < check) {
            check = array[i];
        }
    }
    return check;
}

class MyClass {
public:
    int getX() const;
    void setX(int x);
    bool operator<(const MyClass &obj);
private:
    int x;
};

int MyClass::getX() const {
    return x;
}

void MyClass::setX(int x) {
    this->x = x;
}

bool MyClass::operator<(const MyClass & obj) {
    return x < obj.x;
}

int main() {
    srand(time(NULL));
    int iArray[] {1, 2, 3, 4};
    int iminElement = getSmallest<int>(iArray, 4);
//    cout << iminElement << endl;

    char cArray[] = {'a', 'b', 'c', 'd'};
    char cminElement = getSmallest <char>(cArray, 4);
//    cout << cminElement << endl;

    float fArray[] = {1.22, 5, 2.55, 66};
    float fminElement = getSmallest(fArray, 4);
//    cout << fminElement << endl;

    string sArray[] = {"Hey", "Treppe", "ich", "ist", "strinfreak"};
    string sminElement = getSmallest<string>(sArray, 5);
//    cout << sminElement << endl;

    MyClass mcArray[5];
    for (int i = 0; i < 5; ++i) {
        mcArray[i].setX(rand()%1000);
    }
    MyClass mcminElement = getSmallest<MyClass>(mcArray, 5);

    cout << mcminElement.getX() << endl;
    return 0;
}
