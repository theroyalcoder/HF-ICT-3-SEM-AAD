#include <iostream>
#include <cstdlib>
#include "stdc++.h"
using namespace std;

class Node {
public:
    Node * left;
    Node * right;
    int value;
    Node(int value);
};

Node::Node(int value) : value(value), left(0), right(0) {
}

class BinaryTree {
private:
    Node * root;
    void insert(int v, Node * n);
    void height(Node * n, int & ch, int & max);
    void postOrder(Node * n);
    int sum(Node *n);
    void printLeaves(Node *n);
    void printLeaves(Node *n, vector<int> &vec);
    int getAnchestor(int value, Node * n, int anchestor);
public:
    BinaryTree();
    void insert(int v);
    int height();
    void postOrder();
    int sum();
    void printLeaves();
    int getAnchestor(int value);
};

int BinaryTree::sum(Node *n) {
    if (n == 0) return 0;
    int v = n->value;
    return sum(n->left) + v + sum(n->right);
}

int BinaryTree::sum() {
    return sum(root);
}

void BinaryTree::postOrder() {
    postOrder(root);
    cout << endl;
}

void BinaryTree::postOrder(Node * n) {
    if (n != 0) {
        postOrder(n->left);
        postOrder(n->right);
        cout << n->value << ",";
    }
}

int BinaryTree::height() {
    int ch = 0;
    int max = 0;
    height(root, ch, max);
    return max;
}

void BinaryTree::height(Node * n, int & ch, int & max) {
    if (n == 0) {
        if (ch > max) {
            max = ch;
        }
    } else {
        ch++;
        height(n->left, ch, max);
        height(n->right, ch, max);
        ch--;
    }
}

void BinaryTree::insert(int v, Node * n) {
    if (v < n->value) {
        // left
        if (n->left == 0) {
            n->left = new Node(v);
        } else {
            insert(v, n->left);
        }
    } else {
        // right
        if (n->right == 0) {
            n->right = new Node(v);
        } else {
            insert(v, n->right);
        }
    }
}

void BinaryTree::insert(int v) {
    if (root == 0) {
        root = new Node(v);
    } else {
        insert(v, root);
    }
}

BinaryTree::BinaryTree() : root(0) {
}

void BinaryTree::printLeaves(Node *n) {
    if (n == 0) return;

    if (n->left == 0 && n->right == 0) {
        cout << n->value << endl;
        return;
    } else {
        printLeaves(n->left);
        printLeaves(n->right);
    }
}

void BinaryTree::printLeaves(Node *n, vector<int> &vec) {
    //todo: pop_back funktioniert nicht richtig
    if (n == 0) return;
    vector<int>::iterator it;

    vec.push_back(n->value);

    if (n->left == 0 && n->right == 0) {
        cout << n->value << endl;

        if(vec.size() == 1) {
            cout << vec[0];
        } else {
            for (it = vec.begin(); it != vec.end(); it++) {
                cout << *it << ", ";
            }
            cout << endl;
        }

        vec.pop_back();

        return;
    } else {
        printLeaves(n->left, vec);
        printLeaves(n->right, vec);
    }
}

void BinaryTree::printLeaves() {
//    printLeaves(root);
    vector<int> vec;

    printLeaves(root, vec);
}

int BinaryTree::getAnchestor(int value) {
    getAnchestor(value, root, 999);
    return 0;
}

int BinaryTree::getAnchestor(int value, Node *n, int anchestor) {
    //Tree is emtpy
    if (n == 0) return 0;

    //Value found
    if (n->value == value) return anchestor;

    if (n->left) {
        anchestor = n->value;
        getAnchestor(value, n->left, anchestor);
    }

    if (n->right){
        anchestor = n->value;
        getAnchestor(value, n->right, anchestor);
    }

    return anchestor;
}


int main(int argc, char **argv) {
    BinaryTree bt;
    int values[] = {30, 20, 50, 2, 29, 47, 55};
    int sum = 0;
    for (int value : values) {
        bt.insert(value);
        sum += value;
    }
//    cout << sum << endl;
//    cout << bt.sum() << endl;

//    bt.printLeaves();

    cout << bt.getAnchestor(2);

    return 0;
}
