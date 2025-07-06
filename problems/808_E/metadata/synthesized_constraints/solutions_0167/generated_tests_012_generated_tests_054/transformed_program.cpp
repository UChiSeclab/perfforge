#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 300010;
struct {
    ll v;
    ll c1, c2;
} dp[N];
int num[4], n, m;
ll a[4][N], s[4][N];

// Checker function for dynamic programming array usage
void check_dp_invariant(int m, int dp_updates) {
    if (dp_updates > m * 2) {  // Example threshold: twice the capacity, considering multiple checks per element
        cerr << "Warning: Performance bottleneck condition triggered - excessive DP array updates!" << endl;
        abort();
    }
}

// Checker function for sorting efficiency
void check_sort_invariant(int n, int num_elements_sorted) {
    if (num_elements_sorted > n * 0.8) {  // Example threshold: sorting more than 80% of elements
        cerr << "Warning: Performance bottleneck condition triggered - large array sorted frequently!" << endl;
        abort();
    }
}

int main() {
    scanf("%d%d", &n, &m);
    memset(num, 0, sizeof num);
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; ++i) {
        ll w, c;
        scanf("%lld%lld", &w, &c);
        a[w][++num[w]] = c;
    }

    // Check if sorting operation could trigger performance issues
    int total_elements_sorted = 0;
    for (int i = 1; i <= 3; ++i) {
        s[i][0] = 0;
        sort(a[i] + 1, a[i] + num[i] + 1,
             [](const int &a, const int &b) { return a > b; });
        total_elements_sorted += num[i];
        for (int j = 1; j <= num[i]; ++j) s[i][j] = s[i][j - 1] + a[i][j];
    }
    check_sort_invariant(n, total_elements_sorted);

    dp[0].v = dp[0].c1 = dp[0].c2 = 0;
    int dp_updates = 0;  // Counter for DP updates to check against bottleneck

    for (int i = 1; i <= m; ++i) {
        if (dp[i - 1].v + a[1][dp[i - 1].c1 + 1] > dp[i].v) {
            dp[i].v = dp[i - 1].v + a[1][dp[i - 1].c1 + 1];
            dp[i].c1 = dp[i - 1].c1 + 1;
            dp[i].c2 = dp[i - 1].c2;
            dp_updates++;
        }
        if (i > 1 && dp[i - 2].v + a[2][dp[i - 2].c2 + 1] > dp[i].v) {
            dp[i].v = dp[i - 2].v + a[2][dp[i - 2].c2 + 1];
            dp[i].c1 = dp[i - 2].c1;
            dp[i].c2 = dp[i - 2].c2 + 1;
            dp_updates++;
        }
    }

    // Perform check for excessive DP updates
    check_dp_invariant(m, dp_updates);

    ll ans = 0;
    for (int i = 0; i <= num[3]; ++i) {
        if (m >= i * 3) ans = max(ans, s[3][i] + dp[m - i * 3].v);
    }
    printf("%lld\n", ans);

    return 0;
}