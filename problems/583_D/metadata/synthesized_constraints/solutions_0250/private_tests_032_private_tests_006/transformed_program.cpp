#include <bits/stdc++.h>
using namespace std;

const int MAXN = 201;
const int MAXQ = 305;

int a[2 * MAXN * MAXN];
int dp[2 * MAXN * MAXN];
int cnt_ma[MAXQ], cnt_ma_rev[MAXQ];
int cnt[MAXQ];

void solve(int *a, int len, int *cnt_ma) {
    for (int i = 0; i < MAXQ; i++) cnt_ma[i] = 0;
    for (int i = 0; i < len; i++) {
        dp[i] = 0;
        for (int j = 0; j <= a[i]; j++) {
            dp[i] = max(dp[i], cnt_ma[j]);
        }
        dp[i]++;
        cnt_ma[a[i]] = dp[i];
    }
}

void solve_rev(int *a, int len, int *cnt_ma) {
    for (int i = 0; i < MAXQ; i++) cnt_ma[i] = 0;
    for (int i = 0; i < len; i++) {
        dp[i] = 0;
        for (int j = a[i]; j < MAXQ; j++) {
            dp[i] = max(dp[i], cnt_ma[j]);
        }
        dp[i]++;
        cnt_ma[a[i]] = dp[i];
    }
}

// Checker functions
void check_large_t_and_values_invariant(int t, int n, const int* a, int len);
void check_back_and_forth_processing_invariant(int t, int n);
void check_large_array_invariant(int n, int t);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, t;
    cin >> n >> t;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 1; j < 2 * n; j++) a[i + n * j] = a[i];
        cnt[a[i]]++;
    }

    // Insert invariant checks after reading inputs
    check_large_t_and_values_invariant(t, n, a, n);
    check_back_and_forth_processing_invariant(t, n);
    check_large_array_invariant(n, t);

    if (t < 2 * n) {
        solve(a, t * n, cnt_ma);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, cnt_ma[a[i]]);
        }
        cout << ans << endl;
        return 0;
    }
    
    solve(a, n * n, cnt_ma);
    reverse(a, a + n * n);
    solve_rev(a, n * n, cnt_ma_rev);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, cnt_ma[a[i]] + cnt_ma_rev[a[i]] + (t - 2 * n) * cnt[a[i]]);
    }
    
    cout << ans << endl;
    return 0;
}