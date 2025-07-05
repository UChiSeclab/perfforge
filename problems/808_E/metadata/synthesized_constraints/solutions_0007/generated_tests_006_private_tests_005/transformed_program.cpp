#include <bits/stdc++.h>
using namespace std;

void fast() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

void check_large_weight1_list(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to large weight 1 list!" << endl;
        abort();
    }
}

void check_frequent_dp_updates(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to frequent DP updates!" << endl;
        abort();
    }
}

void check_complex_combinations(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to complex input combinations!" << endl;
        abort();
    }
}

int n, m;
vector<long long> pre[4];
long long dp[30 * 100 * 100 + 5];
int cnt1[30 * 100 * 100 + 5], cnt2[30 * 100 * 100 + 5];

int main() {
    fast();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        pre[x].push_back(y);
    }

    // Check for large list of weight 1 souvenirs
    check_large_weight1_list(pre[1].size() > 1000); // Example threshold value

    for (int i = 0; i < 4; i++) {
        sort(pre[i].rbegin(), pre[i].rend());
    }

    if (pre[1].size()) {
        dp[1] = pre[1][0];
        cnt1[1] = 1;
    }

    for (int i = 2; i < 30 * 100 * 100 + 5; i++) {
        int idxa = cnt1[i - 1], idxb = cnt2[i - 2];
        if (idxa < pre[1].size()) {
            // Check for frequent updates in the DP table for weight 1
            check_frequent_dp_updates(i > 50000 && idxa > 500); // Example thresholds

            if (dp[i] < dp[i - 1] + pre[1][idxa]) {
                dp[i] = dp[i - 1] + pre[1][idxa];
                cnt1[i] = 1 + idxa;
                cnt2[i] = cnt2[i - 1];
            }
        }
        if (idxb < pre[2].size()) {
            if (dp[i] < dp[i - 2] + pre[2][idxb]) {
                dp[i] = dp[i - 2] + pre[2][idxb];
                cnt1[i] = cnt1[i - 2];
                cnt2[i] = 1 + idxb;
            }
        }
    }

    for (int i = 1; i < 30 * 100 * 100 + 5; i++) dp[i] = max(dp[i - 1], dp[i]);
    long long ans = dp[m], tot = 0, idxc = 0;
    while (m >= 0) {
        ans = max(ans, dp[m] + tot);
        m -= 3;
        if (idxc < pre[3].size()) tot += pre[3][idxc++];
    }

    // Check for complex combinations if weight and items interact extensively
    check_complex_combinations(n * m > 1000000); // Example threshold for complexity

    cout << ans << '\n';
    return 0;
}