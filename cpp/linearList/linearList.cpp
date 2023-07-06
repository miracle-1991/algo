//
// Created by 计晓龙 on 6/7/23.
//

#include "linearList.h"
#include <algorithm>

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

