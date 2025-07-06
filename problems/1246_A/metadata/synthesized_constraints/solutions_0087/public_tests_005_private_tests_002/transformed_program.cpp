#include <bits/stdc++.h>
using namespace std;

inline long long read() {
    register long long x = 0, f = 1;
    register char c = getchar();
    for (; !isdigit(c); c = getchar())
        if (c == '-') f = -1;
    for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c & 15);
    return x * f;
}

inline long long low(long long x) {
    long long cnt = 0;
    while (x) {
        x ^= x & -x;
        cnt++;
    }
    return cnt;
}

void check_positive_p_small_n_invariant(long long n, long long p) {
    if (p > 0 && n < 100) { // Arbitrary threshold; adjust as necessary
        cerr << "Warning: Positive p and small n - potential excessive iteration!" << endl;
        abort();
    }
}

void check_high_iteration_invariant(long long i) {
    if (i > 1e6) { // Close to the upper bound of the loop
        cerr << "Warning: High iteration count - potential performance bottleneck!" << endl;
        abort();
    }
}

void check_costly_bit_manipulation_invariant(long long n, long long p, long long i) {
    if (p > 0 && n - p * i < 0 && i > 1000) { // Adjust threshold for costly operation
        cerr << "Warning: Costly bit manipulation due to excessive low() calls!" << endl;
        abort();
    }
}

signed main() {
    long long n = read();
    long long k = read();

    // Check for positive `p` and small `n`
    check_positive_p_small_n_invariant(n, k);

    for (register long long i = 1; i <= 1e6 + 10; i++) {
        // Check for high iteration count
        check_high_iteration_invariant(i);

        // Check for costly bit manipulation
        check_costly_bit_manipulation_invariant(n, k, i);

        if (n - k * i >= i && low(n - k * i) <= i) {
            return !printf("%lld\n", i);
        }
    }
    puts("-1");
    return 0;
}