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

#endif //ALGO_LINEARLIST_H
