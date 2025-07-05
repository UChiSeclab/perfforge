#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5 + 50;
const long long MOD = 1e9 + 7;
long long n, x;
int len = 0;
long long prime[MX];
bool is_prime[MX];

// Check for a large number of prime factors
void check_prime_factor_count(int primeFactorCount) {
    if (primeFactorCount > 10) {  // Threshold determined to detect potential slowdowns
        cerr << "Warning: Performance bottleneck condition triggered - too many prime factors of x!" << endl;
        abort();
    }
}

// Check for large exponentiation due to high powers
void check_large_exponentiation(long long base, long long exponent) {
    if (exponent > 1e9) {  // Arbitrary threshold to indicate potential slowdown
        cerr << "Warning: Performance bottleneck condition triggered - large exponentiation!" << endl;
        abort();
    }
}

// Check for excessive iteration in prime factor loop
void check_excessive_iterations(long long n, long long prime) {
    if (n / prime > 1e9) {  // Threshold to catch excessive loop iterations
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterations in loop!" << endl;
        abort();
    }
}

long long qadd(long long x, long long p) {
    long long ans = 0;
    while (p) {
        if (p & 1) ans = (x + ans) % MOD;
        x = (x + x) % MOD;
        p >>= 1;
    }
    return ans;
}

long long qpow(long long x, long long p) {
    long long ans = 1;
    while (p) {
        if (p & 1) ans = qadd(ans, x);
        x = qadd(x, x);
        p >>= 1;
    }
    return ans;
}

void init() {
    memset(is_prime, true, sizeof(is_prime));
    for (int i = 2; i < MX; i++) {
        if (is_prime[i]) {
            prime[len++] = i;
            for (int j = i * 2; j < MX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

long long p[MX];
int plen = 0;

void make_p() {
    for (int i = 0; i < len && x != 0; i++) {
        if (x % prime[i] == 0)
            p[plen++] = prime[i];
        else
            continue;
        while (x % prime[i] == 0) {
            x /= prime[i];
        }
    }
    if (x != 1) p[plen++] = x;

    // Check for a large number of prime factors
    check_prime_factor_count(plen);
}

int main() {
    ios::sync_with_stdio(true);
    init();
    cin >> x >> n;
    make_p();
    long long ans = 1;
    for (int i = 0; i < plen; i++) {
        long long t = p[i], cnt = 0, pre = 0;

        // Check for excessive iteration in prime factor loop
        check_excessive_iterations(n, p[i]);

        while (t <= n / p[i]) t *= p[i];
        while (t / p[i] != 0) {
            long long mi = n / t - pre;

            // Check for large exponentiation
            check_large_exponentiation(t, mi);

            ans = ans * qpow(t, mi) % MOD;
            pre = n / t;
            t /= p[i];
        }
    }
    cout << ans << endl;
}