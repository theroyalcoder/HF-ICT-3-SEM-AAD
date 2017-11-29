#include <iostream>
#include <array>
#include <tclDecls.h>

using namespace std;

class PriorityQueue {
private:
    array<int, 1000> values;
    int value;
public:
    PriorityQueue(const array<int, 1000> &values, int size);
    bool insert(int value, array<int, 1000> values, int index);
    bool insert(int value);
    int extractMin();

    int size();
};

PriorityQueue::PriorityQueue(const array<int, 1000> &values, int size) : values(values), value(value) {}

bool PriorityQueue::insert(int value, array<int, 1000> values, int index) {
    if (index % 2 == 0) {
        // I am the right element
        index = (index - 2) / 2;

        //info: values[index] = a parent element
        if (values[index] == 0) {
            values[index] = value;
        } else {
            insert(value, values, index);
        }

    } else {
        // I am the left element
        index = (index - 1) / 2;
        //info: values[index] = a parent element

        if (values[index] == 0) {
            values[index] = value;
        } else {
            insert(value, values, index);
        }


    }
}


void PriorityQueue::insert(int value) {
    if (this->values[0] == -1) {
        this->values[0] = value;
    } else {
        insert(value, values, 0);
    }


}

int PriorityQueue::extractMin() {

    return 0;
}

int PriorityQueue::size() {

    return 0;
}

int main() {
    array<int, 1000> values{-1};
    int size = 0;

    for (int i = 0; i < 10; ++i) {
        values[i] = rand() % 100;
        cout << values[i] << "\t";
        size++;
    }

    cout << "size: " << size;

    auto pq = new PriorityQueue(values, size);
    pq->insert(4);

    return 0;
}