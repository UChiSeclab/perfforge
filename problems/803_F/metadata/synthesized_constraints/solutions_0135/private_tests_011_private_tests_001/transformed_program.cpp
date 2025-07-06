#include <bits/stdc++.h>
using namespace std;

int n, a[100001], h[100001], g[100001], x, m, f[100001];

// Checker for invariant: Maximum element 'm' is large, causing nested loops to iterate excessively
void check_max_element_invariant(int m) {
    if (m > 50000) {  // Assuming a threshold based on analysis
        cerr << "Warning: Performance bottleneck condition triggered - large maximum element!" << endl;
        abort();
    }
}

// Checker for invariant: Sparse distribution of high values causing redundant operations
void check_sparse_distribution_invariant(int m, int *f) {
    int highValueCount = 0;
    for (int i = m / 2; i <= m; i++) {
        if (f[i] > 0) highValueCount++;
    }
    if (highValueCount < m / 10) {  // Assume sparse is less than 10% of the range
        cerr << "Warning: Performance bottleneck condition triggered - sparse distribution of high values!" << endl;
        abort();
    }
}

// Checker for invariant: Small n with large element magnitudes
void check_size_magnitude_invariant(int n, int m) {
    if (n < 10 && m > 50000) {  // Assuming a combined threshold
        cerr << "Warning: Performance bottleneck condition triggered - small n with large elements!" << endl;
        abort();
    }
}

int main() {
    cin >> n;
    a[0] = 1;
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] * 2 % 1000000007, cin >> x, f[x]++, m = max(m, x);

    // Insert check after input processing
    check_max_element_invariant(m);
    check_sparse_distribution_invariant(m, f);
    check_size_magnitude_invariant(n, m);

    for (int i = m; i >= 1; i--) {
        for (int j = i; j <= m; j += i)
            g[i] += f[j], h[i] = (h[i] - h[j] + 1000000007) % 1000000007;
        h[i] = (h[i] + a[g[i]] - 1) % 1000000007;
    }
    cout << h[1];
}