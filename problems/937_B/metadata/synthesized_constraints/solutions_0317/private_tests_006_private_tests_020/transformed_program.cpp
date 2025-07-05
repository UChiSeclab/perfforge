#include <bits/stdc++.h>

// Invariant checker functions
void check_large_primality_testing_space(int p) {
    if (p > 32000) {
        std::cerr << "Warning: Performance bottleneck condition triggered - large primality testing space!" << std::endl;
        abort();
    }
}

void check_extensive_loop_iterations(int p) {
    if (p > 32000) {
        std::cerr << "Warning: Performance bottleneck condition triggered - extensive loop iterations!" << std::endl;
        abort();
    }
}

void check_high_density_prime_numbers(int lim) {
    if (lim > 32000) {
        std::cerr << "Warning: Performance bottleneck condition triggered - high density of prime numbers!" << std::endl;
        abort();
    }
}

int main() {
    int prime[32001], p, y, lim, m;
    int i, j;
    scanf("%d %d", &p, &y);
    
    // Check for potential performance bottlenecks based on input values
    check_large_primality_testing_space(p);
    check_extensive_loop_iterations(p);
    
    lim = ((32000) < (p) ? (32000) : (p));
    
    // Check if the limit might lead to performance bottlenecks
    check_high_density_prime_numbers(lim);
    
    prime[m++] = 2;
    for (i = 3; i <= lim; i += 2) {
        for (j = 1; j < m; j++) {
            if (prime[j] * prime[j] > i || i % prime[j] == 0) break;
        }
        if (prime[j] * prime[j] > i || j == m) {
            prime[m++] = i;
        }
    }
    for (; y > p; y--) {
        for (j = 0; j < m; j++) {
            if (prime[j] * prime[j] > y || y % prime[j] == 0) break;
        }
        if (prime[j] * prime[j] > y || j == m) {
            printf("%d\n", y);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}