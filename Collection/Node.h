//
// Created by Anuu Thomson on 18.10.17.
//

#ifndef COLLECTION_NODE_H
#define COLLECTION_NODE_H

#include <iostream>
#include "Collection.h"
#include "array.h"
#include "LinkedList.h"
using namespace std;

template <class T>
class Node {
public:
    T value;
    Node<T> * next;
};

#endif //COLLECTION_NODE_H
