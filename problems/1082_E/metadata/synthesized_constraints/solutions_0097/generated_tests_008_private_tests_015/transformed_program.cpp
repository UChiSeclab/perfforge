#include <bits/stdc++.h>
using namespace std;

vector<int> g[500005];

void check_unique_elements_condition(int unique_values_count, int threshold) {
    if (unique_values_count > threshold) {
        cerr << "Warning: Performance bottleneck - too many unique elements causing excessive iterations!" << endl;
        abort();
    }
}

void check_target_elements_condition(int target_count, int n, double threshold_ratio) {
    if (target_count < n * threshold_ratio) {
        cerr << "Warning: Performance bottleneck - insufficient target elements leading to additional processing!" << endl;
        abort();
    }
}

void check_dominant_non_c_elements(int dominant_count, int n, double threshold_ratio) {
    if (dominant_count > n * threshold_ratio) {
        cerr << "Warning: Performance bottleneck - dominant non-target elements causing recalculations!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;
    
    vector<int> a(n + 1), pre(n + 1, 0);
    unordered_map<int, int> value_count;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g[a[i]].push_back(i);
        pre[i] = pre[i - 1] + (a[i] == c);
        value_count[a[i]]++;
    }
    
    // Check for invariant 1: too many unique elements
    check_unique_elements_condition(value_count.size(), 1e5); // Threshold is a broad estimate

    // Check for invariant 2: insufficient target elements
    check_target_elements_condition(pre[n], n, 0.1); // Threshold ratio is a broad estimate

    // Check for invariant 3: dominant non-target elements
    int dominant_value_count = 0;
    for (const auto& entry : value_count) {
        if (entry.first != c) {
            dominant_value_count = max(dominant_value_count, entry.second);
        }
    }
    check_dominant_non_c_elements(dominant_value_count, n, 0.5); // Threshold ratio is a broad estimate

    if (pre[n] == n) {
        cout << n << endl;
        return 0;
    }
    
    int ans = 0;
    for (int i = 1; i < 500005; i++) {
        int cans = 1, mi = INT_MAX;
        for (int j = 0; j < g[i].size(); j++) {
            if (j) {
                cans = max(cans, j + 1 - pre[g[i][j]] - mi);
            }
            mi = min(mi, j - pre[g[i][j] - 1]);
        }
        ans = max(ans, cans);
    }
    cout << ans + pre[n] << endl;
    return 0;
}