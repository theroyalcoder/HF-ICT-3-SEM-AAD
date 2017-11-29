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
//Wichtig: Bei den Konstruktoren rot, left und right mit 0 initialisieren!!!!
Node::Node(int value) : left(nullptr), right(nullptr), value(value) {}


class BinaryTree {
private:
    Node * root;
    void insert(int v, Node * n);
    void height(Node * n, int & ch, int & max);
    void postOrder(Node * n);
    int treeSum(Node *n, int &sum);
public:
    BinaryTree();
    void insert(int v);
    int height();
    void postOrder();
    int sum();
};

BinaryTree::BinaryTree() : root(nullptr) {

}

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

void BinaryTree::height(Node *n, int &ch, int &max) {
//    todo: Herausfinden wieviel Stockwerke der Baum hat

    if (n == nullptr) {
        if (ch > max) {
            max = ch;
            return;
        }
    } else {
        ch++;
        height(n->left, ch, max);
        height(n->right, ch, max);
        ch--;
    }
}

int BinaryTree::height() {
    int ch = 0;
    int max = 0;
    height(root, ch, max);
    return max;
}

void BinaryTree::postOrder() {
    postOrder(root);
    cout << endl;
}

void BinaryTree::postOrder(Node *n) {
//Postorder (Left, Right, Root)
    if (n != 0) {
        postOrder(n->left);
        postOrder(n->right);
        cout << n->value << ",";
    }
}

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
