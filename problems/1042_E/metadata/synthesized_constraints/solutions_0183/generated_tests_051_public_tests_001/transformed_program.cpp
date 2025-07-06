#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000;
const long long MOD = 998244353;
long long dp[MAXN][MAXN], a[MAXN][MAXN], dpp, xp, xpp, yp, ypp;
int n, m, cnt;
pair<long long, long long> id[MAXN * MAXN];

long long pw(long long a, long long b) {
    check_power_calculation_invariant(b);  // Check for large exponent in power calculation
    if (b == 0) return 1LL;
    return pw(a * a % MOD, b / 2) * (b % 2 ? a : 1LL) % MOD;
}

bool cmp(pair<int, int> x, pair<int, int> y) {
    return a[x.first][x.second] < a[y.first][y.second];
}

void check_power_calculation_invariant(int exponent) {
    if (exponent > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - large power calculations!" << endl;
        abort();
    }
}

void check_sorting_invariant(int elementCount, int duplicateCount) {
    if (elementCount > 500 && duplicateCount > elementCount / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive sorting and handling of duplicates!" << endl;
        abort();
    }
}

void check_grouping_invariant(int groupSize) {
    if (groupSize > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - large element groups in nested loops!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j], id[cnt++] = make_pair(i, j);
    
    sort(id, id + cnt, cmp);
    check_sorting_invariant(cnt, cnt);  // Assume potential duplicates for simplicity

    int pt = 0;
    for (int i = 0, pt = 0; i < cnt; i = pt = pt + 1) {
        while (a[id[i].first][id[i].second] == a[id[pt + 1].first][id[pt + 1].second])
            pt++;
        check_grouping_invariant(pt - i + 1);  // Check size of current group of elements

        for (int j = i; j <= pt; j++) {
            long long x = id[j].first, y = id[j].second;
            dp[x][y] = ((x * x * i % MOD + y * y * i % MOD + dpp - 2 * x * xp % MOD -
                         2 * y * yp + xpp + ypp) % MOD + MOD) % MOD;
            dp[x][y] = dp[x][y] * pw(i, MOD - 2) % MOD;
        }
        for (int j = i; j <= pt; j++) {
            long long x = id[j].first, y = id[j].second;
            dpp = (dpp + dp[x][y]) % MOD;
            xp = (xp + x) % MOD;
            yp = (yp + y) % MOD;
            xpp = (xpp + x * x) % MOD;
            ypp = (ypp + y * y) % MOD;
        }
    }
    long long r, c;
    cin >> r >> c;
    cout << dp[r][c] << '\n';
    return 0;
}