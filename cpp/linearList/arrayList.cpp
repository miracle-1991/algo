//
// Created by 计晓龙 on 7/7/23.
//

#include "arrayList.h"
#include <iostream>

template <typename T>
arrayList<T>::arrayList(int initialCapacity) {
    if (initialCapacity < 1) {
        throw illegalParameterValue();
    }
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
}

template <typename T>
arrayList<T>::arrayList(const arrayList<T> & theList) {
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    std::copy(theList.element, theList.element + listSize, element); //copy的源区间左闭右开
}

template <typename T>
bool arrayList<T>::empty() const {
    return listSize == 0;
}

template <typename T>
int arrayList<T>::size() const {
    return listSize;
}

template <typename T>
void arrayList<T>::checkIndex(int theIndex) const {
    if (theIndex < 0 || theIndex >= listSize) {
        throw illegalIndex();
    }
}

template <typename T>
T& arrayList<T>::get(int theIndex) const {
    checkIndex(theIndex);
    return element[theIndex];
}

template <typename T>
int arrayList<T>::indexOf(const T &theElement) const {
    int theIndex = (int)(std::find(element, element + listSize, theElement) - element);
    if (theIndex == listSize) {
        //not find
        return -1;
    }
    return theIndex;
}

template <typename T>
void arrayList<T>::erase(int theIndex) {
    checkIndex(theIndex);
    std::copy(element +  theIndex + 1, element + listSize, element + theIndex);
    element[--listSize].~T();
}

template <typename T>
void changeLength1D(T*& a, int oldLength, int newLength) {
    if (newLength < 0) {
        throw illegalParameterValue();
    }
    T* temp = new T[newLength];
    int number = std::min(oldLength, newLength);
    std::copy(a, a +  number, temp);
    delete [] a;
    a = temp;
}

template <typename T>
void arrayList<T>::insert(int theIndex, const T &theElement) {
    if (theIndex < 0 || theIndex > listSize) {
        throw illegalIndex();
    }
    if (listSize == arrayLength) {
        changeLength1D(element, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }
    std::copy_backward(element + theIndex, element + listSize, element + listSize + 1);
    element[theIndex] = theElement;
    listSize++;
}

template <typename T>
void arrayList<T>::output(std::ostream &out) const {
    std::copy(element, element + listSize, std::ostream_iterator<T>(std::cout, "  "));
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const arrayList<T>& x) {
    x.output(out);
    return out;
}
