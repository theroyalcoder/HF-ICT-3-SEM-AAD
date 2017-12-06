#include <iostream>
#include <cstdlib>
#include <vector>
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
public:
    Node *getRoot() const;

private:
    void insert(int v, Node * n);
    void height(Node * n, int & ch, int & max);
    void postOrder(Node * n);
    int sum(Node *n);
    void printPreOrder(Node *n);
public:
    BinaryTree();
    void insert(int v);
    int height();
    void postOrder();
    int sum();
    void printPreOrder();
};

BinaryTree::BinaryTree() : root(nullptr) {
}

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
    if (n->left == nullptr && n->right == nullptr) {
        // left
        n->left = new Node(v);
    } else if (n->right == nullptr) {
        //right
        n->right = new Node(v);
    } else if (n->left != nullptr && n->right != nullptr) {
        //left
        insert(v, n->left);
    } else if (n->right != nullptr) {
        // right
        insert(v, n->right);
    }
}

void BinaryTree::insert(int v) {
    if (root == 0) {
        root = new Node(v);
    } else {
        insert(v, root);
    }
}

void BinaryTree::printPreOrder(Node *n) {
//    preOrder
    if (root == nullptr) return;

    cout << n->value << endl;

    if (n->left != nullptr) {
        printPreOrder(n->left);
    }

    if (n->right != nullptr) {
        printPreOrder(n->right);
    }
}

void BinaryTree::printPreOrder() {
    printPreOrder(root);
}

Node *BinaryTree::getRoot() const {
    return root;
}

class TreeUtil {
public :
    static void printMaximumPath(vector<int> values);
    static bool calculateMaximumPath(vector<int> &values, int index, int sum);
};

bool TreeUtil::calculateMaximumPath(vector<int> &values, int index, int sum) {
//    Abbruchbedingung -> Ende vom Baum erreicht
    if (index >= values.size()) {
//        code
        return 0;
    }

    if (index % 2 == 0) {
        // I am the right element
        index = (index * 2) + 2;
        sum = values[index];
        cout << sum << endl;
        suml = calculateMaximumPath(values, index, sum);
    } else {
        // I am the left element
        index = (index * 2) + 1;
        sum += values[index];
        cout << sum << endl;
        return calculateMaximumPath(values, index, sum);
    }
    return suml += values[index];
}

void TreeUtil::printMaximumPath(vector<int> values) {
    auto* bt = new BinaryTree();
    vector<int>::iterator it;

//    Vector in BT abfüllen
    for(it = values.begin(); it != values.end(); ++it) {
        bt->insert(*it);
    }

    for (int i = 0; i < values.size(); ++i) {
        if (!calculateMaximumPath(values, i, 0)) return;
    }



    /*
    Node = i (1)
    Node.Left = 2 · i + 1
    Node.Right = 2 · i + 2
    */

//    bt->printPreOrder();
}


int main(int argc, char **argv) {
    int values[] = {30, 20, 50, 2, 29, 47, 55};
    vector<int> vec;

//    Array in Vector abfüllen
    for (int value : values) {
        vec.push_back(value);
    }

    TreeUtil tu;
    tu.printMaximumPath(vec);

    return 0;
}
