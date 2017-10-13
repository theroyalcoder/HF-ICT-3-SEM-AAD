#include <iostream>
using namespace std;

//int index = Aktuelle position

class Node {
public:
    int value;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int count; //Zählt bei jedem neuen Node auf, damit wir die grösse wissen

public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList& obj);

    int get(int index) const;
    void set(int index, int value);
    int add(int value);
    void remove(int index);
    void output(int index);
};

LinkedList::LinkedList() : head(0), tail(0), count(0) {}

LinkedList::~LinkedList() {
//    Später
}

LinkedList::LinkedList(const LinkedList& obj) {
    //Später
}

int LinkedList::get(int index) const {
    Node* n = head;

    for (int i = 0; i < index; ++i) {
        n = n->next;
    }

    return n->value;
}

void LinkedList::set(int index, int value) {
    /* - Ein neues Node wird erstellt und head zugewiesen
     * - Durch die for-Schlaufe wird im n n->next gespeichert, d.h. am Schluss der Schlaufe zeigt n auf den neusten Node
     * - Sobald n auf den neusten Node zeigt, wird dessen value gesetzt (d.h. value vom neusten Node)
     */

    Node* n = head;

    for (int i = 0; i < index; ++i) {
        n = n->next;
    }
    n->value = value;
}

int LinkedList::add(int value) {
    /* - Es wird ein neues Node erstllt
     * - value und next vom Node wird gesetzt
     * - Falls es das erste Node ist, wird head und tail gesetzt, sonst next vom Node tail und tail
     */

    Node* n = new Node;
    n->next = 0;
    n->value = value;

    if (head == 0) {
        head = n;
        tail = n;
    } else {
        tail->next = n;
        tail = n;
    }

    count++;
    return 0;
}

void LinkedList::output(int index) {
    Node* n = head;

    for (int i = 0; i < index; ++i) {
        cout << n->value << endl;
        n = n->next;
    }
}

void LinkedList::remove(int index) {
    Node *toDelete;

    if (index == 0) {
        toDelete = head;
        head = head->next;
        if (head == 0) {
            tail = 0;
        }
    } else {
        Node *tmp = head;

        for (int i=0; i<index-1; i++) {
            tmp = tmp->next;
        }

        toDelete = tmp->next;

        if (toDelete == tail) {
            tail = tmp;
        }

        tmp->next = toDelete->next;
    }

    delete toDelete;

    count--;
}

int main() {

    LinkedList obj1;
    obj1.set(1, 1);
    obj1.get(1);
    obj1.add(2);
    obj1.output(1);

    return 0;
}