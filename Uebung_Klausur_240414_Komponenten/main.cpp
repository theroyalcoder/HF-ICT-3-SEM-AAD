#include <iostream>
using namespace std;

class Component {
private:
    int id;
    string name;
    double price;
    Component* arr[1];
    int count = 0;
public:
//    getter
    int getID() {return id;}
    string getName() {return name;}
    double getPrice() {return price;}
    Component *const *getarr() const { return arr;}

    static int getPrice(int a){
        return arr[a]->price;
    }

//Konstruktor
    Component::Component () {
        arr[count] = this;
        count++;
    }
    Component** addComponent(Component **array, int & size);
    Component** removeComponent(int id, Component **array, int & size);
};

Component **Component::addComponent(Component **array, int &size) {


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

    return 0;
}