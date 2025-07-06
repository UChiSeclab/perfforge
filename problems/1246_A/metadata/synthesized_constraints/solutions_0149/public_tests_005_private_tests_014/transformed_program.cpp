#include <bits/stdc++.h>
using namespace std;

void check_loop_execution_invariant(int64_t n, int64_t p, int64_t i) {
    if (__builtin_popcountll(n) > i && n >= i) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive loop iterations!" << endl;
        abort();
    }
}

void check_popcount_invariant(int64_t n, int64_t p, int64_t i) {
    if (__builtin_popcountll(n) > i) {
        cerr << "Warning: Performance bottleneck condition triggered - high popcount relative to iteration!" << endl;
        abort();
    }
}

void check_impossibility_invariant(int64_t n, int64_t p) {
    if (n < p) {
        cerr << "Warning: Performance bottleneck condition triggered - inherently unsatisfiable scenario!" << endl;
        abort();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    int64_t n, p;
    cin >> n >> p;
    
    // Check for impossible scenario early
    check_impossibility_invariant(n, p);
    
    for (int64_t i = 1; i < 1e6; ++i) {
        n -= p;
        
        // Check potential performance bottlenecks
        check_loop_execution_invariant(n, p, i);
        check_popcount_invariant(n, p, i);
        
        if (__builtin_popcountll(n) > i) {
            continue;
        }
        if (n < i) {
            continue;
        }
        cout << i;
        return 0;
    }
    cout << -1;
}