#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long pow_mod(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long C(int n, int m) {
    long long resdw1 = 1;
    for (int i = 1; i <= n; i++) resdw1 = resdw1 * i % MOD;
    long long resdw2 = 1;
    for (int i = 1; i <= m - n; i++) resdw2 = resdw2 * i % MOD;
    long long resup = 1;
    for (int i = 1; i <= m; i++) resup = resup * i % MOD;
    return resup * pow_mod(resdw1, MOD - 2) % MOD * pow_mod(resdw2, MOD - 2) % MOD;
}

void check_small_k_large_n(int n, int k) {
    if (k == 1 && n > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - Small k with large n!" << endl;
        abort();
    }
}

void check_high_iteration_count(int n, int k) {
    if ((n / k) > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - High iteration count in main loop!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    long long ans = 0;
    cin >> n >> k;
    
    // Check for potential performance bottlenecks
    check_small_k_large_n(n, k);
    check_high_iteration_count(n, k);
    
    if (n < k) {
        cout << 0 << endl;
        exit(0);
    }
    
    for (int i = 1; i * k <= n; i++) {
        ans += C(k - 1, n / i - 1);
        ans %= MOD;
    }
    
    cout << ans << endl;
    return 0;
}