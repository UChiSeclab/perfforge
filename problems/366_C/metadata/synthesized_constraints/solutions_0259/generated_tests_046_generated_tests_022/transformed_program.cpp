#include <bits/stdc++.h>
using namespace std;
const int N = 105, M = 1e5 + 5;
int n, k, taste[N], cal[N];
map<pair<int, int>, int> dp;

// Checker functions
void check_recursion_invariant(int currentDepth, int maxDepth, int branchingFactor, int maxBranchingFactor) {
    if (currentDepth > maxDepth || branchingFactor > maxBranchingFactor) {
        cerr << "Warning: Recursion invariant triggered - excessive recursion depth or branching factor" << endl;
        abort();
    }
}

void check_memoization_invariant(int uniqueStates, int threshold) {
    if (uniqueStates > threshold) {
        cerr << "Warning: Memoization invariant triggered - too many unique states in DP" << endl;
        abort();
    }
}

void check_combination_invariant(int n, int threshold) {
    if (n >= threshold) {
        cerr << "Warning: Combination invariant triggered - large number of fruits leading to complex combinations" << endl;
        abort();
    }
}

void check_caloric_variability_invariant(int k, int tasteVariance, int calorieVariance, int threshold) {
    if (tasteVariance > threshold && calorieVariance > threshold) {
        cerr << "Warning: Caloric variability invariant triggered - complex taste/calorie combinations" << endl;
        abort();
    }
}

int solve(int i, int ratio, int currentDepth) {
    // Recursion invariant check
    check_recursion_invariant(currentDepth, 50, n, 10); // Example thresholds for depth and branching

    if (i == n) {
        if (!ratio) return 0;
        return -1e9;
    }
    if (dp.find({i, ratio}) != dp.end()) return dp[{i, ratio}];
    int ch1 = solve(i + 1, ratio, currentDepth + 1);
    int ch2 = solve(i + 1, ratio + k * cal[i] - taste[i], currentDepth + 1) + taste[i];
    return dp[{i, ratio}] = max(ch1, ch2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;

    // Combination invariant check
    check_combination_invariant(n, 90); // Example threshold for n

    for (int i = 0; i < n; i++) cin >> taste[i];
    for (int i = 0; i < n; i++) cin >> cal[i];

    // Caloric variability invariant check
    // Example calculation for variance, here simply taking the range as a proxy for variance
    int tasteVariance = *max_element(taste, taste + n) - *min_element(taste, taste + n);
    int calorieVariance = *max_element(cal, cal + n) - *min_element(cal, cal + n);
    check_caloric_variability_invariant(k, tasteVariance, calorieVariance, 50); // Example threshold

    int ans = solve(0, 0, 0);

    // Memoization invariant check after processing
    check_memoization_invariant(dp.size(), 10000); // Example threshold for unique states

    if (ans <= 0) ans = -1;
    cout << ans << "\n";
    
    return 0;
}