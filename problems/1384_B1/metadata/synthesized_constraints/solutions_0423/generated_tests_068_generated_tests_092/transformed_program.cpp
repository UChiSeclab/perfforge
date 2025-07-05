#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e2 + 5;
const int maxm = 1e6 + 2;
int a[maxn];
int dp[maxn][maxn * maxn];

void check_depth_tide_invariant(int a[], int n, int k, int l) {
    for (int i = 1; i <= n; ++i) {
        for (int dh = 0; dh < 2 * k; ++dh) {
            int tide_effect = (dh <= k) ? dh : 2 * k - dh;
            if (a[i] + tide_effect > l) {
                cerr << "Warning: Depth and tide interaction invariant triggered!" << endl;
                abort();
            }
        }
    }
}

void check_dp_table_invariant(int n, int k) {
    const int max_size_allowed = 100 * 2 * 100;
    if (n * 2 * k > max_size_allowed) {
        cerr << "Warning: DP table size invariant triggered - potentially large DP table size!" << endl;
        abort();
    }
}

void check_depth_distribution_invariant(int a[], int n, int l) {
    int high_depth_count = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= l - 1) {
            ++high_depth_count;
        }
    }
    if (high_depth_count > n / 2) {
        cerr << "Warning: Depth distribution invariant triggered - too many high-depth segments!" << endl;
        abort();
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(dp, 0, sizeof(dp));
        int n, k, l;
        scanf("%d%d%d", &n, &k, &l);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        
        // Inserting invariant checks before heavy processing
        check_depth_tide_invariant(a, n, k, l);
        check_dp_table_invariant(n, k);
        check_depth_distribution_invariant(a, n, l);

        for (int i = 0; i <= 2 * k * n; i++) dp[0][i] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 2 * k * n; j++) {
                if (!dp[i][j - 1] && !dp[i - 1][j - 1]) continue;
                int dh = j % (2 * k);
                if (dh > k) dh = 2 * k - dh;
                if (a[i] + dh <= l) dp[i][j] = 1;
            }
        }

        bool flag = 0;
        for (int i = 1; i <= 2 * k * n; i++) {
            if (dp[n][i]) {
                flag = 1;
                break;
            }
        }
        if (flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}