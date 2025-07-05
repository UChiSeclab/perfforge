#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[5005];
int Favo[505];
int cost[11];
int dp[5005][505][11];

// Checker function for recursion and branching
void check_recursion_invariant(int maxDepth, int branchFactor) {
    if (maxDepth > 50 && branchFactor > 10) {
        cerr << "Warning: Recursion invariant triggered - high recursion depth or branching factor" << endl;
        abort();
    }
}

// Checker function for input size and repeated states
void check_input_size_invariant(int n, int k, int uniqueFavoCount) {
    if (n > 400 && uniqueFavoCount > n / 2) {
        cerr << "Warning: Input size invariant triggered - potentially large state space due to input size" << endl;
        abort();
    }
}

// Checker function for memoization table usage
void check_memoization_invariant(int dpSize, int threshold) {
    if (dpSize > threshold) {
        cerr << "Warning: Memoization invariant triggered - excessive state caching" << endl;
        abort();
    }
}

// Recursive function implementing the solution
int solve(int idx, int f, int rem, int depth, int branch) {
    check_recursion_invariant(depth, branch); // Checking recursion depth and branching

    if (idx == n * k || f == n) return cost[rem];
    int &ret = dp[idx][f][rem];
    if (~ret) return ret;
    if (rem < k && arr[idx] == Favo[f])
        ret = max(ret, solve(idx + 1, f, rem + 1, depth + 1, branch));
    ret = max(ret, solve(idx, f + 1, 0, depth + 1, branch + 1) + cost[rem]);
    ret = max(ret, solve(idx + 1, f, rem, depth + 1, branch));
    return ret;
}

int main() {
    scanf("%d %d", &n, &k);
    for (size_t i = 0; i < n * k; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + (n * k));
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &Favo[i]);
    }
    sort(Favo, Favo + n);

    // Check input size invariant
    int uniqueFavoCount = unique(Favo, Favo + n) - Favo;
    check_input_size_invariant(n, k, uniqueFavoCount);

    for (size_t i = 1; i <= k; i++) {
        scanf("%d", &cost[i]);
    }
    memset(dp, -1, sizeof dp);

    // Check memoization table usage invariant
    check_memoization_invariant(sizeof(dp) / sizeof(dp[0][0][0]), 5000);

    printf("%d", solve(0, 0, 0, 0, 0)); // Initial depth and branch are 0
    return 0;
}