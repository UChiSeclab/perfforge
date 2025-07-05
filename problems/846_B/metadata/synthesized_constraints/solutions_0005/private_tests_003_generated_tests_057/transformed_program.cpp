#include <bits/stdc++.h>
using namespace std;
const int maxN = 50;
const long long INF = (long long)1e18;
long long dp[maxN][maxN * maxN], a[maxN], sum[maxN];

void upd(long long& a, long long b) { a = min(a, b); }

// Invariant checkers
void check_combination_invariant(int n, int k, int M, const vector<long long>& a) {
    long long totalTime = 0;
    for (int time : a) totalTime += time;
    if (n > 30 && k > 5 && totalTime > M) {
        cerr << "Warning: combination_invariant triggered - too many subtask combinations possible" << endl;
        abort();
    }
}

void check_time_allocation_invariant(int M, const vector<long long>& a) {
    if (M > 1000000 && a.size() > 5) {
        cerr << "Warning: time_allocation_invariant triggered - substantial time for subtasks" << endl;
        abort();
    }
}

void check_dp_table_invariant(int n, int k) {
    if (n * k > 100) {
        cerr << "Warning: dp_table_invariant triggered - extensive DP table size" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, k, M;
    cin >> n >> k >> M;
    
    vector<long long> a(k + 1);
    for (int i = 1; i <= k; ++i) cin >> a[i];
    
    // Insert invariants checks after input
    check_combination_invariant(n, k, M, a);
    check_time_allocation_invariant(M, a);
    check_dp_table_invariant(n, k);
    
    sort(a.begin() + 1, a.end());
    sum[0] = 0;
    for (int i = 1; i <= k; ++i) sum[i] = sum[i - 1] + a[i];
    
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n * (k + 1); ++j) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= (k + 1) * n; ++j) {
            if (dp[i][j] == INF) continue;
            for (int ne = 0; ne <= k; ++ne) {
                upd(dp[i + 1][j + ne + (ne == k)], dp[i][j] + sum[ne]);
            }
        }
    }
    int ans = -1;
    for (int i = 0; i <= (k + 1) * n; ++i) {
        if (dp[n][i] <= M) ans = max(ans, i);
    }
    cout << ans << endl;
    return 0;
}