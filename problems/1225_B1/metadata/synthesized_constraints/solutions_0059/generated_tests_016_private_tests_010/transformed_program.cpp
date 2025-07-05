#include <bits/stdc++.h>
using namespace std;

int n, k, d;
const int MAXN = 2e5 + 7;
const int MAXK = 1e6 + 7;
int hist[MAXK], arr[MAXN];
int uniq = 0;

// Helper functions for invariant checks

void check_large_d_invariant(int n, int d) {
    if (d > n * 0.8) {  // Check if d is large compared to n
        cerr << "Warning: Performance bottleneck condition triggered - d is large relative to n!" << endl;
        abort();
    }
}

void check_high_variability_invariant(const unordered_set<int>& showSet, int d) {
    if (showSet.size() > d * 0.8) {  // Check if there are too many unique shows in the window
        cerr << "Warning: Performance bottleneck condition triggered - high variability of shows!" << endl;
        abort();
    }
}

void check_frequent_updates_invariant(int uniq) {
    if (uniq > 50) {  // Arbitrary threshold for frequent recalc of uniq
        cerr << "Warning: Performance bottleneck condition triggered - frequent updates to uniq!" << endl;
        abort();
    }
}

inline void add(int pos, int x) {
    if (x == 1 && hist[pos] == 0) uniq++;
    hist[pos] += x;
    if (x == -1 && hist[pos] == 0) uniq--;
}

inline void init() {
    fill(hist, hist + MAXK, 0);
    uniq = 0;
}

inline void solve() {
    init();
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_set<int> showSet(arr, arr + d);  // Track unique shows in the initial window
    
    // Perform initial checks
    check_large_d_invariant(n, d);
    check_high_variability_invariant(showSet, d);

    for (int i = 0; i < d; i++) {
        add(arr[i], 1);
    }
    int ans = uniq;

    for (int i = d; i < n; i++) {
        add(arr[i - d], -1);
        add(arr[i], 1);
        ans = min(ans, uniq);
        
        // Perform runtime check for frequent updates
        check_frequent_updates_invariant(uniq);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 0;
    cin >> t;
    while (cin >> n >> k >> d) solve();
}