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

Node::Node(int value) : value(value), left(nullptr), right(nullptr) {
}

class BinaryTree {
private:
    Node * root;
    Node* construct(vector<int> values, int index);
    int getMaxPath(Node * node);

public:
    BinaryTree(vector<int> values);

    int getMaxTreePath();
};

BinaryTree::BinaryTree(vector<int> values) : root(nullptr)
{
    this->root = construct(values, 0);
}

Node* BinaryTree::construct(vector<int> values, int index)
{
    if (index >= values.size()) return nullptr;

    Node * node = new Node(values[index]);

    node->left = construct(values, (2 * index) + 1);
    node->right = construct(values, (2 * index) + 2);
}

int BinaryTree::getMaxPath(Node *node) {
    //Abbruchbedingung
    if (node == nullptr) return 0;

    int leftSum = getMaxPath(node->left);
    int rightSum = getMaxPath(node->right);

    int pathSum = node->value + max(leftSum, rightSum);

    return pathSum;
}

int BinaryTree::getMaxTreePath() {
    return getMaxPath(this->root);
}

class Treeutil {
public:
    static void printMaximumPath(vector<int> values);
    static int calculateMaximumPath(vector<int> values, int index, int sumL, int sumR, int sumMax);
};

void Treeutil::printMaximumPath(vector<int> values) {

    BinaryTree *tree = new BinaryTree(values);

    int maxPath = tree->getMaxTreePath();

    cout << maxPath << endl;
}

int Treeutil::calculateMaximumPath(vector<int> values, int index, int sumL, int sumR, int sumMax) {
    //Abbruchbedingung
    if (index < values.size()) {
        if (sumL > sumR) {
            cout << sumR << endl;
            return sumL;
        }
        else {
            cout << sumL << endl;
            return sumR;
        }
    }

    if (index % 2 == 0) {
        // I am the RIGHT element
        index = (index * 2) + 2;
        // values[index] = a parent element
        sumR += values[index];
    }

    if (index % 2 == 1) {
        // I am the LEFT element
        index = (index * 2) + 1;
        // values[index] = a parent element
        sumL += values[index];
    }
    //Auswahlverfahren L und R
    if (sumL > sumR) {
        //Uberprufen, ob L grosser als Max ist
        if (sumL > sumMax) {
            sumMax = sumL;
        }

    }
    else {
        //Uberprufen, ob R grosser als Max ist
        if (sumR > sumMax) {
            sumMax = sumR;
        }
    }


    return calculateMaximumPath(values, index, sumL, sumR, sumMax);
}

int main(int argc, char **argv) {
    vector<int> vec = { 30, 20, 50, 2, 29, 47, 55 };

    Treeutil tu;
    tu.printMaximumPath(vec);

    return 0;
}
