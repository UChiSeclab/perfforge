#include <bits/stdc++.h>
using namespace std;

// Checker for large x that may lead to excessive iterations
void check_large_x_invariant(int x) {
    if (x > 1e8) {  // Arbitrary threshold to flag very large `x`
        cerr << "Warning: large_x_invariant triggered - x is very large, leading to many iterations" << endl;
        abort();
    }
}

// Checker for situations involving high divisor counts with small n
void check_divisor_invariant(int n, int x) {
    if (x > 1e7 && n < 10) {
        cerr << "Warning: divisor_invariant triggered - high divisor checks for large x and small n" << endl;
        abort();
    }
}

int main() {
    int n, x;
    scanf("%d%d", &n, &x);

    // Insert checks after reading inputs
    check_large_x_invariant(x);
    check_divisor_invariant(n, x);

    int k = 0;
    for (int i = 1; i <= pow(x, 0.5); i++) {
        if (x % i == 0 && i != pow(x, 0.5) && x / i <= n)
            k = k + 2;
        else if (x % i == 0 && i == pow(x, 0.5) && x / i <= n)
            k = k + 1;
    }
    printf("%d\n", k);
    return 0;
}