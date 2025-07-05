#include <bits/stdc++.h>
using namespace std;

// Checkers for performance bottlenecks
void check_binomial_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - intensive binomial coefficient computation!" << endl;
        abort();
    }
}

void check_power_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive computations in power function!" << endl;
        abort();
    }
}

// Function declarations
long long power(long long x, long long y, long long p);
void binomialCoeff(long long n, long long k);

long long C[2001][2000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, m, k;
    cin >> n >> m >> k;

    // Performance bottleneck checks
    check_binomial_invariant(n > 1500 && k > 1500); // Checks for expensive binomial coefficient computation
    check_power_invariant(k > 1500); // Checks for excessive power computations

    binomialCoeff(n, k);
    
    long long mminus1 = power(m - 1, k, 998244353);
    mminus1 %= 998244353;
    long long ans = 1;
    ans *= mminus1 % 998244353;
    ans = ((ans % 998244353) * (m)) % 998244353;
    ans = ((ans % 998244353) * (C[n - 1][k])) % 998244353;
    cout << ans << endl;
    return 0;
}

long long power(long long x, long long y, long long p) {
    long long res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

void binomialCoeff(long long n, long long k) {
    long long i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= k; j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = (C[i - 1][j - 1] % 998244353 + C[i - 1][j] % 998244353) % 998244353;
        }
    }
}