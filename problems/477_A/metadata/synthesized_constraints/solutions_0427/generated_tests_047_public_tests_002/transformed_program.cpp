#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
const int d = mod / 2 + 1;
int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return (long long int)a * b % mod; }

// Checker functions
void check_high_iteration_invariant(long long b) {
    if (b > 10000000 / 10) { // Arbitrary threshold
        cerr << "Warning: High iteration count due to large b value!" << endl;
        abort();
    }
}

void check_frequent_multiplication_invariant(long long a, long long b) {
    if (b > 10000000 / 10 && a > 10000000 / 10) { // Threshold indicating potential high-cost multiplications
        cerr << "Warning: Frequent multiplication with large numbers!" << endl;
        abort();
    }
}

void check_frequent_addition_invariant(long long b) {
    if (b > 10000000 / 10) { // Same threshold as iteration count
        cerr << "Warning: Frequent addition operations in loop due to large b!" << endl;
        abort();
    }
}

int main() {
    long long int a, b;
    scanf("%lld%lld", &a, &b);

    // Insert checkers
    check_high_iteration_invariant(b);
    check_frequent_multiplication_invariant(a, b);
    check_frequent_addition_invariant(b);

    long long int ans = 0;
    for (long long int m = 1; m < b; m++) {
        long long int sum_t = mul(mul(mul(m, a + 1), a), d);
        long long int cur_add = mul(b, sum_t) + mul(m, a);
        cur_add %= mod;
        ans = add(ans, cur_add);
    }
    printf("%lld\n", ans);
    return 0;
}