#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance characterization
void check_sort_invariant(int n) {
    if (n > 50) {  // Threshold based on potential sorting overhead
        cerr << "Warning: sort_invariant triggered - sorting large number of items" << endl;
        abort();
    }
}

void check_dp_range_invariant(int r, int l) {
    if ((r - l) > 10) {  // Arbitrary threshold indicating a large range
        cerr << "Warning: dp_range_invariant triggered - large range of DP updates" << endl;
        abort();
    }
}

void check_accumulated_weight_invariant(int r, int m) {
    if (r > 0.9 * m) {  // Threshold indicating capacity nearing limit
        cerr << "Warning: accumulated_weight_invariant triggered - capacity nearing limit" << endl;
        abort();
    }
}

bool cmp(pair<int, long long> a, pair<int, long long> b) {
    return a.second / a.first > b.second / b.first;
}

int main() {
    int n, m, w, l, r;
    long long c, dp[300500], mx;
    cin >> n >> m;

    // Check for sorting overhead
    check_sort_invariant(n);

    vector<pair<int, long long>> t(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%I64d", &w, &c);
        t[i] = make_pair(w, c);
    }

    sort(t.begin(), t.end(), cmp);
    memset(dp, 0, sizeof(dp));
    r = 0;

    for (int i = 0; i < n; ++i) {
        r = min(r + t[i].first, m);
        l = max(t[i].first, r - 6);

        // Check for large DP update range
        check_dp_range_invariant(r, l);

        for (int j = r; j >= l; --j) {
            dp[j] = max(dp[j], dp[j - t[i].first] + t[i].second);
        }

        // Check for capacity nearing limit
        check_accumulated_weight_invariant(r, m);
    }

    mx = 0;
    for (int i = 0; i <= m; ++i) {
        mx = max(mx, dp[i]);
    }
    cout << mx << endl;
    return 0;
}