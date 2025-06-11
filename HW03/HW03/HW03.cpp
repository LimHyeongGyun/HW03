#include <iostream>
#include <vector>
#include "simpleVector.h"

using namespace std;

int main() {

    SimpleVector<int> vec;

    for (int i = 23; i > 0; i--) {
        vec.push_back(i);
    }
    vec.sortData();
    for (int i = 0; i < vec.size(); i++) {
        cout << i << "번째: " << vec[i] << endl;
    }
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    cout << "----------------------------------------------" << endl;
    SimpleVector<int> cloneVec(vec);
    for (int i = 0; i < cloneVec.size(); i++) {
        cout << i << "번째: " << cloneVec[i] << endl;
    }
    cout << cloneVec.size() << endl;
    cout << cloneVec.capacity() << endl;

    return 0;
}