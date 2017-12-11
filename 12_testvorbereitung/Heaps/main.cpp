#include <iostream>
#include <array>
#include <vector>
#include <list>

using namespace std;

class MinIntHeap {
public:
    int size = 0;
    vector<int> items;

    int getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }
    int getRightChildIndex(int parentIndex) { return 2 * parentIndex + 2; }
    int getParentIndex(int childIndex) { return (childIndex - 1) / 2; }

    bool hasLeftChild(int index) { return getLeftChildIndex(index) < size; }
    bool hasRightChild(int index) { return getRightChildIndex(index) < size; }
    bool hasParent(int index) { return getParentIndex(index) >= 0; }

    int leftChild(int index) { return items[getParentIndex(index)]; }
    int rightChild(int index) { return items[getRightChildIndex(index)]; }
    int parent(int index) { return items[getParentIndex(index)]; }

    int print() {
        for (auto i : items) {
            cout << i << "\t";
        }
    }
    int peek() {
        if (size == 0) return -1;
        return items[0];
    }

    int poll() {
        if (size == 0) return -1;
        int item = items[0];
        items[0] = items[size - 1];
        size--;
        heapifyDown();

        return item;
    }

    void add(int item) {
        items.push_back(item);
        heapifyUp();
    }

    void heapifyUp() {
        auto index = static_cast<int>(items.size() - 1);

        while (hasParent(index) && parent(index) > items[index]) {
            int tmpParent = getParentIndex(index);
            swap_h(tmpParent, index);
            index = getParentIndex(index);
        }
    }

    void swap_h(int indexOne, int indexTwo) {
        int tmp = items[indexOne];
        items[indexOne] = items[indexTwo];
        items[indexTwo] = tmp;
    }

    void heapifyDown() {
        int index = 0;

        while (hasLeftChild(index)) {
            int smallerChildIndex = getLeftChildIndex(index);
            if (hasRightChild(index) && rightChild(index) < leftChild(index)) {
                smallerChildIndex = getRightChildIndex(index);
            }

            if (items[index] < items[smallerChildIndex]) {
                break;
            } else {
                swap_h(index, smallerChildIndex);
            }
            index = smallerChildIndex;
        }
    }

};

int main() {
    auto * MIH = new MinIntHeap;
    vector<int> vec = {20, 10, 15, 17};

    for (int i : vec) {
        MIH->add(i);
    }

    MIH->print();

    MIH->add(8);
cout << endl;
    MIH->print();

    return 0;
}
