#include <iostream>
using namespace std;

class Component {
private:
    int id;
    string name;
    double price;
    int maxSize;
public:
//    getter
    int getID() {return id;}
    string getName() {return name;}
    double getPrice() {return price;}
    Component(int id, int maxSize, const string &name, double price, Component** arr);
    Component** addComponent(Component **array, int & size);
    Component** removeComponent(int id, Component **array, int & size);
};

Component::Component(int id, int maxSize, const string &name, double price, Component** arr) {
    Component::id = id;
    Component::price = price;
    Component::maxSize = maxSize;
    this->maxSize = 10;
    arr[this->maxSize];
    arr[id] = this;
}

Component **Component::addComponent(Component **array, int &size) {
    array[this->id+1] = this;

    return array;
}

Component **Component::removeComponent(int id, Component **array, int &size) {
    array[id] = nullptr;

    for (int i = id; i < size-1; ++i) {
        array[i] = array[i+1];
    }

    return array;
}

int main() {
    int ID(0), SIZE(10);
    string NAME;
    double PRICE;
    Component *arr = new Component[SIZE]{};



    arr->addComponent(&arr, SIZE);

    if (ID == 0 && SIZE == 0) {
        arr[5].removeComponent(ID, &arr, SIZE);
    }

    cout << arr->getPrice();


    return 0;
}