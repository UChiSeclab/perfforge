#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 100 + 5;
const long long inf = 9223372036854775807;
long long dp[2][maxn][maxn], n, m, b, mod, a[maxn];

void check_high_bug_tolerance(int b, const vector<int>& a) {
    int total_bug_rate = accumulate(a.begin(), a.end(), 0);
    if (b > total_bug_rate) {
        cerr << "Warning: Performance bottleneck condition triggered - high bug tolerance increases iterations!" << endl;
        abort();
    }
}

void check_high_bug_count(int max_bug_per_line, int b) {
    if (max_bug_per_line > 0 && b > 0) {
        cerr << "Warning: Performance bottleneck condition triggered - high bug count per line compounds DP computation!" << endl;
        abort();
    }
}

void check_large_dp_operations(int n, int m, int b) {
    if (n * m * b > 1000000) {  // Threshold for large DP computations
        cerr << "Warning: Performance bottleneck condition triggered - large DP operations due to dimensions!" << endl;
        abort();
    }
}

void check_large_mod_operations(int m, int b, int mod) {
    if (mod < 1000000 && (m > 100 || b > 100)) {  // Example thresholds
        cerr << "Warning: Performance bottleneck condition triggered - modulo operations with large m and b!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> b >> mod;
    vector<int> bug_rates(n);
    int max_bug_per_line = 0;
    for (int i = 0; i < n; i++) {
        cin >> bug_rates[i];
        a[i + 1] = bug_rates[i];
        max_bug_per_line = max(max_bug_per_line, bug_rates[i]);
    }
    
    // Insert performance checks
    check_high_bug_tolerance(b, bug_rates);
    check_high_bug_count(max_bug_per_line, b);
    check_large_dp_operations(n, m, b);
    check_large_mod_operations(m, b, mod);
    
    dp[0][0][0] = 1;
    for (int j = 1; j <= n; j++) {
        for (int i = 0; i <= m; i++) {
            for (int k = 0; k <= b; k++) {
                dp[j % 2][i][k] = 0;
            }
        }
        for (int i = 0; i <= m; i++) {
            for (int k = 0; k <= b; k++) {
                dp[j % 2][i][k] += dp[1 - (j % 2)][i][k] % mod;
                if (k >= a[j] && i > 0) {
                    dp[j % 2][i][k] += dp[j % 2][i - 1][k - a[j]] % mod;
                }
                dp[j % 2][i][k] = dp[j % 2][i][k] % mod;
            }
        }
    }
    long long sum = 0;
    for (int i = 0; i <= b; i++) {
        sum += dp[n % 2][m][i];
    }
    cout << sum % mod;
}