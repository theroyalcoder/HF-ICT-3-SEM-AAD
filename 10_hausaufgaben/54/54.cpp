#include <iostream>
#include <cstdlib>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>

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
    Node* construct(string input, int index);
public:
    BinaryTree(string input);
    Node *getRoot() const;
};

BinaryTree::BinaryTree(string input) : root(nullptr){
    this->construct(std::move(input), 0);
}

Node *BinaryTree::construct(string input, int index) {
    if (index >= input.size()) return nullptr;

    auto* node = new Node(input[index]);

    node->left = construct(input, (2 * index) + 1);
    node->right = construct(input, (2 * index) + 2);

    return node;
}

Node *BinaryTree::getRoot() const {
    return root;
}

class TreeUtil {
private:
    int calculate(Node *node, const string &input, int index, int *arr);
public:
    int calculate(string input);
};

int TreeUtil::calculate(Node *node, const string &input, int index, int *arr) {
    int up(0);
    //Abbruchbedingung
    //if (index >= input.size()) return 0;
    if (node == nullptr) return up;

    //todo: Uberprufen, ob input-element zwischen A - Z ist -> Alles andere wird nicht berucksichtigt!

    if (index % 2 == 0) {
        //I am the RIGHT Element
        index = 2 * index + 2;
        up = arr[input[index]]++;
    }

    if (index % 2 == 1) {
        //I am the LEFT Element
        index = 2 * index + 1;
        up = arr[input[index]]++;
    }


    calculate(node->left, input, index, arr);
    calculate(node->right, input, index, arr);

    return up;
}

int TreeUtil::calculate(string input) {
    //todo: input leerzeichen entfernen
    //input.erase(remove_if(input.begin(), input.end(), isspace), input.end());
    //Alles Grossbuchstaben machen
    transform(input.begin(), input.end(), input.begin(), ::toupper);

    //BT mit input wurde generiert
    BinaryTree* tree = new BinaryTree(input);

    //Array zum Buchstaben zaehlen
    int arr[26]{};

    for (int i = 0; i < input.size(); ++i) {
        calculate(tree->getRoot(), input, i, arr);

        /*
        if(input[i] >= 65 && input[i] <= 90) {
            calculate(tree->getRoot(), input, i, arr);
        }
         */
    }

    //Muss noch getestet werden
    sort(begin(arr), end(arr));

    int count(26);
    for (int j = 0; j < count; ++j) {
        if (arr[j] == 0) return 0;
        cout << arr[j] * count - j << endl;
    }

    /*
     * todo: "Buchstabe mit höchstem wert * 26, zweithöchste wert * 25, usw.
     * */


    return 0;
}

int main(int argc, char **argv) {
    TreeUtil tu;

    string str = "ABBCCC";
    tu.calculate(str);

//    str = "Sometimestestcasesarehardtomakeup";
//    tu.calculate(str);

    return 0;
}
