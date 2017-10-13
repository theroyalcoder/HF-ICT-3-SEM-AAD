//
// Created by Anusanth Nagaratnam & Patrick Oetterli on 26.08.17.
//

#include "array.h"

array::array(int size): currentSize(size), maxSize(size) {
values = new int[size];
}

array::~array() {
    delete [] values;
}

array::array(const array &obj) {

}

array array::operator=(const array &obj) {
    return array();
}

int array::size() {
    return 0;
}

void array::add(int value) {

}

int array::get(int index, bool &ok) {
    return 0;
}

void array::set(int index, int value, bool &ok) {

}

void array::remove(int index, bool &ok) {

}
