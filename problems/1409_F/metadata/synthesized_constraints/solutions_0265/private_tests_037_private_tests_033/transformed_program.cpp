#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
using namespace std;
long long dp[205][205][205];

// Checker functions
void check_high_replacement_allowance(int n, int k) {
    if (k > n / 2) {
        cerr << "Warning: High replacement allowance invariant triggered!" << endl;
        abort();
    }
}

void check_nested_loop_complexity(int n, int k) {
    if (n >= 150 && k >= 150) {
        cerr << "Warning: Nested loop complexity invariant triggered!" << endl;
        abort();
    }
}

void check_same_character_redundancy(const string& t) {
    if (t[0] == t[1]) {
        cerr << "Warning: Same character redundancy invariant triggered!" << endl;
        abort();
    }
}

void solve() {
    long long n, k, ans = 0;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;

    // Invariant checks based on the input
    check_high_replacement_allowance(n, k);
    check_nested_loop_complexity(n, k);
    check_same_character_redundancy(t);

    memset(dp, -0x3f3f3f3f, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int ck = 0; ck <= n; ck++) {
                if (dp[i][j][k] == -0x3f3f3f3f) continue;
                int e0 = s[i] == t[0];
                int e1 = s[i] == t[1];
                int e01 = t[1] == t[0];
                dp[i + 1][j][ck + e0] =
                    max(dp[i + 1][j][ck + e0], dp[i][j][ck] + (e1 ? ck : 0));
                if (j < k) {
                    dp[i + 1][j + 1][ck + 1] =
                        max(dp[i + 1][j + 1][ck + 1], dp[i][j][ck] + (e01 ? ck : 0));
                    dp[i + 1][j + 1][ck + e01] =
                        max(dp[i + 1][j + 1][ck + e01], dp[i][j][ck] + ck);
                }
            }
        }
    }
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= n; j++) ans = max(ans, dp[n][i][j]);
    cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    solve();
    return 0;
}