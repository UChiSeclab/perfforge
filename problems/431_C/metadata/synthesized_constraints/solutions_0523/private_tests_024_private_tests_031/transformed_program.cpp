#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void check_recursion_depth_and_branching(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive recursion depth and branching!" << endl;
        abort();
    }
}

void check_large_k(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to large k causing excessive loop iterations!" << endl;
        abort();
    }
}

void check_large_n(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to large n causing exhaustive path computation!" << endl;
        abort();
    }
}

// Function implementations
long long mod_mul(long long a, long long b) {
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}

long long mod_add(long long a, long long b) {
    a = a % mod;
    b = b % mod;
    return (((a + b) % mod) + mod) % mod;
}

long long n, k, d;
long long dp[101][101][101];

long long f(long long max_val, long long num_val, long long num) {
    if (num <= 0) return 0;
    if (num_val == 1) {
        if (num > max_val) return 0;
        return 1;
    }
    if (dp[max_val][num_val][num] != -1) return dp[max_val][num_val][num];
    long long ans = 0;
    for (long long i = 1; i <= max_val; i++) {
        ans = mod_add(f(max_val, num_val - 1, num - i), ans);
    }
    return dp[max_val][num_val][num] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin >> n >> k >> d;

    // Insert performance checks
    check_recursion_depth_and_branching(n > 80 && k > 80);
    check_large_k(k > 80);
    check_large_n(n > 80);

    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        ans = (ans + f(k, i, n) - f(d - 1, i, n) + mod) % mod;
    }
    cout << ans;

    return 0;
}