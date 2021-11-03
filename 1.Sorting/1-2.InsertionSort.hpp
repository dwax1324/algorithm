#include <bits/stdc++.h>

using namespace std;

void InsertionSort(vector<int> &v) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        int key = v[i];  // 현재값
        int j = i;
        // v[j-1]이 현재값보다 크다면 v[j]로 값을 덮어쓴다.(한칸씩 옆으로 밀어준다)
        while (j - 1 >= 0 && v[j - 1] > key) v[j] = v[j - 1], j--;
        v[j] = key;  // 새로운 자리에 현재값을 덮어쓴다(insert).
    }
}
void InsertionSort2(vector<int> &v) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && v[j - 1] > v[j]) swap(v[j], v[j - 1]), j--;
    }
};
void InsertionSort3(vector<int> &v) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        int key = v[i];
        int j = i;
        int toInsert = i;
        while (j >= 0) {
            if (v[j] > v[i]) toInsert = j;
            j--;
        }
        v.erase(v.begin() + i);
        v.insert(v.begin() + toInsert, key);
    }
};