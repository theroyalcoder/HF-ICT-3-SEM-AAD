#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node * left;
    Node * right;
    int value;

    Node(int value);
};

//Kontruktor so und nicht anders!!!!
//Wichtig: Bei den Konstruktoren rot, left und right mit 0 initialisieren!!!!
Node::Node(int value) : left(nullptr), right(nullptr), value(value) {}


class BinaryTree {
private:
    Node * root;
    void insert(int v, Node * n);
    bool isBST(Node *n);
public:
    BinaryTree();
    void insert(int v);
    bool isBST();
};

bool BinaryTree::isBST(Node *n) {
//    todo: DFS Algo bis zum Ende gehen, schauen ob jetziger Node kleiner ist als Node oben dran
//    todo: BFS Algo immer Links gehen und schauen ob "Node left" kleiner ist als "Node i"

    



    return false;
}

bool BinaryTree::isBST() {
    isBST(root);

    return false;
}

BinaryTree::BinaryTree() : root(nullptr) {}

void BinaryTree::insert(int v, Node *n) {
//    todo: Überprüfen, ob v grösser oder kleiner als n->value ist, damit man es rechts oder links einfügen kann


    if (v < n->value) {
//        left
        if (n->left != nullptr) {
//            v ist kleiner als n->value, aber links kein Platz, deshalb rekursiv aufruf und n->left mitgeben
            insert(v, n->left);
        } else {
//            v ist kleiner als n->value, hat platz
            n->left = new Node(v);
        }
    } else {
//        right
        if (n->right != nullptr) {
            insert(v, n->right);
        } else {
            n->right = new Node(v);
        }
    }
}

void BinaryTree::insert(int v) {
    if (root == nullptr) {
        root = new Node(v);
    } else {
        insert(v, root);
    }
}


int main() {
    BinaryTree bt;
    int values[] = {20, 12, 34, 9, 19, 29};

    for (auto i : values) {
        bt.insert(i);
    }

    if (bt.isBST()) {
        cout << "It's a BST" << endl;
    } else {
        cout << "Its' not a BST" << endl;
    }


    return 0;
}