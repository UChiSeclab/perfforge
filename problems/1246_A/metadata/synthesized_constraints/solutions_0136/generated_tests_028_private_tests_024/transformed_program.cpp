#include <bits/stdc++.h>
using namespace std;

// Checker function for high iteration count
void check_high_iteration_invariant(long long i) {
    if (i >= 1000000) { // Arbitrary large threshold for loop iterations
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count in main loop" << endl;
        abort();
    }
}

// Checker function for n and p relationship
void check_value_invariant(long long n, long long p) {
    if (p != 0 && abs(n % p) < 10) { // Threshold is illustrative; adjust based on deeper insight
        cerr << "Warning: Performance bottleneck condition triggered - relationship between n and p causing slow convergence" << endl;
        abort();
    }
}

int main() {
    long long int n, p, i, x, y;
    cin >> n >> p;

    // Check relationship between n and p before the main loop
    check_value_invariant(n, p);
    
    for (i = 1; i < 100000000; i++) {
        x = n - (i * p);
        if (x > 0) {
            if (__builtin_popcount(x) <= i && x >= i) {
                cout << i;
                return 0;
            }
        }
        
        // Check high iteration invariant inside the loop
        check_high_iteration_invariant(i);
    }
    cout << -1;
    return 0;
}