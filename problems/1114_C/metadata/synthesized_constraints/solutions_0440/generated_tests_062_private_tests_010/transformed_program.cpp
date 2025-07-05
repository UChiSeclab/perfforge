#include <bits/stdc++.h>
using namespace std;

// Checker for large base size
void check_large_base(long long b) {
    if (b > 1e12 / 1000) {  // Adjusted threshold for practical checking
        cerr << "Warning: Performance bottleneck condition triggered due to large base size!" << endl;
        abort();
    }
}

// Checker for prime factorization overhead
void check_prime_factorization_overhead(long long b) {
    long long count = 0;
    for (long long i = 2; i * i <= b; ++i) {
        while (b % i == 0) {
            b /= i;
            ++count;
        }
    }
    if (b > 1) ++count;  // For the remaining prime factor if b is prime
    if (count > 20) {  // Arbitrary threshold for number of prime factors
        cerr << "Warning: Performance bottleneck condition triggered due to prime factorization overhead!" << endl;
        abort();
    }
}

// Checker for high iteration count in nested loops
void check_high_iteration_count(long long n, long long b) {
    if (n > 1e6 && b > 1e6) {  // Example threshold for both parameters
        cerr << "Warning: Performance bottleneck condition triggered due to high iteration count in loops!" << endl;
        abort();
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, base;
    cin >> n >> base;

    // Performance checkers
    check_large_base(base);  // Check for large base size
    check_prime_factorization_overhead(base);  // Check for prime factorization overhead
    check_high_iteration_count(n, base);  // Check for high iteration count in loops

    long long noz = n;
    long long j = base;
    for (long long i = 2; i * i <= base; i++) {
        if (j % i == 0) {
            long long p = 0;
            while (j % i == 0) {
                p++;
                j /= i;
            }
            long long c = 0;
            long long k = n;
            while (k / i > 0) {
                c += k / i;
                k /= i;
            }
            noz = min(noz, c / p);
        }
    }
    if (j > 1) {
        long long p = 0;
        while (j % j == 0) {
            p++;
            j /= j;
        }
        long long c = 0;
        long long k = n;
        while (k / j > 0) {
            c += k / j;
            k /= j;
        }
        noz = min(noz, c / p);
    }
    cout << noz;
    return 0;
}