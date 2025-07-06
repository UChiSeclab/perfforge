#include <bits/stdc++.h>

// Check for when x is very small, causing full loop iteration
void check_small_x_invariant(int n, int x) {
    if (x == 1) {
        std::cerr << "Warning: small_x_invariant triggered - x is too small, causing full loop iteration!" << std::endl;
        abort();
    }
}

// Check for when x has many divisors, impacting performance
void check_many_divisors_invariant(int n, int x) {
    int divisor_count = 0;
    for (int i = 1; i <= n; ++i) {
        if (x % i == 0) {
            divisor_count++;
            if (divisor_count > 1000) { // Arbitrary threshold indicating too many divisors
                std::cerr << "Warning: many_divisors_invariant triggered - x has many divisors, causing slowdown!" << std::endl;
                abort();
            }
        }
    }
}

// Check for large n with small x causing performance issues
void check_large_n_small_x_invariant(int n, int x) {
    if (n > 10000 && x < 10) { // Example condition that considers large n and small x
        std::cerr << "Warning: large_n_small_x_invariant triggered - large n combined with small x!" << std::endl;
        abort();
    }
}

int main() {
    int n, x, i, a = 0;
    std::cin >> n >> x;

    // Apply performance checks based on identified invariants
    check_small_x_invariant(n, x);
    check_many_divisors_invariant(n, x);
    check_large_n_small_x_invariant(n, x);

    for (i = n; i > 0 && x / i <= n; i--) {
        if (x % i == 0) a++;
    }

    std::cout << a;
}