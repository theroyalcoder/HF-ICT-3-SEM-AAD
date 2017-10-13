#include <iostream>
using namespace std;

//Struct node erstellt, Container für 1 Wert und 1 Pointer (zeigt auf nächstes node)
struct node {
    int data;
    node* next;
};



int main() {
    node* n;
    node* t;
    node* h;

    n = new node;
    n->data = 1;

//    cout << "Adresse node " << n->data << ": \t" << n << endl;

    t = n;          //t = temp; Pointer, welches zum temporären Speichern benötigt wird
    h = n;          //h = head; Wird immer auf das erste node zeigen, damit wir wissen wo die Liste anfängt

    n = new node;
//    cout << "Adresse node 2 : \t" << n << endl;
    n->data = 2;
    t->next = n;    //next zeigt jetzt auf das zweite node
//    cout << "t->next von node 2: " << t->next << endl;
    t = n;          //t zeigt jetzt auf das zweite node
//    cout << "t: \t" << t << endl;


    n = new node;
//    cout << "Adresse node 3 :" << n << endl;
    n->data = 3;
    t->next = n;    //next zeigt jetzt auf das zweite node
//    cout << "t->next von node 3: \t " << t->next << endl;
    t = n;          //t zeigt jetzt auf das zweite node
//    cout << "t: \t" << t << endl;


    return 0;
}
