#include <iostream>
#include <vector>
using namespace std;

class TreeUtil {
public:
    static bool isBST(vector<int> values);
    static bool upperValues(vector<int> &values, int index, int value);
    static void printMaximumPath(const vector<int> &values);
    static int calculateMaximumPath(vector<int> values, int index);
};


bool TreeUtil::upperValues(vector<int> &values, int index, int value) {
//    Abbruchbedingung
    if (index <= 0) return true;

    if (index % 2 == 0) {
//        I am right Element
        index = (index - 2) / 2;

        if (values[index] > value) {
            return false;
        }
    } else {
//        I am the left Element
        index = (index - 1) / 2;

        if (values[index] <= value) {
            return false;
        }
    }

    return upperValues(values, index, values[index]);
}

bool TreeUtil::isBST(vector<int> values) {
    for (int i = 1; i < values.size(); i++) {
        if (!upperValues(values, i, values[i])) return false;
    }
    return true;
}

int TreeUtil::calculateMaximumPath(vector<int> values, int index) {
    //Abbruchbedingung
    if (index >= values.size()) return 0;

    int indexL = index * 2 + 1;
    int indexR = index * 2 + 2;
//    cout << "L: " << indexL << endl;
//    cout << "R: " << indexR << endl;

    int leftSum = calculateMaximumPath(values, indexL);
    int rightSum = calculateMaximumPath(values, indexR);

    int pathSum = values[index] + std::max(leftSum, rightSum);

//    cout << pathSum << "\t";

    return pathSum;
}

void TreeUtil::printMaximumPath(const vector<int> &values) {
    int maxVal(0), tempVal(0);

    for (int i = 0; i < values.size(); ++i) {
        tempVal = calculateMaximumPath(values, i);
        if (maxVal < tempVal) {
            maxVal = tempVal;
        }
    }

    cout << "Max Path: " << maxVal;

}

int main() {
    vector<int> BST = {20, 12, 34, 9, 19, 29};
    bool result = TreeUtil::isBST(BST);

//    if(result) {
//        cout << "it's a BST" << endl;
//    } else {
//        cout << "it's not a BST" << endl;
//    }

    BST = {40, 100, 200, 20, 40, 70, 80, 50, 10};
//    result = TreeUtil::isBST(BST);
//
//    if(result) {
//        cout << "it's a BST" << endl;
//    } else {
//        cout << "it's not a BST" << endl;
//    }

    TreeUtil::printMaximumPath(BST);

    return 0;
}
