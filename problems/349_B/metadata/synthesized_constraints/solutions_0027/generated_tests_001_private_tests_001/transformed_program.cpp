#include <bits/stdc++.h>
using namespace std;

// Checker for recursion depth and branching factor
void check_recursion_invariant(int branchCount) {
    if (branchCount > 8) { // High branching factor assumption
        cerr << "Warning: Performance bottleneck condition triggered - high branching factor in recursion!" << endl;
        abort();
    }
}

// Checker for insufficient memoization
void check_memoization_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - insufficient memoization!" << endl;
        abort();
    }
}

// Checker for large remaining paint budget with close costs
void check_paint_budget_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large remaining paint budget with close costs!" << endl;
        abort();
    }
}

int i, j, k, t, n, m, a[15];
int dp[1000005], w[1000005];

int f(int x) {
    int ans = -1, t = 0;
    if (x == 0) return 0;
    if (dp[x]) return dp[x];

    int branchCount = 0; // To track the number of branching options in recursion

    for (int i = 9; i >= 1; i--) {
        if (x - a[i] < 0) continue;
        branchCount++;
        t = f(x - a[i]);
        if (t > ans) {
            ans = t;
            w[x] = i;
        }
    }

    check_recursion_invariant(branchCount); // Check high branching factor

    return dp[x] = ans + 1;
}

int main() {
    scanf("%d", &k);
    for (i = 1; i <= 9; i++) scanf("%d", &a[i]);

    // Before starting recursion, check if memoization is sufficiently initialized
    check_memoization_invariant(dp[k] == 0 && k > 0);

    // Check if there's a potential performance bottleneck due to close costs
    int minCost = *min_element(a + 1, a + 10);
    int maxCost = *max_element(a + 1, a + 10);
    check_paint_budget_invariant(k > 100 && (maxCost - minCost < 10));

    if (!f(k))
        cout << -1;
    else
        while (w[k] > 0) {
            cout << w[k];
            k -= a[w[k]];
        }
    return 0;
}