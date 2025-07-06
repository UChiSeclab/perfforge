#include <bits/stdc++.h>
using namespace std;

// Checker functions to identify potential performance bottlenecks
void check_large_m_invariant(int n, int m) {
    if (m > 9000 && n > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - large m with many shelves!" << endl;
        abort();
    }
}

void check_iteration_invariant(int n, int m, const vector<vector<int>>& shelves) {
    int totalItems = 0;
    for (const auto& shelf : shelves) {
        totalItems += shelf.size();
    }
    if (totalItems > 5000 && m > 8000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive iteration over combinations!" << endl;
        abort();
    }
}

void check_nested_loops_invariant(int n, const vector<vector<int>>& shelves) {
    for (const auto& shelf : shelves) {
        if (shelf.size() > 80) {
            cerr << "Warning: Performance bottleneck condition triggered - nested loops on large shelves!" << endl;
            abort();
        }
    }
}

int dp[2][10001];
signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    
    // Initialize shelves and run invariant checks
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a[i].assign(k, 0);
        for (int j = 0; j < k; j++) cin >> a[i][j];
    }

    // Run checks after input is read
    check_large_m_invariant(n, m);
    check_iteration_invariant(n, m, a);
    check_nested_loops_invariant(n, a);

    vector<vector<int>> val(n);
    for (int i = 0; i < n; i++) val[i].assign(a[i].size() + 1, 0);
    for (int i = 0; i < n; i++) {
        int loc = a[i].size();
        vector<int> pref(loc, 0);
        for (int j = 0; j < loc; j++) {
            pref[j] = a[i][j];
            if (j != 0) pref[j] += pref[j - 1];
        }
        for (int l = 0; l < loc; l++) val[i][l + 1] = max(val[i][l + 1], pref[l]);
        int sum = 0;
        for (int j = loc - 1; j >= 0; j--) {
            sum += a[i][j];
            val[i][loc - j] = max(val[i][loc - j], sum);
        }
        for (int len = 1; len <= loc; len++) {
            for (int l = 0; l + len - 1 < loc; l++) {
                int k = pref[l + len - 1] - (l != 0 ? pref[l - 1] : 0);
                val[i][loc - len] = max(val[i][loc - len], sum - k);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        swap(dp[0], dp[1]);
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= min((int)a[i].size(), j); k++)
                dp[1][j] = max(dp[1][j], dp[0][j - k] + val[i][k]);
        }
    }
    cout << dp[1][m];
}