#include <bits/stdc++.h>
using namespace std;

// Performance bottleneck checkers
void check_large_n_small_x_invariant(long long n, long long x) {
    if (n > 10000 && x <= n) {  // Condition representing large `n` and small `x`
        cerr << "Warning: Performance bottleneck condition triggered - large n with small x!" << endl;
        abort();
    }
}

void check_x_less_equal_n_invariant(long long n, long long x) {
    if (x <= n) {  // Condition when `x` is less or equal to `n`, maximizing loop iterations
        cerr << "Warning: Performance bottleneck condition triggered - x is less or equal to n!" << endl;
        abort();
    }
}

int main() {
    long long int n, x, i, a = 0, b, j;  // Initialize `a` to zero to avoid undefined behavior
    cin >> n >> x;
    
    // Insert checkers after reading inputs
    check_large_n_small_x_invariant(n, x);
    check_x_less_equal_n_invariant(n, x);
    
    if (x <= n) a = a + 1;
    for (j = 2; j <= n; j++) {
        b = j * n;
        if (x % j == 0 && b >= x) {
            a++;
        }
    }
    cout << a;
    return 0;
}