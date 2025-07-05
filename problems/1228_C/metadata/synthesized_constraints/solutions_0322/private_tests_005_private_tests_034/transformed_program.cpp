#include <bits/stdc++.h>
const int N = 1e5 + 100;
const int INF = 1e9;
const unsigned long long mod = 1e9 + 7;
using namespace std;

unsigned long long x, n, ans = 1;
vector<unsigned long long> d;

bool isprime(unsigned long long a) {
    if (a == 1) return false;
    for (unsigned long long i = 2; i <= sqrt(a); ++i) {
        if (a % i == 0) return false;
    }
    return true;
}

unsigned long long qpow(unsigned long long x, unsigned long long y) {
    unsigned long long ret = 1, a = x;
    for (; y; a = a * a % mod, y >>= 1)
        if (y & 1) ret = ret * a % mod;
    return ret;
}

void check_divisor_invariant(unsigned long long divisorCount, unsigned long long primeFactorCount) {
    if (divisorCount > 50000 || primeFactorCount > 10) {
        cerr << "Warning: Performance bottleneck due to excessive divisors or large prime factors!" << endl;
        abort();
    }
}

void check_power_calculation_invariant(unsigned long long powerIterations) {
    if (powerIterations > 1000000) {
        cerr << "Warning: Performance bottleneck due to excessive power calculations!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> n;

    unsigned long long divisorCount = 0;
    unsigned long long primeFactorCount = 0;

    // Find divisors and their primality
    for (unsigned long long i = 1; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            ++divisorCount;
            if (isprime(i)) d.push_back(i);
            if (isprime(x / i) && i * i != x) d.push_back(x / i);
        }
    }

    primeFactorCount = d.size();
    
    // Check for excessive divisors or large prime factors
    check_divisor_invariant(divisorCount, primeFactorCount);

    unsigned long long powerIterations = 0;

    // Calculate the product and check for excessive power calculations
    for (unsigned long long i = 0; i < d.size(); ++i) {
        unsigned long long tmp = d[i];
        while (1) {
            ans *= qpow(d[i], n / tmp);
            ans %= mod;
            ++powerIterations;
            if (n / tmp < d[i]) break;
            tmp *= d[i];
        }
    }
    
    // Check for excessive power calculations
    check_power_calculation_invariant(powerIterations);
    
    cout << ans % mod;
    return 0;
}