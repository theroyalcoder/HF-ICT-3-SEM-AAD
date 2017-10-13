#ifndef ARRAY_H
#define ARRAY_H

template <class T>
class Array {
private:
    T *values;
    int maxSize;
    int currentSize;

    void resize();
    bool isIndexValid(int index);

public:
    Array(int size=0);

    ~Array(); // oetterli, nagaratnam
    Array(const Array & obj); // bruderer, kugler
    Array operator= (const Array & obj);

    int size(); // holm, cakan
    void add(T value); // gasser, buergi
    T get(int index, bool & ok); // grolimund, bieli
    void set(int index, T value, bool & ok); // perepelin, christeller
    void remove(int index, bool & ok); // datti
};

template <class T>
Array<T>::Array(int size) {
  if (size <= 10) {
    maxSize = 10;
  } else {
    maxSize = size;
  }
  currentSize = size;
  values = new T[maxSize];
}

template <class T>
Array<T>::~Array() {
  //cout << "Destruktor" << endl;
  delete [] values;
}

template <class T>
Array<T>::Array(const Array & obj) {
  maxSize = obj.maxSize;
  currentSize = obj.currentSize;

  values = new T [maxSize];

  for (int i = 0; i < currentSize; ++i) {
    values[i] = obj.values[i];
  }
}

template <class T>
Array<T> Array<T>::operator= (const Array<T> & obj) {
  delete [] values;
  maxSize = obj.maxSize;
  currentSize = obj.currentSize;

  values = new T [maxSize];

  for (int i = 0; i < currentSize; ++i) {
    values[i] = obj.values[i];
  }
  return *this;
}

template <class T>
int Array<T>::size() {
  return currentSize;
}

template <class T>
void Array<T>::add(T value) {
  resize();
  values[currentSize] = value;
  currentSize++;
}

template <class T>
T Array<T>::get(int index, bool & ok) {
  if (isIndexValid(index)) {
    ok = true;
    return values[index];
  } else {
    ok = false;
  }
}

template <class T>
void Array<T>::set(int index, T value, bool & ok) {
  if (isIndexValid(index)) {
    ok = true;
    values[index] = value;
  } else {
    ok = false;
  }
}

template <class T>
void Array<T>::remove(int index, bool & ok) {
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

template <class T>
bool Array<T>::isIndexValid(int index) {
  return index >= 0 && index < currentSize;
}

template <class T>
void Array<T>::resize() {
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
    T *tmp = new T[newSize];
    for (int i=0; i<currentSize; i++) {
      tmp[i] = values[i];
    }
    maxSize = newSize;
    delete [] values;
    values = tmp;
  }
}


#endif