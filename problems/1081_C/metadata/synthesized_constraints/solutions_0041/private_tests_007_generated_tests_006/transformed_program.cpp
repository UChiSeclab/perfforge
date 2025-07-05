#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e3 + 9, lg = 19, MOD = 998244353, maxV = 1e6 + 9;
int n, m, k;
long long dp[maxN][maxN];

void check_high_variation_count(int n, int k) {
    if (k > n / 2) {  // Example threshold: when k is more than half of n
        cerr << "Warning: Performance bottleneck condition triggered - high variation count!" << endl;
        abort();
    }
}

void check_large_color_space(int m, int threshold = 1500) {  // Example threshold
    if (m > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - large color space!" << endl;
        abort();
    }
}

void check_extensive_dp_updates(int n, int k) {
    if (n > 1800 && k > 900) {  // Example thresholds close to upper boundaries
        cerr << "Warning: Performance bottleneck condition triggered - extensive DP updates!" << endl;
        abort();
    }
}

long long getsum(int i) {
    long long sm = 0;
    for (int j = 0; j < m; j++) sm = (sm + dp[i][j]) % MOD;
    return sm;
}

long long fdp() {
    for (int i = k; i >= 0; i--) {
        long long sm = getsum(i + 1);
        if (i == k) sm = 1;
        for (int j = 0; j < m; j++) dp[i][j] = (sm + MOD - dp[i + 1][j]) % MOD;
    }
    return getsum(0);
}

long long sdp() {
    memset(dp, 0, sizeof dp);
    dp[n][0] = 1;
    for (int i = n - 1; i >= 0; i--)
        for (int j = 1; j <= k + 1; j++)
            dp[i][j] = (dp[i + 1][j] + dp[i + 1][j - 1]) % MOD;
    return dp[0][k + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    
    // Performance-checking function calls
    check_high_variation_count(n, k);
    check_large_color_space(m);
    check_extensive_dp_updates(n, k);
    
    cout << fdp() * sdp() % MOD << '\n';
}