#include <bits/stdc++.h>
using namespace std;

int Partition(int l, int r, vector<int>& v) {
    int pivot = v[r];  // r pivot
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (v[j] <= pivot) i++, swap(v[i], v[j]);
    }
    swap(v[i + 1], v[r]);
    return i + 1;
}

void QuickSort(int l, int r, vector<int>& v) {
    if (l < r) {
        int mid = Partition(l, r, v);
        QuickSort(l, mid - 1, v);
        QuickSort(mid + 1, r, v);
    }
};

int Partition2(int l, int r, vector<int>& v) {
    int pivot = v[(l + r) / 2];
    while (l <= r) {
        while (v[l] < pivot) l++;
        while (v[r] > pivot) r--;
        if (l <= r) {
            swap(v[l], v[r]);
            l++, r--;
        }
    }
    return l;
}

void QuickSort2(int l, int r, vector<int>& v) {
    int part2 = Partition2(l, r, v);
    if (l < part2 - 1) QuickSort2(l, part2 - 1, v);
    if (part2 < r) QuickSort2(part2, r, v);
};