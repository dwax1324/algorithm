#include <bits/stdc++.h>

#include <random>

#include "1-1.BubbleSort.hpp"
#include "1-2.InsertionSort.hpp"
#include "1-3.SelectionSort.hpp"
#include "1-4.MergeSort.hpp"
#include "1-5.QuickSort.hpp"
using namespace std;

void genShuffled(vector<int> &v) {
    std::random_device rd;
    std::default_random_engine rng(rd());
    shuffle(v.begin(), v.end(), rng);
}

vector<int> gen(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = i + 1;
    genShuffled(v);
    return v;
}
void printBefore(vector<int> v) {
    cout << "before sort...\n";
    for (int x : v) cout << x << ' ';
}
void printAfter(vector<int> v) {
    cout << "\nafter sort...\n";
    for (int x : v) cout << x << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n = 20;
    vector<int> v = gen(n);
    printBefore(v);
    QuickSort2(0, n - 1, v);
    printAfter(v);
}