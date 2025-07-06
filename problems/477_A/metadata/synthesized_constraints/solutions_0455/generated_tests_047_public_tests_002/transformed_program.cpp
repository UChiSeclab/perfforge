#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int MAXN = 1000006;
long long a, b;

// Checker functions
void check_large_b_invariant(long long b) {
    if (b > 1000000) {  // arbitrary threshold to detect large `b`
        cerr << "Warning: Performance bottleneck - large number of iterations due to large b!" << endl;
        abort();
    }
}

void check_function_call_invariant(long long b) {
    if (b > 1000000) { // arbitrary threshold to detect repeated expensive function calls
        cerr << "Warning: Performance bottleneck - excessive calls to suma due to large b!" << endl;
        abort();
    }
}

void check_arithmetic_operations_invariant(long long b) {
    if (b > 1000000) { // arbitrary threshold considering arithmetic operations
        cerr << "Warning: Performance bottleneck - excessive arithmetic operations due to high iterations!" << endl;
        abort();
    }
}

long long suma(long long e, long long l) {
    long long m1 = e, m2 = e + 1;
    if (m1 % 2 == 0)
        m1 /= 2;
    else
        m2 /= 2;
    m1 %= mod;
    m2 %= mod;
    e %= mod;
    return (m1 * m2 % mod * b % mod * l % mod + l * (e + 1)) % mod;
}

int main() {
    scanf("%lld%lld", &a, &b);
    
    // Insert performance checkers
    check_large_b_invariant(b);
    check_function_call_invariant(b);
    check_arithmetic_operations_invariant(b);

    long long ret = 0;
    for (int l = 1; l < b; ++l) {
        ret += suma(a, l);
        ret += mod - l;
    }
    printf("%lld\n", ret % mod);
    return 0;
}