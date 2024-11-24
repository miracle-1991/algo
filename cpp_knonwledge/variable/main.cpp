//
// Created by Xiaolong Ji on 2024/11/24.
//
#include <iostream>
#include "variable.h"

using namespace std;

extern int g_v1; // if you want to use global variable defined in other file, must use extern in this fule
extern std::string fileName; // but you cannot extern static globel variable defined in other files

int local_variable() {
    int v = 10; // init every time
    v++;
    return v;
}

int static_local_variable() {
    static int v = 10; // only init once, and can only be viewed in this function
    v++;
    return v;
}

int main() {
    cout << "hello world" << endl;
    cout << g_v1 << endl; // ok
//    cout << fileName << endl; // not ok
    for (int i = 0; i < 10; i++) {
        cout << local_variable() << endl; // always 11
    }

    for (int i = 0; i < 10; i++) {
        cout << static_local_variable() << endl; // increase from 11
    }
}