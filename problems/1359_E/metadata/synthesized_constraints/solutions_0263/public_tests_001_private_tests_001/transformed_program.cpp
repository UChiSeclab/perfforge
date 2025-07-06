#include <bits/stdc++.h>
using namespace std;

const long long mod = (long long)998244353;
const long long MAXN = (long long)5e5 + 1;

long long fact[MAXN];

// Checker function for fast_pow
void check_fast_pow_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursive calls in fast_pow!" << endl;
        abort();
    }
}

// Checker function for combination calculations
void check_combination_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive combination calculations!" << endl;
        abort();
    }
}

// Checker function for factorial calculations
void check_factorial_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive factorial calculations!" << endl;
        abort();
    }
}

long long fast_pow(long long x, long long y) {
    check_fast_pow_invariant(y > 1e6); // Check before recursive calculations
    if (!y) return 1;
    if (y % 2) return (x * fast_pow(x, y - 1)) % mod;
    long long c = fast_pow(x, y / 2);
    return (c * c) % mod;
}

long long back(long long x) { return fast_pow(x, mod - 2); }

long long c(long long n, long long k) {
    if (k > n) return 0;
    return fact[n] * back(fact[n - k]) % mod * back(fact[k]) % mod;
}

void solve() {
    long long n, k;
    cin >> n >> k;

    fact[0] = 1;
    for (long long i = 1; i <= n; ++i) fact[i] = (fact[i - 1] * i) % mod;

    check_factorial_invariant(n > 1e5); // Check after factorial initialization

    long long ans = 0;

    for (long long i = 1; i <= n; ++i) {
        check_combination_invariant(i > 1e5 && k < 10); // Check during loop iteration
        ans += c(n / i - 1, k - 1);
        ans %= mod;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}