#include <iostream>
using namespace std;

class Node {
public:
    Node * left;
    Node * right;
    int value;

    Node(int value);
};

//Kontruktor so und nicht anders!!!!
//left und right zeigen auf NULL (wichtig für Abfrage später in den Methoden)
//value wird mit der mitgegebenen Value initialisiert
Node::Node(int value) : left(nullptr), right(nullptr), value(value) {}


class BinaryTree {
private:
    Node * root;
    void insert(int v, Node * n);
    void height(Node * n, int & ch, int & max);
    void postOrder(Node * n);
    int treeSum(Node *n, int &summe);
public:
    BinaryTree();
    void insert(int v);
    int height();
    void postOrder();
    int sum();
};

//Wichtig: Mit nullptr initialisieren
BinaryTree::BinaryTree() : root(nullptr) {

}

//Methode: Fügt ein Node mit dem mitgegebenen Value ein
void BinaryTree::insert(int v, Node *n) {

//    Falls int v kleiner als der value vom jetzigen Node ist, dann soll int v links vom node gespeichert werden
    if (v < n->value) {
//        left
//        Überprüfen ob der linke node leer ist
        if (n->left != nullptr) {
//            Links kein Platz, deshalb rekursiv aufruf n->left mitgeben
            insert(v, n->left);
        } else {
//            Links ist leer, Node kann erstellt und int v eingefügt werden
            n->left = new Node(v);
        }
    } else {
//        right
//        Überprüfen ob der rechte node leer ist
        if (n->right != nullptr) {
//            Rechts kein Platz, deshalb rekursiv aufruf n->left mitgeben
            insert(v, n->right);
        } else {
//            Rechts ist leer, Node kann erstellt und int v eingefügt werden
            n->right = new Node(v);
        }
    }
}

void BinaryTree::insert(int v) {
//    Falls es noch keine Nodes gibt, dann wird ein Node erstellt, sonst rekursive Methode erstellt
    if (root == nullptr) {
        root = new Node(v);
    } else {
        insert(v, root);
    }
}

//    Herausfinden wieviel "Stockwerke" der Baum hat
void BinaryTree::height(Node *n, int &ch, int &max) {
//    ch heisst current height: jetzige Höhe
//    Wir gehen zuerst bis zum letzten linken Node, danach zum letzten rechten Node.
//    Danach gehen wir wieder zurück zum root

//    Falls n gleich nullptr ist, dann sind wir am Ende angekommen
    if (n == nullptr) {
        if (ch > max) {
            max = ch;
            return;
        }
    } else {
//        Stockwerk erhöht
        ch++;
        height(n->left, ch, max);
        height(n->right, ch, max);
//        Stockwerk verringert, da die rekursive Methode endet und wir den Stockwerk wieder verlassen
        ch--;
    }
}

int BinaryTree::height() {
    int ch = 0;
    int max = 0;
    height(root, ch, max);
    return max;
}

//Postorder Ausgabe
void BinaryTree::postOrder(Node *n) {
//Postorder (Left, Right, Root)
    if (n != nullptr) {
        postOrder(n->left);
        postOrder(n->right);
        cout << n->value << ",";
    }
}

void BinaryTree::postOrder() {
    postOrder(root);
    cout << endl;
}

//Geht durch den ganzen Baum und zählt alle Werte zusammen und gibt sie zurück
int BinaryTree::treeSum(Node *n, int &summe) {
    if (n!= nullptr) {
        summe += n->value;
        treeSum(n->left, summe);
        treeSum(n->right, summe);
    }

    return summe;
}

int BinaryTree::sum() {
    int sumsum(0);
    return treeSum(root, sumsum);
}

int main() {
    BinaryTree bt;
    int values[] = {30, 20, 50, 2, 29, 47, 55};
    int sum = 0;

    for (auto i : values) {
        bt.insert(i);
        sum += i;
    }

    bt.postOrder();
    cout << "summe: " << sum << endl;
    cout << "summe: " << bt.sum() << endl;

    cout << "height:" << bt.height() << endl;

//    bt.printLeaves();
    return 0;
}
