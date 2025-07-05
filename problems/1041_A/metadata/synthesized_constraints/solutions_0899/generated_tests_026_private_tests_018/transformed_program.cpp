#include <bits/stdc++.h>
using namespace std;

// Phase 3: Invariant checkers
void check_large_range_invariant(int minIndex, int maxIndex, int n) {
    if ((maxIndex - minIndex) > 1000 * n) {
        cerr << "Warning: Performance bottleneck condition triggered - large range between indices!" << endl;
        abort();
    }
}

void check_sparse_distribution_invariant(int minIndex, int maxIndex, int n) {
    if (n < (maxIndex - minIndex) / 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - sparse distribution of indices!" << endl;
        abort();
    }
}

void check_large_iteration_invariant(int minIndex, int maxIndex, int n) {
    if (n < (maxIndex - minIndex) / 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - large iteration count with small n!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
  
    int minIndex = a[0];
    int maxIndex = a[n - 1];

    // Phase 4: Invoking invariant checkers
    check_large_range_invariant(minIndex, maxIndex, n);
    check_sparse_distribution_invariant(minIndex, maxIndex, n);
    check_large_iteration_invariant(minIndex, maxIndex, n);

    int t = 0, d = 0;
    for (int i = minIndex; i <= maxIndex; i++) {
        if (i == a[t])
            t++;
        else
            d++;
    }
    cout << d << endl;
}