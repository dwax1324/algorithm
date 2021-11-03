#include <bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int> &v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        int mn = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[mn]) mn = j;
        }
        swap(v[i], v[mn]);
    }
}
