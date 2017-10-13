#include <iostream>

using namespace std;

#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node * next;

};

class LinkedList {
private:
    Node * head;
    Node * tail;

    bool isIndexValid(int index);
public:

    LinkedList();

    int size();
    void add(int value);
    int get(int index, bool & ok);
    void set(int index, int value, bool & ok);
    void remove(int index, bool & ok);
    friend std::ostream& operator<<(std::ostream& stream, const LinkedList& obj);
};

LinkedList::LinkedList() : head(0), tail(0) {
}

void LinkedList::add(int value) {
    Node *n = new Node();
    n->value = value;
    n->next = 0;

    if (head == 0) {
        head = n;
        tail = n;
    } else {
        tail->next = n;
        tail = n;
    }
}
std::ostream& operator<<(std::ostream& stream, const LinkedList& obj) {

    stream << "Head = " << obj.head << endl;
    stream << "Tail = " << obj.tail << endl;

    stream << endl;
    stream << "===============================" << endl;
    Node *tmp = obj.head;
    int index = 0;
    while(tmp != 0){
        stream << "===============================" << endl;
        stream << "Index: " << index << endl;
        stream << "MyAdress = " << tmp << endl;
        stream << "MyValue = " << tmp->value<< endl;
        stream << "MyNext = " << tmp->next << endl;
        stream << "===============================" << endl;
        index++;
        tmp = tmp ->next;
    }
    return stream;
}
int main(int argc, char **argv) {

    LinkedList obj;

    for (int i= 0; i < 10;i++){
        obj.add(i);
    }

    cout << obj;

    return 0;
}