#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 100;
const int mod = 1e9 + 7;
long long dp[N][N];
long long g[N];

// Checker functions based on identified performance bottlenecks
void check_large_k_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: large_k_invariant triggered - excessive operations for large k" << endl;
        abort();
    }
}

void check_power_computation_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: power_computation_invariant triggered - inefficient power computations for large n" << endl;
        abort();
    }
}

void check_dp_array_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: dp_array_invariant triggered - large memory or computational overhead with dp array" << endl;
        abort();
    }
}

// Function to compute power modulo
long long PowerMod(long long a, long long b) {
    long long ans = 1;
    a = a % mod;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

void solve() {
    long long n;
    int k;
    scanf("%lld%d", &n, &k);

    // Invariant checks
    check_large_k_invariant(k > 4000);  // Arbitrary threshold for demonstration
    check_power_computation_invariant(n > 500000);  // Arbitrary threshold for demonstration
    check_dp_array_invariant(k > 4000);  // Arbitrary threshold for the size of dp

    long long ans = 0;
    long long temp = n;

    if (n <= k) {
        for (int i = 1; i <= n; i++) {
            ans += (temp * PowerMod(i, k));
            ans %= mod;
            temp = temp * (n - i) % mod * PowerMod(i + 1, mod - 2) % mod;
        }
    } else {
        dp[0][k] = PowerMod(2, n - k);
        for (int i = k - 1; i >= 0; i--) dp[0][i] = dp[0][i + 1] * 2 % mod;
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = ((n - j) * (dp[i - 1][j + 1] + g[j + 1]) % mod + j * dp[i - 1][j]) % mod;
                g[j + 1] = g[j + 1] * (j + 1) % mod;
            }
        }
        ans = dp[k][0];
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}