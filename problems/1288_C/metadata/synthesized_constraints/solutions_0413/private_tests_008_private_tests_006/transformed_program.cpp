#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
vector<long long> factorials;

long long modExp(long long x, long long n, int depth) {
    check_recursion_invariant(depth); // Check recursion depth
    if (n == 0) return 1;
    if (n == 1) return x;
    long long ans = modExp(x, n / 2, depth + 1);
    ans = (ans * ans) % mod;
    if (n % 2) ans *= x;
    return ans % mod;
}

long long modInv(long long a) { return modExp(a, mod - 2, 0); }

long long choose(long long n, long long k) {
    if (k > n) return 0;
    long long num = factorials[n];
    long long den = (factorials[k] * factorials[n - k]) % mod;
    return ((num * modInv(den)) % mod);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m;
    cin >> n >> m;

    // Checking for large n before loops
    check_nested_loop_invariant(n);

    factorials.resize(2 * n * m + 1);
    factorials[0] = factorials[1] = 1;
    for (int i = 2; i < 2 * n * m + 1; ++i) {
        factorials[i] = (factorials[i - 1] * i) % mod;
    }

    long long ans = 0;
    int numCombinations = 0;
    for (int i = 1; i < n + 1; ++i) {
        for (int k = i; k < n + 1; ++k) {
            ans += (choose(m + i - 2, i - 1) * choose(m + n - k - 1, n - k)) % mod;
            ans %= mod;
            numCombinations++;
        }
    }

    // Check for excessive combination calculations
    check_combination_invariant(numCombinations);

    cout << ans << "\n";
    return 0;
}