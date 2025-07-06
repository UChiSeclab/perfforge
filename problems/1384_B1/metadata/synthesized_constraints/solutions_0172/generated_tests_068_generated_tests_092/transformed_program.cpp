#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7f7f7f7f;
const int N = 1e2 + 10;
const long long mod = 1e9 + 7;
const double PI = 3.14;

void check_depth_invariant(int depth, int tideEffect, int l) {
    if (depth + tideEffect >= l) {
        cerr << "Warning: Performance bottleneck condition triggered - depth close to threshold!" << endl;
        abort();
    }
}

void check_tide_invariant(int k, int l, int maxDepth) {
    if (2 * k + maxDepth >= l) {
        cerr << "Warning: Performance bottleneck condition triggered - large k with tight depth constraint!" << endl;
        abort();
    }
}

void check_cumulative_tide_invariant(int cumulativeTide, int l) {
    if (cumulativeTide >= l) {
        cerr << "Warning: Performance bottleneck condition triggered - high cumulative tide effects!" << endl;
        abort();
    }
}

int read() {
    char ch = getchar();
    int x = 0, f = 1;
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int random(int n) { return (long long)rand() * rand() % n; }
int a[N];
int dp[N][100005];
int sum[100005];

void solve() {
    int n = read(), k = read(), l = read();
    int maxDepth = 0;
    
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        if (a[i] > maxDepth) maxDepth = a[i];
    }

    // Check invariant related to large `k` with tight depth constraint
    check_tide_invariant(k, l, maxDepth);

    memset(dp, 0, sizeof dp);
    memset(sum, 0, sizeof sum);
    int cnt = 0;

    for (int i = 1; i < 100005; i++) {
        int x;
        if (cnt % (2 * k) < k)
            x = 1;
        else
            x = -1;
        sum[i] = sum[i - 1] + x;
        cnt++;

        // Check invariant related to cumulative tide effects
        check_cumulative_tide_invariant(sum[i], l);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < 100005; j++) {
            if (i == 1) {
                if (a[i] + sum[j] <= l) {
                    dp[i][j] = 1;
                }
            } else {
                if (dp[i - 1][j - 1] && a[i] + sum[j] <= l) {
                    dp[i][j] = 1;
                }
                if (dp[i][j - 1] && a[i] + sum[j] <= l) {
                    dp[i][j] = 1;
                }
            }

            // Check invariant related to depth values close to threshold
            check_depth_invariant(a[i], sum[j], l);
        }
    }

    for (int i = 1; i <= n; i++) {
        int flag = 1;
        for (int j = 1; j < 100005; j++) {
            if (dp[i][j] == 1) flag = 0;
        }
        if (flag) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main() {
    srand((unsigned)time(0));
    int t = read();
    while (t--) {
        solve();
    }
    return 0;
}