#include <bits/stdc++.h>
using namespace std;
const int M = 50 * 1000 * 1000, LG = 40;

// Function to check large number of iterations
void check_large_iterations_invariant(long long x, int i, int M) {
    if (x >= i && i >= M - 1) {
        cerr << "Warning: Performance bottleneck condition triggered - large number of iterations!" << endl;
        abort();
    }
}

// Function to check popcount limitation
void check_popcount_invariant(long long x, int i) {
    if (__builtin_popcount(x) > i) {
        cerr << "Warning: Performance bottleneck condition triggered - popcount limitation!" << endl;
        abort();
    }
}

// Function to check impact of negative or zero p
void check_negative_p_invariant(int p, int i) {
    if (p <= 0 && i > 0) {
        cerr << "Warning: Performance bottleneck condition triggered - negative or zero p value impact!" << endl;
        abort();
    }
}

int main() {
    int n, p;
    cin >> n >> p;
    
    for (int i = 0; i < M; i++) {
        long long x = (long long)n - 1ll * p * i;
        
        // Insert checks to detect potential performance bottlenecks
        check_negative_p_invariant(p, i);
        check_large_iterations_invariant(x, i, M);
        check_popcount_invariant(x, i);
        
        if (x >= i && __builtin_popcount(x) <= i) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}