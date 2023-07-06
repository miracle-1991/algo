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
    arrayList(int initialCapacity = 10);
    arrayList(const arrayList<T>&);
    ~arrayList() { delete [] element; }

    //抽象数据类型的方法
    bool empty() const override { return listSize == 0; }
    int size() const override { return listSize; }
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

#endif //ALGO_LINEARLIST_H
