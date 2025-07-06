#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000000")
using namespace std;

const double EPS = 1e-3;
const int INF = (int)(2e9 + 0.5);
const int MAXN = 410;

int n, k, a[MAXN], b[MAXN];
map<int, int> dp[MAXN];

// Checkers for performance bottlenecks
void check_recursive_depth(int currentDepth) {
    if (currentDepth > 100) { // Hypothetical threshold
        cerr << "Warning: Performance bottleneck condition triggered - high recursive depth!" << endl;
        abort();
    }
}

void check_memoization(int memoizedStates) {
    int maxStates = 20000; // Hypothetical threshold
    if (memoizedStates > maxStates) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive states in memoization!" << endl;
        abort();
    }
}

void check_branching_factor(int branchingFactor) {
    if (branchingFactor > 50) { // Hypothetical threshold
        cerr << "Warning: Performance bottleneck condition triggered - high branching factor!" << endl;
        abort();
    }
}

int dfs(int num, int balance, int depth = 0) {
    check_recursive_depth(depth);

    if (num < 0 && !balance) return 0;
    if (num < 0 && balance) return -INF;
    if (dp[num].count(balance)) return dp[num][balance];

    int& result = dp[num][balance];
    result = dfs(num - 1, balance, depth + 1);

    int branchingFactor = 0; // Variable to analyze branching factor
    result = max(result, dfs(num - 1, balance - (a[num] - b[num]), depth + 1) + a[num]);
    branchingFactor++;  // Increment whenever a branch is explored

    check_branching_factor(branchingFactor);
    check_memoization(dp[num].size()); // Check memoization after updating dp

    return result;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; scanf("%d", &a[i]), ++i);
    for (int i = 0; i < n; scanf("%d", &b[i]), b[i] *= k, ++i);

    int result = dfs(n - 1, 0);

    printf("%d\n", result <= 0 ? -1 : result);
    return 0;
}