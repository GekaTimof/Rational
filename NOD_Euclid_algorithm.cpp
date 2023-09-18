#include <iostream>
#include "NOD_Euclid_algorithm.h"

using namespace std;

int NOD(int a, int b) {
    a = abs(a);
    b = abs(b);

    if (a < b) {
        swap(a, b);
    }

    if (b) {
        return NOD(b, a % b);
    }
    else {
        return a;
    }
}