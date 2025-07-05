#include <bits/stdc++.h>
using namespace std;

// Function prototypes for invariant checks
void check_high_remainder_invariant(long long a, long long m);
void check_large_prime_modulus_invariant(long long a, long long m);
void check_ineffective_loop_invariant(long long a, long long m);

int main() {
    long long a, m;
    cin >> a >> m;
    
    // Performance bottleneck checks
    check_high_remainder_invariant(a, m);
    check_large_prime_modulus_invariant(a, m);
    check_ineffective_loop_invariant(a, m);

    int t = 10000000;
    while (t--) {
        if (a % m == 0) {
            cout << "Yes" << endl;
            return 0;
        }
        a += (a % m);
    }
    cout << "No" << endl;
    return 0;
}

// Check if the initial remainder is high relative to `a`, indicating many loop iterations.
void check_high_remainder_invariant(long long a, long long m) {
    if ((a % m) > (a / 2)) { // Example threshold using a fraction of `a`
        cerr << "Warning: High remainder invariant triggered - potential slow processing!" << endl;
        abort();
    }
}

// Check if `m` is a large prime number and `a` is small compared to `m`.
void check_large_prime_modulus_invariant(long long a, long long m) {
    // Simple check for large prime assumption (use a known range for demonstration)
    bool isPrime = true;
    if (m < 2) isPrime = false;
    for (long long i = 2; i * i <= m; ++i) {
        if (m % i == 0) {
            isPrime = false;
            break;
        }
    }
    if (isPrime && m > 95000 && a < m / 10) { // Hypothetical threshold
        cerr << "Warning: Large prime modulus invariant triggered - potential slowdown!" << endl;
        abort();
    }
}

// Check if the increment operation is ineffective over multiple iterations.
void check_ineffective_loop_invariant(long long a, long long m) {
    // Example of ineffective increment detection
    if ((a % m) == (m - 1) || (a % m) == 1) { // Hypothetical ineffective increments
        cerr << "Warning: Ineffective loop invariant triggered - slow convergence!" << endl;
        abort();
    }
}