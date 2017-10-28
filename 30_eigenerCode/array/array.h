//
// Created by Anuu Thomson on 26.08.17.
//

#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H
template <class T>

class array {
private:
    T *values;
    int maxSize;
    int currentSize;

public:
    array(int size=10);
    ~array();
    array(const array & obj);
    array operator=(const array & obj);

    int size();
    void add(T value);
    T get(int index, bool & ok);
    void set(int index, T value, bool & ok);
    void remove(int index, bool & ok);
};


#endif //ARRAY_ARRAY_H
