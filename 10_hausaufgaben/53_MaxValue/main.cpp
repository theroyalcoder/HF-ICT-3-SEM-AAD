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

Node::Node(int value) : value(value), left(nullptr), right(nullptr) {
}

class BinaryTree {
private:
    Node * root;
    Node* construct(std::vector<int> values, int index);
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

    Node* node = new Node(values[index]);

    node->left = construct(values, (2 * index) + 1);
    node->right = construct(values, (2 * index) + 2);

    return node;
}

int BinaryTree::getMaxPath(Node *node) {
    //Abbruchbedingung
    if (node == nullptr) return 0;

    int leftSum = getMaxPath(node->left);
    int rightSum = getMaxPath(node->right);

    int pathSum = node->value + std::max(leftSum, rightSum);

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

    BinaryTree *tree = new BinaryTree(move(values));
    //std::move is used to indicate that an object t may be "moved from", i.e. allowing the efficient transfer of resources from t to another object.

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

    //Uberprufen, ob index gerade oder ungerade ist. Wenn gerade, dann index -> rechts, sonst links
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

    //Uberprufen, ob L oder R grosser ist
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

    //Rekursivaufruf
    return calculateMaximumPath(values, index, sumL, sumR, sumMax);
}

int main(int argc, char **argv) {
    Treeutil tu;

    vector<int> vec = { 30, 20, 50, 2, 29, 47, 55 };
    tu.printMaximumPath(vec); // 30 + 50 + 55 = 135

    vec = { 40, 100, 200, 20, 40, 70, 80, 50, 10 };
    tu.printMaximumPath(vec); // 40 + 200 + 80 = 320

    return 0;
}
