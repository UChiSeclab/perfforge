#include <bits/stdc++.h>
using namespace std;

// Invariant checkers
void check_backtracking_invariant(int d, int k, int l, int maxTideEffect) {
    if (d + maxTideEffect > l) {
        cerr << "Warning: Backtracking invariant triggered - depth exceeds safe level after tide" << endl;
        abort();
    }
}

void check_iteration_invariant(int k, int mx) {
    if (k > 90 && mx > 90) { // Example threshold; adjust based on logical constraints
        cerr << "Warning: Iteration invariant triggered - excessive loop iterations due to high k and mx" << endl;
        abort();
    }
}

void check_condition_check_invariant(int depth, int tideEffect, int l) {
    if (depth + tideEffect > l) {
        cerr << "Warning: Condition check invariant triggered - frequent depth checks exceeding safe level" << endl;
        abort();
    }
}

void solve() {
    int n, k, l;
    cin >> n >> k >> l;
    vector<int32_t> d(n + 1);
    int mx = 1;
    for (int i = 0; i < n + 1; ++i) {
        mx = max(d[i], mx);
        if (d[i] - k > l) {
            cout << "No" << endl;
            return;
        }
    }

    // Check invariant before entering the main loop
    check_iteration_invariant(k, mx);

    vector<int32_t> p(2 * k + 1);
    for (int i1 = 1; i1 <= k; ++i1) {
        p[i1] = p[i1 - 1] + 1;
    }
    for (int i1 = k + 1; i1 < 2 * k + 1; ++i1) {
        p[i1] = p[i1 - 1] - 1;
    }
    for (int m = 1; m <= n; ++m) {
        int a;
        cin >> a;
        d[m] = a;
        // Check for possible backtracking issue upon reading depth
        check_backtracking_invariant(a, k, l, k);
    }

    int x = 0;
    for (int t = 1; t < (2 * k) * mx * 10000; ++t) {
        int deep = d[x + 1] + p[t % (2 * k)];
        // Check for frequent condition checks leading to performance issues
        check_condition_check_invariant(d[x + 1], p[t % (2 * k)], l);

        if (deep <= l)
            x++;
        else
            while (d[x] + p[t % (2 * k)] > l && x > 0) x--;
        if (x == n) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t_;
    cin >> t_;
    while (t_--) solve();
    return 0;
}