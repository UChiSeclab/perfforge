#include <bits/stdc++.h>
using namespace std;
const int MAX_A = 1000 * 1000 + 10;
int dp[MAX_A], t[MAX_A];

// Checkers for performance bottlenecks
void check_maxi_invariant(int maxi) {
    if (maxi > 900000) { // Broad threshold for potential performance degradation
        cerr << "Warning: Performance bottleneck due to large maxi value!" << endl;
        abort();
    }
}

void check_sparse_t_invariant(int zeroCount, int maxi) {
    if (zeroCount > maxi * 0.9) { // More than 90% zeroes may indicate inefficiency
        cerr << "Warning: Performance bottleneck due to sparse t array!" << endl;
        abort();
    }
}

void check_dp_update_invariant(int updateCount, int maxi) {
    if (updateCount > maxi * 0.8) { // Frequent updates may indicate inefficiency
        cerr << "Warning: Performance bottleneck due to excessive dp updates!" << endl;
        abort();
    }
}

int main() {
    int n, ans = 0, maxi = 0, zeroCount = 0, updateCount = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        t[a] = b;
        maxi = max(maxi, a);
    }

    // Insert the check for maxi value
    check_maxi_invariant(maxi);

    if (t[0] > 0) {
        dp[0] = 1;
        ans = 1;
    }
    for (int i = 1; i <= maxi; i++) {
        if (t[i] == 0) {
            dp[i] = dp[i - 1];
            zeroCount++; // count the number of zeros processed
        } else {
            int x = i - t[i] - 1;
            if (x >= 0) dp[i] = dp[x];
            dp[i]++;
            updateCount++; // count how many times dp[i] is updated
        }
        ans = max(ans, dp[i]);
    }

    // Insert check for sparse `t` array and excessive dp updates
    check_sparse_t_invariant(zeroCount, maxi);
    check_dp_update_invariant(updateCount, maxi);

    cout << n - ans << endl;
    return 0;
}