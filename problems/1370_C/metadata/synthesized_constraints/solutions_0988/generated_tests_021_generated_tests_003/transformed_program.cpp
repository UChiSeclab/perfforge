#include <bits/stdc++.h>
using namespace std;

// Performance checker functions
void check_odd_divisors_invariant(int n, int iterations) {
    if (iterations > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - high iterations with odd divisors!" << endl;
        abort();
    }
}

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void check_large_prime_invariant(int n) {
    if (n > 1000000 && is_prime(n)) {
        cerr << "Warning: Performance bottleneck condition triggered - large prime!" << endl;
        abort();
    }
}

void check_large_composite_invariant(int n, int m) {
    if (n > 1000000 && m > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - large composite with big factors!" << endl;
        abort();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m = 1;
        cin >> n;

        // Check for primes
        check_large_prime_invariant(n);

        int iteration_count = 0;
        while (n % 2 == 0) {
            n /= 2;
            m *= 2;
            iteration_count++;
        }

        // Evaluate the number of iterations for divisor checks
        check_odd_divisors_invariant(n, iteration_count);

        int x = 1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                x = 0;
                break; // Stop further checks once a factor is found
            }
        }

        // Check large composite invariant
        check_large_composite_invariant(n, m);

        if ((n == 1 && m != 2) || (n != 1 && m == 2 && x))
            cout << "FastestFinger";
        else
            cout << "Ashishgup";
        cout << endl;
    }
}