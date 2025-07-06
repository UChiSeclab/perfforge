#include <bits/stdc++.h>
using namespace std;

// Function to check for combinatorial calculation bottleneck
void check_combinatorial_invariant(int n, long long k) {
    if (n > 240 && k > 1e8) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive combinatorial calculations!" << endl;
        abort();
    }
}

// Function to check for recursive depth and breadth issues
void check_recursion_invariant(int n, long long k) {
    if (n > 240 && k > 1e8) {
        cerr << "Warning: Performance bottleneck due to high recursion depth or branching factor!" << endl;
        abort();
    }
}

// Function to check for repeated power calculation issues
void check_power_invariant(long long k) {
    if (k > 1e8) {
        cerr << "Warning: Performance bottleneck condition triggered by repeated power calculations!" << endl;
        abort();
    }
}

inline long long gcd(long long a, long long b) {
    a = ((a) < 0 ? -(a) : (a));
    b = ((b) < 0 ? -(b) : (b));
    while (b) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

const long long inf = 2147383647;
const long long mod = 1000000007;
const double pi = 2 * acos(0.0);
const double eps = 1e-9;

inline long long bigmod(long long a, long long p, long long m) {
    long long res = 1 % m, x = a % m;
    while (p) {
        if (p & 1) res = (res * x) % m;
        x = (x * x) % m;
        p >>= 1;
    }
    return res;
}

int n, k;
long long dp[255][255], fact[255], inv[255], ar[2][255];

long long ncr(int x, int y) {
    long long res = (fact[x] * inv[x - y]) % mod;
    res = (res * inv[y]) % mod;
    return res;
}

long long f(int row, int rem) {
    long long &res = dp[row][rem];
    if (res != -1) return res;
    if (row == n + 1) {
        res = (rem == 0) ? 1 : 0;
        return res;
    }
    res = 0;
    long long tmp;
    for (int i = 1; i <= rem; i++) {
        tmp = ncr(rem, i);
        tmp = (tmp * ar[1][rem - i]) % mod;
        tmp = (tmp * ar[0][n - rem]) % mod;
        tmp = (tmp * f(row + 1, rem - i));
        res = (res + tmp) % mod;
    }
    if (rem < n) {
        tmp = (ar[0][n - rem] - ar[1][n - rem] + mod) % mod;
        tmp = (tmp * bigmod(k - 1, rem, mod)) % mod;
        tmp = (tmp * f(row + 1, rem)) % mod;
        res = (res + tmp) % mod;
    }
    return res;
}

int main() {
    fact[0] = 1;
    for (long long i = 1; i <= 250; ++i) fact[i] = (fact[i - 1] * i) % mod;
    for (long long i = 0; i <= 250; ++i)
        inv[i] = bigmod(fact[i], mod - 2, mod);

    cin >> n >> k;

    // Check for potential performance bottlenecks
    check_combinatorial_invariant(n, k);
    check_recursion_invariant(n, k);
    check_power_invariant(k);

    if (k == 1) {
        cout << 1 << "\n";
        return 0;
    }

    ar[0][0] = 1;
    ar[1][0] = 1;
    for (long long i = 1; i <= 250; ++i) {
        ar[0][i] = (ar[0][i - 1] * k) % mod;
        ar[1][i] = (ar[1][i - 1] * (k - 1)) % mod;
    }

    memset(dp, -1, sizeof(dp));
    cout << f(1, n) << "\n";
    return 0;
}