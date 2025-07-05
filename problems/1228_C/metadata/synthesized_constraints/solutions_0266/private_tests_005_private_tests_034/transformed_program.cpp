#include <bits/stdc++.h>
using namespace std;
const int mod = (1e9) + 7;

bool isprime(long long int a) {
    if (a <= 1) return false;
    for (long long int i = 2; i < floor(sqrt(a) + 1); i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

long long int modpow(long long int x, long long int y) {
    long long int ans = 1;
    while (y > 0) {
        if (y & 1) {
            ans = ((ans % mod) * (x % mod)) % mod;
        }
        y = y >> 1;
        x = ((x % mod) * (x % mod)) % mod;
    }
    return ans;
}

// Checker functions
void check_prime_checker_invariant(long long int x) {
    if (floor(sqrt(x)) > 31622) {  // Approximate upper threshold for x = 10^9
        cerr << "Warning: Performance bottleneck condition triggered due to high prime checking overhead!" << endl;
        abort();
    }
}

void check_large_n_invariant(long long int n) {
    if (n > 1e18) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive iterations with large n!" << endl;
        abort();
    }
}

void check_composite_x_invariant(long long int x) {
    int divisor_count = 0;
    for (long long int i = 1; i <= floor(sqrt(x)); ++i) {
        if (x % i == 0) {
            divisor_count += (i == x / i) ? 1 : 2;
        }
    }
    if (divisor_count > 10) {  // Threshold number of divisors
        cerr << "Warning: Performance bottleneck condition triggered due to many divisors of x!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int x, n, ans = 1;
    cin >> x >> n;
    
    // Insert checks after input
    check_prime_checker_invariant(x);  // Check for high prime checking overhead
    check_large_n_invariant(n);        // Check for large n
    check_composite_x_invariant(x);    // Check for composite structure of x

    for (long long int i = 1; i < floor(sqrt(x)) + 1; i++) {
        if (x % i == 0 && isprime(i)) {
            long long int m = n / i;
            while (m) {
                ans = (ans * modpow(i, m)) % mod;
                m = m / i;
            }
        }
        if (x % i == 0 && isprime((x / i)) && i != (x / i)) {
            long long int m = n / (x / i);
            while (m) {
                ans = (ans * modpow((x / i), m)) % mod;
                m = m / (x / i);
            }
        }
    }
    cout << ans;
    return 0;
}