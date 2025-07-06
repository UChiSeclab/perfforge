#include <bits/stdc++.h>
using namespace std;

int a[200005];
long long sum[200005];

void check_large_k_invariant(int k, int initialMedian, int maxElement) {
    if (k > (maxElement - initialMedian) * 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - large k relative to element differences!" << endl;
        abort();
    }
}

void check_element_closeness_invariant(int a[], int n) {
    int medianIndex = n / 2 + 1;
    int countClose = 0;
    for (int i = medianIndex; i < n; ++i) {
        if (a[i] - a[i - 1] <= 2)
            ++countClose;
    }
    if (countClose > n / 4) {
        cerr << "Warning: Performance bottleneck condition triggered - too many close elements!" << endl;
        abort();
    }
}

void check_element_clustering_invariant(int a[], int n, int initialMedian) {
    int clusterCount = 0;
    for (int i = n / 2 + 1; i