#include <bits/stdc++.h>
using namespace std;

int n, T;
int a[100005];
int b[100005];
int cnt[1000];
int dp[400];
int dp2[400];
int ans[400];

// Checker functions to identify performance bottlenecks
void check_redundant_array_operations(int n, int T) {
    if (T > 2 * n) {
        cerr << "Warning: Performance bottleneck condition triggered - Redundant array operations due to large T." << endl;
        abort();
    }
}

void check_inefficient_nested_loop(int n, int T, int sz2) {
    if (sz2 > n * n) {
        cerr << "Warning: Performance bottleneck condition triggered - Inefficient nested loop due to large sz2." << endl;
        abort();
    }
}

int main() {
    scanf("%d%d", &n, &T);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), b[i] = a[i], cnt[a[i]]++;

    // Checking for redundant array operations
    check_redundant_array_operations(n, T);

    int id = n;
    int sz = n * min(n, T);
    for (int i = n; i < sz; i++) a[id] = a[id - n], id++;
    
    int sz2 = n * min(n, max(0, T - n));
    
    // Checking for inefficient nested loop
    check_inefficient_nested_loop(n, T, sz2);

    id = n;
    for (int i = n; i < sz2; i++) b[id] = b[id - n], id++;
    
    int last = max(0, T - 2 * n);
    for (int i = 0; i < sz; i++) {
        int ma = 0;
        for (int j = 0; j <= a[i]; j++) ma = max(ma, dp[j]);
        dp[a[i]] = max(dp[a[i]], ma + 1);
    }
    for (int i = sz2 - 1; i >= 0; i--) {
        int ma = 0;
        for (int j = b[i]; j <= 300; j++) ma = max(ma, dp2[j]);
        dp2[b[i]] = max(dp2[b[i]], ma + 1);
    }
    int ma = 0;
    for (int i = 0; i <= 300; i++) {
        ma = max(ma, dp[i]);
        ans[i] = ma + cnt[i] * last;
    }
    ma = 0;
    int res = 0;
    for (int i = 300; i >= 0; i--) {
        ma = max(ma, dp2[i]);
        res = max(res, ans[i] + ma);
    }
    cout << res << endl;
    return 0;
}