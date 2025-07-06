#include <bits/stdc++.h>
using namespace std;
const int offset = (int)10000;
const int N = 3e4;
map<int, int> dp[105];
int ara[105], a[105], b[105];
int n, k;
const int inf = 1 << 30;

// Checker functions for performance bottlenecks
void check_high_branching_invariant(int n) {
    if (n > 90) {
        cerr << "Warning: Performance bottleneck condition triggered - high branching factor with many fruits!" << endl;
        abort();
    }
}

void check_memoization_invariant(int uniqueStatesCount) {
    if (uniqueStatesCount > 5000) {
        cerr << "Warning: Performance bottleneck condition triggered - ineffective memoization due to unique states!" << endl;
        abort();
    }
}

void check_search_space_invariant(int negativeOutcomes) {
    if (negativeOutcomes > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive exploration of negative outcomes!" << endl;
        abort();
    }
}

void check_recursive_evaluations_invariant(int uniqueRatiosCount) {
    if (uniqueRatiosCount > 7000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursive evaluations!" << endl;
        abort();
    }
}

int solve(int pos, int bal) {
    static int uniqueStatesCount = 0;  // Track unique states for memoization check
    static int negativeOutcomes = 0;   // Track negative outcomes for search space check
    static int uniqueRatiosCount = 0;  // Track unique ratios for recursive evaluations check

    if (pos > n) {
        if (bal == 0) {
            return 0;
        } else {
            negativeOutcomes++;
            check_search_space_invariant(negativeOutcomes);
            return -inf;
        }
    }
    if (dp[pos].find(bal) != dp[pos].end()) {
        return dp[pos][bal];
    }

    uniqueStatesCount++;
    check_memoization_invariant(uniqueStatesCount);

    int ret = -inf;
    ret = max(ret, solve(pos + 1, bal));
    uniqueRatiosCount++;
    ret = max(ret, a[pos] + solve(pos + 1, bal + a[pos] - (k * b[pos])));
    
    check_recursive_evaluations_invariant(uniqueRatiosCount);

    return dp[pos][bal] = ret;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    
    check_high_branching_invariant(n);  // Check for high branching condition

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int ans = solve(1, 0);
    if (ans <= 0) {
        cout << -1 << "\n";
        return 0;
    }
    cout << ans << "\n";
    return 0;
}