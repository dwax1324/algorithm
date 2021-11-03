#include <bits/stdc++.h>
using namespace std;

void Merge(int l, int mid, int r, vector<int>& v) {
    // L = l.. mid , R = mid+1..r
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = v[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = v[mid + 1 + i];
    }

    int i = 0, j = 0;
    int idx = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) v[idx] = L[i], i++;
        else
            v[idx] = R[j], j++;
        idx++;
    }
    while (i < n1) v[idx] = L[i], idx++, i++;
    while (j < n2) v[idx] = R[j], idx++, j++;
}
// [l..h] inclusive!!!
void MergeSort(int l, int r, vector<int>& v) {
    if (l < r) {
        int mid = (l + r) / 2;
        MergeSort(l, mid, v);
        MergeSort(mid + 1, r, v);
        Merge(l, mid, r, v);
    }
}