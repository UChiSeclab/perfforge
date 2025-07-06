#include <bits/stdc++.h>
using namespace std;

int n, m;
int pos[100];
int range[100];
bool filled[100005];
int memo[100005];

// Checker functions
void check_recursive_coverage_invariant(int uncoveredSegments) {
    if (uncoveredSegments > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large uncovered segments!" << endl;
        abort();
    }
}

void check_memoization_invariant(int unfilledCount) {
    if (unfilledCount > 5000) {
        cerr << "Warning: Performance bottleneck condition triggered due to inefficient memoization usage!" << endl;
        abort();
    }
}

void check_initial_placement_invariant(int initialCoverageLength) {
    if (initialCoverageLength < m / 10) {
        cerr << "Warning: Performance bottleneck condition triggered due to non-optimal initial placement!" << endl;
        abort();
    }
}

int dp(int i) {
    if (i > m) return 0;
    if (memo[i] != -1) return memo[i];
    if (filled[i]) return memo[i] = dp(i + 1);

    int ans = m - i + 1;
    int diff;

    for (int x = 0; x < n; x++) {
        if (i < pos[x] - range[x]) {
            diff = pos[x] - range[x] - i;
            ans = min(ans, diff + dp(pos[x] + range[x] + diff + 1));
        }
    }
    return memo[i] = ans;
}

int main() {
    scanf("%d%d", &n, &m);
    int initialCoverage = 0;

    for (int x = 0; x < n; x++) {
        scanf("%d%d", &pos[x], &range[x]);
        for (int y = max(1, pos[x] - range[x]); y <= min(m, pos[x] + range[x]); y++) {
            filled[y] = true;
        }
        initialCoverage += min(m, pos[x] + range[x]) - max(1, pos[x] - range[x]) + 1;
    }

    // Perform initial placement check
    check_initial_placement_invariant(initialCoverage);

    // Count initially uncovered segments
    int uncoveredSegments = 0;
    int unfilledCount = 0;

    for (int i = 1; i <= m; i++) {
        if (!filled[i]) {
            unfilledCount++;
            if (i == 1 || filled[i - 1]) {
                uncoveredSegments++;
            }
        }
    }

    // Perform memoization invariant check
    check_memoization_invariant(unfilledCount);
    // Perform recursive coverage invariant check
    check_recursive_coverage_invariant(uncoveredSegments);

    memset(memo, -1, sizeof(memo));
    printf("%d\n", dp(1));
}