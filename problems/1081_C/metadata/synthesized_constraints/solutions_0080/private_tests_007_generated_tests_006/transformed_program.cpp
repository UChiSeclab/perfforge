#include <bits/stdc++.h>
const int maxn = 2005;
const long long mod = 998244353;
using namespace std;
long long dp[maxn][maxn];

void check_high_variation_count(int n, int k) {
    if (k > 0.9 * n) {
        cerr << "Warning: Performance bottleneck condition triggered - High variation count!" << endl;
        abort();
    }
}

void check_high_loop_iterations(int n, int k) {
    if (k > 0.8 * n) {
        cerr << "Warning: Performance bottleneck condition triggered - High loop iterations!" << endl;
        abort();
    }
}

void check_resource_intensive_calculations(int n, int k) {
    if (k > 0.85 * n) {
        cerr << "Warning: Performance bottleneck condition triggered - Resource-intensive calculations!" << endl;
        abort();
    }
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    // Insert checks after input reading
    check_high_variation_count(n, k);  // Check for high variation count
    check_high_loop_iterations(n, k);  // Check for high loop iterations
    check_resource_intensive_calculations(n, k);  // Check for resource-intensive calculations

    dp[1][0] = m;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * (m - 1) % mod) % mod;
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}