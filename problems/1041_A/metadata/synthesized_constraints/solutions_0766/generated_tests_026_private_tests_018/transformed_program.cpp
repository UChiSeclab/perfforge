#include <bits/stdc++.h>
using namespace std;

int n, el[1001];

void check_large_range_invariant(int minIndex, int maxIndex, int n) {
    if ((maxIndex - minIndex) > 10 * n) { // Arbitrary threshold relative to n
        cerr << "Warning: Performance bottleneck condition triggered - large range iteration!" << endl;
        abort();
    }
}

void check_sparse_distribution_invariant(int minIndex, int maxIndex, int n) {
    if ((maxIndex - minIndex) / n > 10) { // Arbitrary threshold indicating sparsity
        cerr << "Warning: Performance bottleneck condition triggered - sparse distribution of indices!" << endl;
        abort();
    }
}

void check_linear_search_invariant(int minIndex, int maxIndex, int n) {
    if ((maxIndex - minIndex) > 100 * n) { // Threshold derived from inefficiency due to large range
        cerr << "Warning: Performance bottleneck condition triggered - linear search inefficiency!" << endl;
        abort();
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < (int)n; ++i) cin >> el[i];
    sort(el, el + n);

    int minIndex = el[0];
    int maxIndex = el[n - 1];

    // Perform checks after sorting and before the loop
    check_large_range_invariant(minIndex, maxIndex, n);
    check_sparse_distribution_invariant(minIndex, maxIndex, n);
    check_linear_search_invariant(minIndex, maxIndex, n);

    int j = 0, ans = 0;
    for (int i = minIndex; i <= maxIndex; i++) {
        if (el[j] != i) {
            ans++;
        } else {
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}