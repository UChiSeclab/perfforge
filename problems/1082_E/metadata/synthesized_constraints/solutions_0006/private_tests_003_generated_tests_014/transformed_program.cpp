#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;

// Function to check high maximum element value
void check_max_element_invariant(int mx) {
    if (mx > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered! High maximum element value." << endl;
        abort();
    }
}

// Function to check sparse population in pos array
void check_sparse_population_invariant(const vector<int> pos[], int mx) {
    int sparse_count = 0;
    for (int i = 1; i <= mx; ++i) {
        if (pos[i].empty()) {
            ++sparse_count;
        }
    }
    if (sparse_count > mx / 2) { // arbitrary threshold for sparsity
        cerr << "Warning: Performance bottleneck condition triggered! Sparse population in pos array." << endl;
        abort();
    }
}

// Function to check excessively large input values
void check_large_input_values_invariant(const vector<int>& a) {
    for (int x : a) {
        if (x >= 500000) {
            cerr << "Warning: Performance bottleneck condition triggered! Excessively large input value." << endl;
            abort();
        }
    }
}

bool Finish_read;
template <class T>
inline void read(T &x) {
    Finish_read = 0;
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        if (ch == EOF) return;
        ch = getchar();
    }
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
    Finish_read = 1;
}
template <class T>
inline void print(T x) {
    if (x / 10 != 0) print(x / 10);
    putchar(x % 10 + '0');
}
template <class T>
inline void writeln(T x) {
    if (x < 0) putchar('-');
    x = abs(x);
    print(x);
    putchar('\n');
}

const int maxn = 500005;
int n, k, mx;
vector<int> pos[maxn];
inline int id(int x) {
    return lower_bound(pos[k].begin(), pos[k].end(), x) - pos[k].begin();
}
inline void init() {
    read(n), read(k);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        read(a[i]);
        pos[a[i]].push_back(i + 1);
        mx = max(mx, a[i]);
    }
    // Check for performance bottlenecks
    check_max_element_invariant(mx);
    check_sparse_population_invariant(pos, mx);
    check_large_input_values_invariant(a);
}
inline int calc() {
    int now = pos[k].size(), cnt = now;
    for (int i = 1; i <= mx; ++i) {
        if (!pos[i].size() || i == k) continue;
        int p = 1;
        now = max(now, cnt + p);
        for (int j = 1; j < (int)pos[i].size(); ++j)
            now = max(now,
                      cnt + (p = max(p + 1 - id(pos[i][j]) + id(pos[i][j - 1]), 1)));
    }
    return now;
}
int main() {
    init();
    writeln(calc());
}