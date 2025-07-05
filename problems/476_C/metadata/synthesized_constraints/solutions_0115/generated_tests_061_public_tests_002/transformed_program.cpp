#include <bits/stdc++.h>
using namespace std;

void check_large_b_invariant(long long b) {
    if (b > 1e7 / 2) { // Arbitrary threshold at half the maximum constraint to catch large values
        cerr << "Warning: Performance bottleneck condition triggered due to large b!" << endl;
        abort();
    }
}

void check_heavy_operations_invariant(long long b) {
    if (b > 1e7 / 2) { // Similarly checking for heavy operations based on large b
        cerr << "Warning: Performance bottleneck condition triggered due to heavy operations with large b!" << endl;
        abort();
    }
}

int main() {
    long long a, b;
    long long ans = 0, mod = 1e9 + 7;
    cin >> a >> b;
    
    // Check for performance bottlenecks based on `b`
    check_large_b_invariant(b);
    check_heavy_operations_invariant(b);

    for (long long k = 1; k < b; ++k) {
        long long diff = b * k, first = 2 * (k * b + k), n = a - 1, m = a;
        if (m % 2ll) {
            first /= 2;
            first %= mod;
            n /= 2;
            n %= mod;
            diff %= mod;
            diff *= n;
            diff %= mod;
            diff += first;
            diff %= mod;
            m %= mod;
            ans += (m * diff) % mod;
        } else {
            m /= 2;
            m %= mod;
            first %= mod;
            n %= mod;
            diff %= mod;
            diff *= n;
            diff %= mod;
            diff += first;
            diff %= mod;
            ans += (m * diff) % mod;
        }
        ans %= mod;
    }
    cout << ans % mod;
}