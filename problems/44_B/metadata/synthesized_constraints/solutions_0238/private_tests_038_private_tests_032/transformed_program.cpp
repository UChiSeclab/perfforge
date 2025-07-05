#include <bits/stdc++.h>

// Checker functions to identify potential performance bottlenecks
void check_n_invariant(long n) {
    if (n > 9000) {
        std::cerr << "Warning: Performance bottleneck condition triggered - large n value." << std::endl;
        abort();
    }
}

void check_bottle_availability_invariant(long a, long b, long c) {
    if (a > 4500 && b > 4500 && c > 4500) {
        std::cerr << "Warning: Performance bottleneck condition triggered - high bottle availability." << std::endl;
        abort();
    }
}

void check_combination_complexity_invariant(long n, long a, long b, long c) {
    if ((n > 9000) && (a > 4500 || b > 4500 || c > 4500)) {
        std::cerr << "Warning: Performance bottleneck condition triggered - large n with high bottle availability." << std::endl;
        abort();
    }
}

int main() {
    long n;
    long long f[4][20005] = {0}, a[4] = {0}, b[4] = {0, 1, 2, 4};
    long i, j, k;
    scanf("%I64d%I64d%I64d%I64d", &n, &a[1], &a[2], &a[3]);
  
    // Insert checker functions after input is read
    check_n_invariant(n);
    check_bottle_availability_invariant(a[1], a[2], a[3]);
    check_combination_complexity_invariant(n, a[1], a[2], a[3]);

    n = n * 2;
    f[0][0] = 1;
    
    for (i = 1; i <= 3; i++) {
        for (k = n; k >= 0; k--) {
            for (j = 0; j * b[i] <= k && j <= a[i]; j++) {
                f[i][k] += f[i - 1][k - j * b[i]];
            }
        }
    }
    
    printf("%I64d\n", f[3][n]);
    return 0;
}