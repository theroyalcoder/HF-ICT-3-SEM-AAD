#include <iostream>
#include <vector>
using namespace std;

class TreeUtil {
public:
    static bool isBST(vector<int> values);
    static bool upperValues(vector<int> &values, int index, int value);
};

bool TreeUtil::upperValues(vector<int> &values, int index, int value) {


    return false;
}

bool TreeUtil::isBST(vector<int> values) {

    for (int i = 1; i < values.size(); i++) {
        if (!upperValues(values, i, values[i])) return false;
    }
    return true;
}


int main() {
    vector<int> BST = {20, 12, 34, 9, 19, 29};
    auto * TU = new TreeUtil;
    TU->isBST(BST);

    return 0;
}