#include <bits/stdc++.h>
using namespace std;

// Checkers to detect performance bottlenecks
void check_large_prime_invariant(long long n, int m) {
    if (m == n) { // This means n is a prime number
        cerr << "Warning: Performance bottleneck condition triggered - n is a large prime or has large prime factors!" << endl;
        abort();
    }
}

void check_large_n_invariant(long long n, int m) {
    if (m > sqrt(n)) { // If m is greater than the square root of n, it indicates few small divisors
        cerr << "Warning: Performance bottleneck condition triggered - Large `n` with minimal small divisors!" << endl;
        abort();
    }
}

void check_high_iteration_invariant(int t, int currentQuery) {
    if (currentQuery > t / 2) { // More than half of the queries processed
        cerr << "Warning: Performance bottleneck condition triggered - High iteration count with inefficient divisor calculation!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    int currentQuery = 0;

    while (T-- > 0) {
        currentQuery++;

        long long n, k;
        cin >> n >> k;

        int m;
        for (m = 2; m <= n; m++) {
            if (n % m == 0) break;
        }

        // Insert checks after finding the smallest divisor
        check_large_prime_invariant(n, m);
        check_large_n_invariant(n, m);
        check_high_iteration_invariant(T, currentQuery);

        long long ans = n + m + (k - 1) * 2;
        cout << ans << endl;
    }
    
    return 0;
}