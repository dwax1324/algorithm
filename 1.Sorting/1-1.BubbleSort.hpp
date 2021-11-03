#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) swap(v[j], v[j + 1]);
        }
    }
}
void bubbleSort2(vector<int> &v) {
    int n = v.size();
    while (1) {
        int swapped = false;
        for (int i = 0; i < n - 1; i++)
            if (v[i] > v[i + 1]) swap(v[i], v[i + 1]), swapped = true;
        if (!swapped) break;
    }
}
