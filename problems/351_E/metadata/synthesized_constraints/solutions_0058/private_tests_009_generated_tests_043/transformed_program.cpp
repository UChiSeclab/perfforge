#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005, maxm = 1e5 + 5;
int a[maxn], b[maxn], seg[4 * maxm];

// Checker functions
void check_segment_tree_operations(int operationCount, int threshold) {
    if (operationCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - too many segment tree operations!" << endl;
        abort();
    }
}

void check_complex_distribution(int uniqueCount, int n) {
    if (uniqueCount > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - complex distribution of sequence elements!" << endl;
        abort();
    }
}

void check_input_size(int n, int threshold) {
    if (n > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - large input size!" << endl;
        abort();
    }
}

void check_repeated_operations(int n, int threshold) {
    if (n > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated operations in nested loops!" << endl;
        abort();
    }
}

void add(int id, int L, int R, int idx, int x) {
    if (idx < L || idx >= R) return;
    if (R == L + 1) {
        seg[id] += x;
        return;
    }
    int mid = (L + R) / 2;
    add(2 * id + 0, L, mid, idx, x);
    add(2 * id + 1, mid, R, idx, x);
    seg[id] = seg[2 * id + 0] + seg[2 * id + 1];
}

int get(int id, int L, int R, int l, int r) {
    if (R <= l || r <= L) return 0;
    if (L >= l && R <= r) return seg[id];
    int mid = (L + R) / 2;
    return get(2 * id + 0, L, mid, l, r) + get(2 * id + 1, mid, R, l, r);
}

int main() {
    int n;
    cin >> n;

    // Input size check
    check_input_size(n, 2000);

    int inv = 0;
    int operationCount = 0;
    set<int> uniqueElements;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = abs(a[i]);
        inv += get(1, 0, maxm, a[i] + 1, maxm);
        b[i] = get(1, 0, maxm, 0, a[i]);
        add(1, 0, maxm, a[i], +1);
        operationCount += 2; // Each loop processes two operations on the segment tree

        // Track unique elements
        uniqueElements.insert(a[i]);
    }

    // Check segment tree operations
    check_segment_tree_operations(operationCount, n * 10); // Arbitrary threshold based on complexity

    // Check complex distribution
    check_complex_distribution(uniqueElements.size(), n);

    for (int i = 0; i < n; i++) {
        int c = get(1, 0, maxm, 0, a[i]);
        c -= b[i];
        if (c > b[i]) inv -= c - b[i];
    }

    cout << inv;
}