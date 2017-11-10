#include <iostream>
#include <vector>

using namespace std;

class TreeUtil {
public:
    static bool isBinarySearchTree(vector<int> values);
    static bool upperValues(vector<int> &values, int index, int value);
};

bool TreeUtil::upperValues(vector<int> &values, int index, int value) {
    //Abbruchbedingung
    if (index <= 0) return true;

    //Herausfinden, ob "Knoten" links oder rechts im Baum ist -> Mithilfe von Formel von Sheet 5.2
    if (index % 2 == 0) {
        // I am the right element
        //Formel
        index = (index - 2) / 2;

        // values[index] = a parent element
        //Parent element wird mit "jetzigem" element gecheckt, wenn childknoten kleiner ist, dann falsch
        if (values[index] > value) {
            return false;
        }

    } else {
        // I am the left element
        //Formel
        index = (index - 1) / 2;
        // values[index] = a parent element
        //Parent element wird mit "jetzigem" element gecheckt, wenn childknoten grösser ist, dann falsch
        if (values[index] <= value) {
            return false;
        }
    }

    //Rekursivaufruf
    return upperValues(values, index, value);
}

bool TreeUtil::isBinarySearchTree(vector<int> values) {
    //Wieso kann man ersten Knoten überspringen??
    for (int i = 1; i < values.size(); i++) {
        if (!upperValues(values, i, values[i])) return false;
    }
    return true;
};

int main() {
    bool result;
    vector<int> values = {100, 50, 150, 25, 75, 125, 175, 12, 37, 62, 87, 112, 137, 162, 187, 10, 14, 35, 39, 60, 64,
                          85, 89, 110, 114, 135, 139, 160, 164, 185, 189, 9, 11, 13, 15, 34, 36, 38, 40, 59, 61, 63, 65,
                          84, 86, 88, 90, 109, 111, 113, 115, 134, 136, 138, 140, 159, 161, 163, 165, 184, 186, 188,
                          190};

    result = TreeUtil::isBinarySearchTree(values);

    if (result) {
        cout << "It's a SearchTree" << endl;
    } else {
        cout << "It's not a SearchTree" << endl;
    }

    return 0;
}