#include "quick_sort.h"

#include <iostream>
#include <vector>

using namespace std;

int pt(vector<int> &a, int li, int ri) {
    int pv = a[ri];
    int i = li;
    for (int j = li; j < ri; ++j) {
        if (a[j] < pv) {
            swap(a[j], a[i]);
            ++i;
        }
    }
    cout << "i is : " << i << "\n";
    swap(a[ri], a[i]);
    return i;
}

int quick_sort(vector<int> &a, int li, int ri) {
    cout << "li is : " << li << "ri is : " << ri << "\n";
    if (li >= ri) { return 0; }
    int s = pt(a, li, ri);
    quick_sort(a, li, s - 1);
    quick_sort(a, s + 1, ri);
}
