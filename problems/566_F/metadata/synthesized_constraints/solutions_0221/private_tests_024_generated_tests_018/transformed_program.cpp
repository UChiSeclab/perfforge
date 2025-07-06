#include <bits/stdc++.h>
using namespace std;
const int N = 1e6, M = 320, K = 1001;
const int oo = 1e9 + 7;
int dp[N + 1], n, a[N + 1], ans;

// Function to check for minimum value invariant
void check_min_value_invariant(int minValue) {
    if (minValue == 1) {
        cerr << "Warning: Performance bottleneck triggered - smallest value is 1, causing high iteration count in nested loop." << endl;
        abort();
    }
}

// Function to check for multiplicative factors invariant
void check_multiplicative_factors_invariant(const vector<int>& a) {
    if (!a.empty() && a[0] == 1) {
        cerr << "Warning: Performance bottleneck triggered - presence of very small number in input leading to large multiplicative factors." << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // Apply checker functions based on the invariants
    check_min_value_invariant(a[1]);
    check_multiplicative_factors_invariant(a);

    for (int i = n; i >= 1; --i) {
        for (int j = 1; j * a[i] <= N; ++j)
            dp[a[i]] = max(dp[a[i]], dp[a[i] * j] + 1);
        ans = max(ans, dp[a[i]]);
    }
    cout << ans;
}