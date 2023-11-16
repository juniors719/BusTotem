#include <iostream>

#include "tads/ForwardList.h"

using namespace std;

int main() {
    ForwardList<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    while (!lst.empty()) {
        cout << lst.front() << endl;
        lst.pop_front();
    }
}