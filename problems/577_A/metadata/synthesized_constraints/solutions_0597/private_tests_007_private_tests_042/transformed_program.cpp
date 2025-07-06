#include <bits/stdc++.h>
using namespace std;

// Checkers for performance-characterizing invariants
void check_large_n_invariant(long n) {
    if (n > 100000) {
        cerr << "Warning: Large n invariant triggered - excessive loop iterations" << endl;
        abort();
    }
}

void check_small_x_invariant(long x) {
    if (x == 1) {
        cerr << "Warning: Small x invariant triggered - x has many divisors" << endl;
        abort();
    }
}

int main() {
    long n, x, temp, i;
    long ans = 0;
    cin >> n >> x;

    // Place checkers after input reading
    check_large_n_invariant(n); // Detects potential slowdown due to large n
    check_small_x_invariant(x); // Detects potential slowdown due to x being 1

    for (i = 1; i <= n; i++) {
        temp = x / i;
        if (x % i == 0 && (temp <= n)) {
            ans++;
        }
    }
    cout << ans << endl;
}