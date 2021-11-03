#include <bits/stdc++.h>
#define vec2(x) vector<vector<x>>
#define vec3(x) vector<vector<vector<x>>>
#define all(x) x.begin(), x.end()
#include <random>
using namespace std;

std::random_device dev;
std::mt19937 rng(dev());
class Sort {
public:
    vector<int> v;
    int n;
    Sort(int _n) : n(_n) {
    }

    void bubble() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (v[j] > v[j + 1]) swap(v[j], v[j + 1]);
            }
        }
    }
    void insertion() {
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j - 1 >= 0 && v[j - 1] > v[j]) swap(v[j - 1], v[j]), j--;
        }
    }
    void selection() {
        for (int i = 0; i < n; i++) {
            int mn = i;
            for (int j = i + 1; j < n; j++) {
                if (v[j] < v[mn]) mn = j;
            }
            swap(v[i], v[mn]);
        }
    }
    void merge(int l, int r) { merge(l, r, v); }
    void merge(int l, int r, vector<int> &v) {
        if (l < r) {
            int mid = (l + r) / 2;
            merge(l, mid, v);
            merge(mid + 1, r, v);
            merger(l, mid, r, v);
        }
    }
    void merger(int l, int mid, int r, vector<int> &v) {
        int n1 = mid - l + 1, n2 = r - mid;
        vector<int> L(n1), R(n2);
        for (int i = 0; i < n1; i++) L[i] = v[l + i];
        for (int i = 0; i < n2; i++) R[i] = v[mid + i + 1];
        int i = 0, j = 0, idx = l;
        while (i < n1 && j < n2) {
            if (L[i] < R[j]) v[idx] = L[i], i++, idx++;
            else
                v[idx] = R[j], j++, idx++;
        }
        while (i < n1) v[idx] = L[i], idx++, i++;
        while (j < n2) v[idx] = R[j], idx++, j++;
    }
    void quick(int l, int r) { quick(l, r, v); }
    void quick(int l, int r, vector<int> &v) {
        int pivot = quicker(l, r, v);
        if (pivot - l > 1) {
            quick(l, pivot - 1, v);
        }
        if (pivot < r) {
            quick(pivot, r, v);
        }
    }
    int quicker(int l, int r, vector<int> &v) {
        std::uniform_int_distribution<std::mt19937::result_type> dist(l, r);
        int pivot = v[dist(rng)];
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

    void heap() {
        vector<int> t = v;
        v = {};
        heapConstruct(t);
        // cout << "@" << t[0] << "@\n";
        int sz = t.size();
        while (sz) {
            v.push_back(t[0]);
            swap(t[0], t[sz - 1]);
            sz--;
            heapify(0, sz, t);
        }
    }
    void heapConstruct(vector<int> &v) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(i, n, v);
        }
    }
    void heapify(int i, int size, vector<int> &v) {
        int idx = i;
        while (1) {
            int p = idx, l = idx * 2 + 1, r = idx * 2 + 2;
            if (l < size && v[l] < v[p]) p = l;
            if (r < size && v[r] < v[p]) p = r;
            if (p == idx) break;
            swap(v[idx], v[p]);
            idx = p;
        }
    }

    void push(int a) {
        v.push_back(a);
    }
    void print() {
        for (auto x : v) cout << x << '\n';
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    Sort solve = Sort(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        solve.push(a);
    }
    solve.heap();
    solve.print();
}