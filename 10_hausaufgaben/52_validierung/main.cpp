#include <iostream>
#include <vector>
using namespace std;

/* Implementieren Sie eine Methode, welche einen Baum in Array Form bekommt.
 * Diese Methode liefert true, falls es sich um einen bina ̈ren Suchbaum handelt.
 * Falls es lediglich ein bina ̈rer Baum ist, liefert die Methode false.
 */


class TreeUtil {
public:
    static bool isBinarySearchTree(vector<int> values);
};

bool TreeUtil::isBinarySearchTree(vector<int> values) {
//    vector<int>::iterator it;
    int posl(0), posr(0);

    for (int i = 0; i < values.size()-2; i++) {
        posl = (2 * i) + 1;
        posr = (2 * i) + 2;

        cout << "knoten: " << i << "\t" << posl << "\t" << posr << endl;

        cout << "values: " << values[i] << "\t" << values[posl] << "\t" << values[posr] << endl << endl;
        if (values[i] < values[posl]) {
            return false;
        }

        if (values[i] > values[posr]) {
            return false;
        }
    }

    return true;
}

int main() {
    int arr[6]{20, 12, 34, 9, 19, 29};
    vector<int> vec;
    vector<int>::iterator it;

    for (int i : arr) {
        vec.push_back(i);
    }

//    for (it = vec.begin(); it != vec.end(); it++) {
//        cout << *it << ", ";
//    }

    TreeUtil search;

    if (search.isBinarySearchTree(vec)) {
        cout << "It's a Binary Search Tree" << endl;
    } else {
        cout << "It's NOT a Binary Search Tree" << endl;
    }

    return 0;
}