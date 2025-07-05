#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

// Checker for high prime factor count
void check_high_prime_factor_count(const std::vector<long long>& primes) {
    if (primes.size() > 10) {  // Assuming more than 10 prime factors is excessive for x
        cerr << "Warning: High prime factor count detected, potential slowdown!" << endl;
        abort();
    }
}

// Checker for deep factorization
void check_deep_factorization(long long x, const std::vector<long long>& primes) {
    long long factor_count = 0;
    for (long long p : primes) {
        while (x % p == 0) {
            x /= p;
            factor_count++;
            if (factor_count > 20) {  // Arbitrary threshold for deep factorization
                cerr << "Warning: Deep factorization detected, potential slowdown!" << endl;
                abort();
            }
        }
    }
}

// Checker for heavy recursive computation
void check_heavy_recursive_computation(long long n) {
    if (n > 1e17) {  // Set a threshold for n indicating potential deep recursion
        cerr << "Warning: Large n detected, potential heavy recursive computation!" << endl;
        abort();
    }
}

// Checker for complexity of primality sieve
void check_primality_sieve_complexity(long long x) {
    long long MX = 2 * sqrt(x);
    if (MX > 10000) {  // Assuming a large MX could lead to slow primality sieving
        cerr << "Warning: High complexity in primality sieve, potential slowdown!" << endl;
        abort();
    }
}

long long calc(long long n, long long x) {
    long long z = 0;
    while (n) {
        z += n / x;
        n /= x;
    }
    return z;
}

long long mul(long long x, long long y) {
    x %= mod;
    y %= mod;
    return (x * y) % mod;
}

long long pp(long long x, long long y) {
    long long res = 1;
    while (y) {
        if (y & 1) res = mul(res, x);
        x = mul(x, x);
        y >>= 1;
    }
    return res;
}

int main(int argc, char const *argv[]) {
    long long x, n;
    cin >> x >> n;
    
    // Perform initial checks
    check_heavy_recursive_computation(n);
    check_primality_sieve_complexity(x);

    const long long MX = 2 * sqrt(x);
    std::vector<bool> v(MX, 0);
    std::vector<long long> p;
    v[1] = 1;
    for (int i = 1; i < MX; ++i) {
        if (v[i]) continue;
        if (x % i == 0) p.push_back(i);
        for (int j = 2 * i; j < MX; j += i) v[j] = 1;
    }

    // Check prime factor count
    check_high_prime_factor_count(p);

    set<long long> P;
    long long tmp = x;
    for (long long xx : p) {
        if (tmp % xx == 0) {
            while (tmp % xx == 0) tmp /= xx;
        }
    }
    if (tmp > 1) p.push_back(tmp);

    // Check deep factorization
    check_deep_factorization(x, p);

    long long ans = 1;
    for (long long xx : p) {
        ans = mul(ans, pp(xx, calc(n, xx)));
    }
    cout << ans << endl;
    return 0;
}