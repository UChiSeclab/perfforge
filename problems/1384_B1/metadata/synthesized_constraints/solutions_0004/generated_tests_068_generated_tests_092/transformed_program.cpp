#include <bits/stdc++.h>
using namespace std;

int dp[100005][209], n, k, l, depth[609], timeLim, p[100005];

// Integrate depth constraint interaction checker
void check_depth_constraint_invariant(int l, int depth, int tideEffect) {
    if (depth + tideEffect > l - 1) {
        cerr << "Warning: Performance bottleneck condition triggered - depth constraint interaction" << endl;
        abort();
    }
}

// Integrate tide periodicity impact checker
void check_tide_periodicity_invariant(int k, int n) {
    if (2 * k < n) {
        cerr << "Warning: Performance bottleneck condition triggered - tide periodicity impact" << endl;
        abort();
    }
}

// Integrate state space complexity checker
void check_state_space_complexity_invariant(int timee, int pos, int timeLim) {
    if (timee > timeLim - 1000) { // Arbitrary threshold for complexity
        cerr << "Warning: Performance bottleneck condition triggered - state space complexity" << endl;
        abort();
    }
}

int func(int timee, int pos) {
    // Check state space complexity
    check_state_space_complexity_invariant(timee, pos, timeLim);

    if (pos == n + 1) {
        return 1;
    }
    if (timee == timeLim + 1) {
        return 0;
    }
    if (dp[timee][pos] != -1) {
        return dp[timee][pos];
    }
    int ans = 0;
    int newDep = depth[pos] + p[(timee + 1) % (2 * k)];
    
    // Check depth constraints
    check_depth_constraint_invariant(l, depth[pos], p[(timee + 1) % (2 * k)]);

    if (newDep <= l || pos == 0) ans = func(timee + 1, pos);
    if (pos + 1 == n + 1) {
        ans = max(ans, func(timee + 1, pos + 1));
    } else {
        int newDepth = depth[pos + 1] + p[(timee + 1) % (2 * k)];
        if (newDepth <= l) {
            ans = max(ans, func(timee + 1, pos + 1));
        }
    }
    return dp[timee][pos] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i, j, line;
    cin >> line;
    while (line--) {
        cin >> n >> k >> l;
        timeLim = 10000;

        // Check tide periodicity impact
        check_tide_periodicity_invariant(k, n);

        for (i = 1; i <= n; i++) {
            cin >> depth[i];
        }
        for (i = 0; i <= timeLim; i++) {
            for (j = 0; j <= n + 1; j++) {
                dp[i][j] = -1;
            }
        }
        p[0] = 0;
        int cur = 1;
        for (i = 1; i <= k; i++) {
            p[cur] = i;
            cur++;
        }
        for (i = k - 1; i > 0; i--) {
            p[cur] = i;
            cur++;
        }
        int ans = func(0, 0);
        if (ans == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}