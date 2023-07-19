//
// Created by 计晓龙 on 6/7/23.
//

#ifndef ALGO_LINEARLIST_H
#define ALGO_LINEARLIST_H
#include <ostream>
#include <exception>

// define interface
template <typename T>
class linearList {
public:
    virtual ~linearList() {};
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual T& get(int theIndex) const = 0;
    virtual int indexOf(const T& theElement) const = 0;
    virtual void erase(int theIndex) = 0;
    virtual void insert(int theIndex, const T& theElement) = 0;
    virtual void output(std::ostream& out) const = 0;
};

class illegalParameterValue : public std::exception {
public:
    const char * what() const noexcept override {
        return "illegalParameterValue";
    }
};

class illegalIndex : public std::exception {
public:
    const char * what() const noexcept override {
        return "illegalIndex";
    }
};

// implement interface
template <typename T>
class arrayList : public linearList<T> {
public:
    //构造函数、复制构造、析构函数
    explicit arrayList(int initialCapacity = 10);
    arrayList(const arrayList<T>&);
    ~arrayList() { delete [] element; }

    //抽象数据类型的方法
    bool empty() const override;
    int size() const override;
    T& get(int theIndex) const override;
    int indexOf(const T& theElement) const override;
    void erase(int theIndex) override;
    void insert(int theIndex, const T& theElement) override;
    void output(std::ostream& out) const override;

    //不用override关键字标记的都是单独实现的其他方法
    int capacity() const { return arrayLength; }
protected:
    void checkIndex(int theIndex) const; //检查索引，如果索引无效，抛出异常

    T* element;         //存储线性表元素的一位数组
    int arrayLength;    //一位数组的容量
    int listSize;       //线性表的元素个数
};

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
    --listSize;
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
    std::copy(element, element + listSize, std::ostream_iterator<T>(out, "  "));
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const arrayList<T>& x) {
    x.output(out);
    return out;
}

#endif //ALGO_LINEARLIST_H
