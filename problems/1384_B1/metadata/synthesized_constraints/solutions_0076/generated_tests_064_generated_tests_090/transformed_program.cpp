#include <bits/stdc++.h>
using namespace std;

// Define the checker functions
void check_dfs_depth_invariant(int recursionDepth) {
    if (recursionDepth > 1000) {
        cerr << "Warning: dfs_depth_invariant triggered - excessive recursion depth" << endl;
        abort();
    }
}

void check_depth_threshold_invariant(int depth, int tideEffect, int l) {
    if (depth + tideEffect > l - 10) {
        cerr << "Warning: depth_threshold_invariant triggered - depth close to limit" << endl;
        abort();
    }
}

void check_tide_state_invariant(int k, int maxDepthDiff) {
    if (k > maxDepthDiff + 10) {
        cerr << "Warning: tide_state_invariant triggered - excessive tide state range" << endl;
        abort();
    }
}

long long int mod = 1000000007;
void solve() {
    long long int n, k, l;
    cin >> n >> k >> l;
    vector<long long int> d(n + 1);
    for (long long int i = 0; i < n; i++) cin >> d[i];
    d[n] = -INT_MAX;
    vector<long long int> p(2 * k);
    for (long long int i = 0; i < 2 * k; i++) {
        if (i <= k)
            p[i] = i;
        else
            p[i] = 2 * k - i;
    }
    map<pair<long long int, long long int>, bool> visited;
    bool ok = false;
    function<void(long long int, long long int)> dfs = [&](long long int i,
                                                           long long int state) {
        check_dfs_depth_invariant(state);  // Check recursion depth

        if (i == n) {
            ok = true;
            return;
        }
        long long int t = state;
        while ((d[i] + p[state % (2 * k)] <= l) && ((state - t) <= 2 * k)) {
            check_depth_threshold_invariant(d[i], p[state % (2 * k)], l);  // Check depth threshold

            if (!visited[{i, state}]) {
                dfs(i + 1, state + 1);
                visited[{i, state}] = true;
            }
            state++;
        }
    };

    // Compute max depth difference for tide state invariant check
    int maxDepthDiff = *max_element(d.begin(), d.end()) - *min_element(d.begin(), d.end());
    check_tide_state_invariant(k, maxDepthDiff);  // Check tide state range

    for (long long int j = 0; j < 2 * k; j++) {
        if (d[0] + p[j] <= l) {
            dfs(1, j + 1);
        }
    }
    if (ok)
        cout << "Yes";
    else
        cout << "No";
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long int T;
    cin >> T;
    while (T--) {
        solve();
    }
}