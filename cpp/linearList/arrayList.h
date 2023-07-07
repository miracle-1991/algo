//
// Created by 计晓龙 on 7/7/23.
//

#ifndef ALGO_ARRAYLIST_H
#define ALGO_ARRAYLIST_H
#include "linearList.h"

// implement interface
template <typename T>
class arrayList : public linearList<T> {
public:
    //构造函数、复制构造、析构函数
    explicit arrayList(int initialCapacity = 10);
    arrayList(const arrayList<T>&);
    ~arrayList() { delete [] element; }

    //抽象数据类型的方法
    bool empty() const;
    int size() const;
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(std::ostream& out) const;

    //不用override关键字标记的都是单独实现的其他方法
    int capacity() const { return arrayLength; }
protected:
    void checkIndex(int theIndex) const; //检查索引，如果索引无效，抛出异常

    T* element;         //存储线性表元素的一位数组
    int arrayLength;    //一位数组的容量
    int listSize;       //线性表的元素个数
};

#endif //ALGO_ARRAYLIST_H
