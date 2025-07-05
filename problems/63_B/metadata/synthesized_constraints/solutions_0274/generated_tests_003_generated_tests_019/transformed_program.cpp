#include <bits/stdc++.h>
using namespace std;
map<int, int> m;

// Checkers for performance bottlenecks
void check_rank_gap_invariant(int minRank, int maxRank) {
    if (maxRank - minRank > 50) {
        cerr << "Warning: Performance bottleneck condition triggered due to significant rank gap!" << endl;
        abort();
    }
}

void check_loop_execution_invariant(int currentMinRank, int maxRank) {
    if (maxRank - currentMinRank > 50) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive loop execution!" << endl;
        abort();
    }
}

void check_group_formation_invariant(int minRank, int maxRank) {
    if (maxRank - minRank > 50) {
        cerr << "Warning: Performance bottleneck condition triggered due to inefficient group formation!" << endl;
        abort();
    }
}

int main() {
    int a, t, n, i, j, k, l, mn = INT_MAX, mx = 0;
    cin >> n >> k;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        mn = min(mn, a);
        m[a]++;
    }
    
    // Insert checker after input and initial setup
    check_rank_gap_invariant(mn, k);

    int p = mn;
    while (p < k) {
        ans++;
        mn = INT_MAX;

        // Insert checker at the beginning of the loop
        check_loop_execution_invariant(p, k);

        for (int i = k - 1; i >= p; i--) {
            if (m[i] > 0) m[i]--, m[i + 1]++;
            if (m[i] > 0) mn = min(mn, i);
            if (m[i + 1] > 0) mn = min(mn, i + 1);
        }

        // Insert checker at the end of the loop
        check_group_formation_invariant(p, k);

        p = mn;
    }
    cout << ans << "\n";
}