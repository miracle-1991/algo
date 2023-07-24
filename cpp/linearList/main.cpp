//
// Created by 计晓龙 on 6/7/23.
//
#include <iostream>
#include "linearList.h"
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    linearList<int>* gpsListPtr = new arrayList<int>();

    gpsListPtr->insert(0, 101);
    gpsListPtr->insert(1,102);
    gpsListPtr->insert(1, 103);

    if (!gpsListPtr->empty()) {
        cout << "element in index 1: " << gpsListPtr->get(1) << endl;
        cout << "size: " << gpsListPtr->size() << endl;
        gpsListPtr->erase(1);
        cout << "size after erase: " << gpsListPtr->size() << endl;
    }
    delete gpsListPtr;

    arrayList<int> a;
    a.insert(0,1);
    a.insert(0, 2);
    a.insert(0, 3);
    reverse(a.begin(), a.end());
    for (arrayList<int>::iterator ite = a.begin(); ite != a.end(); ite++) {
        cout << *ite << endl;
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    cout << sum << endl;
}