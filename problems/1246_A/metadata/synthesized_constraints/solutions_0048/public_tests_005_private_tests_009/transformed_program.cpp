#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_large_iterations_invariant(long long n, long long p, long long i) {
    if (p > 0 && (n - p * i < 1)) {
        cerr << "Warning: Performance bottleneck condition triggered - loop iterates excessively without useful computation!" << endl;
        abort();
    }
}

void check_condition_skipping_invariant(long long left) {
    if (left < 1) {
        cerr << "Warning: Performance bottleneck condition triggered - skipping iterations excessively!" << endl;
        abort();
    }
}

void check_input_constraints_invariant(long long n, long long p) {
    if (p > 0 && n <= p) {
        cerr << "Warning: Performance bottleneck condition triggered - n is smaller than or equal to p, causing excessive iterations!" << endl;
        abort();
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, p;
    cin >> n >> p;
    
    // Check input constraints
    check_input_constraints_invariant(n, p);
    
    long long ans = 5 * 5000000;
    for (long long i = 1; i <= 5000000; i++) {
        long long left = n - p * i;
        
        // Check for large iteration invariant
        check_large_iterations_invariant(n, p, i);
        
        if (left < 1) {
            // Check for condition skipping invariant
            check_condition_skipping_invariant(left);
            continue;
        } else {
            long long k = __builtin_popcount(left);
            if (k <= i and left >= i) {
                cout << i;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}