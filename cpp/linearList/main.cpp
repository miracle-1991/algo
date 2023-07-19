//
// Created by 计晓龙 on 6/7/23.
//
#include <iostream>
#include "linearList.h"
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
}