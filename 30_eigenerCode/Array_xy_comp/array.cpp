/*

#include "array.h"

Array::Array(int size) {
  if (size <= 10) {
    maxSize = 10;
  } else {
    maxSize = size;
  }
  currentSize = size;
  values = new int[maxSize];
}

Array::~Array() {
  //cout << "Destruktor" << endl;
  delete [] values;
}

Array::Array(const Array & obj) {
  maxSize = obj.maxSize;
  currentSize = obj.currentSize;

  values = new int [maxSize];

  for (int i = 0; i < currentSize; ++i) {
    values[i] = obj.values[i];
  }
}

Array Array::operator= (const Array & obj) {
  delete [] values;
  maxSize = obj.maxSize;
  currentSize = obj.currentSize;

  values = new int [maxSize];

  for (int i = 0; i < currentSize; ++i) {
    values[i] = obj.values[i];
  }
  return *this;
}

int Array::size() {
  return currentSize;
}

void Array::add(int value) {
  resize();
  values[currentSize] = value;
  currentSize++;
}

int Array::get(int index, bool & ok) {
  if (isIndexValid(index)) {
    ok = true;
    return values[index];
  } else {
    ok = false;
    return -1;
  }
}

void Array::set(int index, int value, bool & ok) {
  if (isIndexValid(index)) {
    ok = true;
    values[index] = value;
  } else {
    ok = false;
  }
}

void Array::remove(int index, bool & ok) {
  if (isIndexValid(index)) {
    resize();
    for (int i=index; i<currentSize-1; i++) {
      values[i] = values[i+1];
    }
    currentSize -= 1;
  } else {
    ok = false;
  }
}

bool Array::isIndexValid(int index) {
  return index >= 0 && index < currentSize;
}

void Array::resize() {
  int newSize;
  bool performResize = false;

  if (currentSize >= maxSize) {
    newSize = maxSize*2;
    performResize = true;
  } else if (currentSize <= maxSize/4 && maxSize >= 10) {
    newSize = maxSize/2;
    performResize = true;
  }

  if (performResize) {
    int *tmp = new int[newSize];
    for (int i=0; i<currentSize; i++) {
      tmp[i] = values[i];
    }
    maxSize = newSize;
    delete [] values;
    values = tmp;
  }
}
*/
