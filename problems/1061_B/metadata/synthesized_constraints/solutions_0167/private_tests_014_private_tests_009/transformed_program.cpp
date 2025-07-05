#include <bits/stdc++.h>
using namespace std;

// Checkers for performance bottlenecks
void check_high_h_invariant(long long h, long long m) {
    if (h > m * 0.9) { // Assume critical if h is over 90% of m
        cerr << "Warning: High initial h invariant triggered!" << endl;
        abort();
    }
}

void check_sparse_tall_stack_invariant(long long n, long long h, long long m) {
    if (n < 10 && h > m * 0.9) { // Critical if few stacks and a tall one
        cerr << "Warning: Sparse tall stack invariant triggered!" << endl;
        abort();
    }
}

void check_minimal_k_advance_invariant(long long k, long long n, long long h, const long long* a) {
    if (k == 1 && a[k] < h * 0.5) { // Critical if k advances slowly
        cerr << "Warning: Minimal k advancement invariant triggered!" << endl;
        abort();
    }
}

int main() {
    long long n, m;
    cin >> n >> m;
    long long a[n], cnt = 0, h = 0;
    
    for (int k = 0; k < n; k++) {
        cin >> a[k];
        h = max(h, a[k]);
        cnt += a[k];
    }
    
    // Check high initial h invariant
    check_high_h_invariant(h, m);
    
    sort(a, a + n, [](int x, int y) { return x > y; });
    if (n == 1) {
        cout << 0;
        return 0;
    }

    long long k = 1, r = h;
    
    // Check sparse tall stack invariant
    check_sparse_tall_stack_invariant(n, h, m);
    
    while (h > 1) {
        if (a[k] >= h - 1) k++;
        h--;
        if (k == n) break;
        
        // Check minimal k advancement invariant
        check_minimal_k_advance_invariant(k, n, h, a);
    }
    
    long long ans = cnt - r - (n - k);
    cout << ans;
    return 0;
}