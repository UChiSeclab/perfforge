#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int n, k;
long long cnt[500500];
long long pw[500500];
long long fact[500500], rev[500500];

// Checkers for performance bottlenecks
void check_recursion_invariant(long long n) {
    if (n > 30) { // Arbitrary threshold for recursion depth
        cerr << "Warning: recursion_invariant triggered - excessive recursion depth in binpow" << endl;
        abort();
    }
}

void check_nested_loop_invariant(long long n) {
    if (n > 10000) { // Threshold for nested loops
        cerr << "Warning: nested_loop_invariant triggered - potentially expensive nested loop in cnt calculation" << endl;
        abort();
    }
}

void check_combinatorial_invariant(long long n, long long k) {
    if (n > 10000 && k < 100) { // Conditions for excessive combinatorial calculations
        cerr << "Warning: combinatorial_invariant triggered - excessive combinatorial calculations" << endl;
        abort();
    }
}

long long binpow(long long a, long long n) {
    check_recursion_invariant(n); // Check recursion depth before entering
    if (n == 0) return 1;
    if (n % 2 == 1)
        return (binpow(a, n - 1) * a) % mod;
    else {
        long long b = binpow(a, n / 2);
        return (b * b) % mod;
    }
}

long long cnk(long long n, long long k) {
    if (n < k) return 0;
    if (k == 0) return 1;
    long long result = (fact[n] * rev[k]) % mod;
    return (result * rev[n - k]) % mod;
}

void solve() {
    cin >> n >> k;
    check_combinatorial_invariant(n, k); // Check combinatorial computation conditions
    pw[0] = 1;
    fact[0] = 1;
    rev[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
        rev[i] = binpow(fact[i], mod - 2);
        pw[i] = (pw[i - 1] * 2) % mod;
    }
    check_nested_loop_invariant(n); // Check before nested loop begins
    for (int i = 1; i <= n; ++i)
        for (int j = i + i; j <= n; j += i) ++cnt[i];
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = (ans + cnk(cnt[i], k - 1)) % mod;
    }
    cout << ans << "\n";
}

int main() {
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
    return 0;
}