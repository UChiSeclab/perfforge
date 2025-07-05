#include <bits/stdc++.h>
using namespace std;

// Checker for rebalancing overhead with mixed student counts
void check_rebalancing_invariant(int c1, int c2) {
    if (c1 > 0 && c2 > 0) {
        cerr << "Warning: Rebalancing invariant triggered - mixed compartments with 1 and 2 students need complex rearrangement" << endl;
        abort();
    }
}

// Checker for complexity from high `n` with specific patterns
void check_complexity_invariant(int n, int c1, int c2) {
    if (n > 100000 && (c1 > c2 || c2 > c1)) {
        cerr << "Warning: Complexity invariant triggered - high compartment count with uneven distribution of small groups" << endl;
        abort();
    }
}

// Checker for suboptimal use of `c[1]` and `c[2]` balancing
void check_suboptimal_balance_invariant(int c1, int c2) {
    if (c1 + c2 > 100000) {  // A threshold for too many small groups needing balancing
        cerr << "Warning: Suboptimal balance invariant triggered - too many compartments with 1 or 2 students" << endl;
        abort();
    }
}

int main(void) {
    int n;
    cin >> n;
    map<int, int> c;
    int ans = 0;
    for (int i = 0, v; i < n; ++i) {
        cin >> v;
        ++c[v];
    }

    // Insert checker calls after input processing
    check_rebalancing_invariant(c[1], c[2]);
    check_complexity_invariant(n, c[1], c[2]);
    check_suboptimal_balance_invariant(c[1], c[2]);

    int t;
    t = min(c[1], c[2]);
    c[1] -= t, c[2] -= t;
    c[3] += t;
    ans += t;
    if (c[2] == 0 && c[1] == 0) {
        cout << ans;
        return 0;
    }
    if (c[2] == 0) {
        t = c[1] / 3;
        c[3] += t;
        c[1] %= 3;
        ans += 2 * t;
        if (c[1] != 0) {
            t = min(c[1] / 2, c[4]);
            c[3] += t;
            c[4] -= t;
            c[1] -= t * 2;
            ans += t * 2;
            t = min(c[1], c[3]);
            c[4] += t;
            c[1] -= t;
            c[3] -= t;
            ans += t;
            t = min(c[4] / 2, c[1]);
            c[1] -= t;
            c[4] -= 2 * t;
            c[3] += t;
            ans += t * 2;
        }
    } else {
        t = c[2] / 3;
        c[3] += 2 * t;
        c[2] %= 3;
        ans += 2 * t;
        if (c[2] != 0) {
            t = c[2] / 2;
            c[4] += t;
            c[2] -= t * 2;
            ans += t * 2;
            t = min(c[2], c[4]);
            ans += t;
            c[4] -= t, c[2] -= t;
            c[3] += t;
            t = min(c[2], c[3] / 2);
            ans += 2 * t;
            c[4] += 2 * t;
            c[3] -= 2 * t;
            c[2] -= t;
        }
    }
    if (c[1] != 0 || c[2] != 0) {
        ans = -1;
    }
    cout << ans;
    return 0;
}