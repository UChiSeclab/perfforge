#include <bits/stdc++.h>
using namespace std;
const int maxk = 1e3 + 7;
const int p = 1000000007;
int k;
int c[maxk];
long long dp[maxk];
int cnt;
long long n, m;

void check_recursive_depth_invariant(int ball_count) {
    if (ball_count > 600) { // Arbitrary threshold based on performance testing
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth due to large ball count!" << endl;
        abort();
    }
}

void check_nested_loop_invariant(int color_count) {
    if (color_count > 800) { // Assume a high number of colors can trigger slowdowns due to loop nesting
        cerr << "Warning: Performance bottleneck condition triggered - excessive nested loop iterations!" << endl;
        abort();
    }
}

void check_modular_operations_invariant(int calls) {
    if (calls > 100000) { // Threshold for considering modular operations to be excessive
        cerr << "Warning: Performance bottleneck condition triggered - excessive modular operations in recursion!" << endl;
        abort();
    }
}

long long quick_mod(long long a, long long b) {
    long long ans = 1;
    a %= p;
    int calls = 0; // Track number of modular operations
    while (b) {
        if (b & 1) {
            ans = ans * a % p;
            b--;
        }
        b >>= 1;
        a = a * a % p;
        calls++;
    }
    check_modular_operations_invariant(calls);
    return ans;
}

long long C(long long n, long long m) {
    if (m > n) return 0;
    long long ans = 1;
    for (int i = 1; i <= m; i++) {
        long long a = (n + i - m) % p;
        long long b = i % p;
        ans = ans * (a * quick_mod(b, p - 2) % p) % p;
    }
    return ans;
}

long long Lucas(long long n, long long m) {
    if (m == 0) return 1;
    return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}

long long fun(long long x) {
    long long ans = 0;
    // Check for potential performance issues with ball count
    check_recursive_depth_invariant(x);
    for (int i = 0; i < x - 1; i++) {
        long long t = Lucas(x - 2, i);
        long long y = Lucas(cnt + 1, i + 1);
        ans = (ans % p + (t % p * y % p) % p) % p;
    }
    if (!ans) return 1ll;
    return ans;
}

void solve() {
    dp[0] = 1;
    cnt = c[0];
    check_nested_loop_invariant(k); // Check color count before entering main loop
    for (int i = 1; i < k; i++) {
        dp[i] = dp[i - 1] * fun(c[i]) % p;
        cnt += c[i];
    }
    cout << dp[k - 1] << endl;
}

int main() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> c[i];
    }
    solve();
}