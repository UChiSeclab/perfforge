#include <bits/stdc++.h>
using namespace std;

int dp[100005];

void check_antenna_coverage(int n, int m, const vector<pair<int, int>>& a) {
    int uncovered_positions = 0;
    for (int pos = 1; pos <= m; ++pos) {
        bool covered = false;
        for (const auto& antenna : a) {
            if (pos >= antenna.first - antenna.second && pos <= antenna.first + antenna.second) {
                covered = true;
                break;
            }
        }
        if (!covered) ++uncovered_positions;
    }
    if (uncovered_positions > m / 2) {
        cerr << "Warning: Performance bottleneck condition triggered due to many uncovered positions!" << endl;
        abort();
    }
}

void check_coverage_adjustments(const vector<pair<int, int>>& a, int m) {
    int small_coverage_count = 0;
    for (const auto& antenna : a) {
        if (antenna.second < m / 10) {
            ++small_coverage_count;
        }
    }
    if (small_coverage_count > a.size() / 2) {
        cerr << "Warning: Performance bottleneck due to many antennas with small initial coverage!" << endl;
        abort();
    }
}

void check_dp_updates(int n, int m) {
    if (m > 10000 && n > 40) {
        cerr << "Warning: Performance bottleneck due to frequent DP updates for large m and n!" << endl;
        abort();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (auto &x : a) {
        cin >> x.first >> x.second;
    }
    
    // Check for potential performance bottlenecks
    check_antenna_coverage(n, m, a);
    check_coverage_adjustments(a, m);
    check_dp_updates(n, m);
    
    sort(a.begin(), a.end());
    memset(dp, 0x3f, sizeof(dp));
    dp[m + 1] = 0;
    for (int i = m; i >= 1; i--) {
        if (i == 1) {
            int v;
            v++;
        }
        for (int j = 0; j < n; j++) {
            if (a[j].first + a[j].second >= i) {
                int req = 0;
                if (a[j].first - a[j].second > i) {
                    req = a[j].first - a[j].second - i;
                }
                dp[i] = min(dp[i],
                            req + dp[min(m + 1, a[j].first + a[j].second + req + 1)]);
                if (a[j].first + a[j].second < m) {
                    req = max(req, m - (a[j].first + a[j].second));
                }
                dp[i] = min(dp[i], req);
            }
        }
    }
    cout << dp[1] << endl;
    return 0;
}