#include <bits/stdc++.h>
using namespace std;

long long m = 1000000007;

long long binpow(long long a, long long n) {
    if (n == 1) return a;
    if (n == 0) return 1;
    long long b = binpow(a, n / 2);
    return (((b * b) % m) * (binpow(a, n % 2))) % m;
}

// Prime factorization complexity check
void check_prime_factorization_invariant(long long x) {
    if (x > 1e9 / 10) {  // Arbitrary threshold indicating large `x`
        cerr << "Warning: Performance bottleneck condition triggered - large prime factorization!" << endl;
        abort();
    }
}

// Repeated power calculations check
void check_power_calculation_invariant(long long n) {
    if (n > 1e17) {  // Threshold indicating large `n`
        cerr << "Warning: Performance bottleneck condition triggered - large power calculations!" << endl;
        abort();
    }
}

// Compound check for both large `x` and `n`
void check_compound_invariant(long long x, long long n) {
    if (x > 1e9 / 10 && n > 1e17) {
        cerr << "Warning: Performance bottleneck condition triggered - large `x` and `n` combination!" << endl;
        abort();
    }
}

signed main() {
    long long n, x;
    cin >> x >> n;

    // Perform checks after reading inputs
    check_prime_factorization_invariant(x);
    check_power_calculation_invariant(n);
    check_compound_invariant(x, n);

    vector<long long> pr;
    long long x1 = x;
    for (long long i = 2; i <= (long long)sqrt(x); ++i) {
        if (x1 % i != 0) continue;
        pr.push_back(i);
        while (x1 % i == 0) {
            x1 /= i;
        }
    }
    long long ans = 1;
    if (x1 != 1) pr.push_back(x1);
    for (auto p : pr) {
        long long n1 = n;
        while (n1 >= p) {
            n1 /= p;
            ans = (ans * (binpow(p, n1))) % m;
        }
    }
    cout << ans;
}