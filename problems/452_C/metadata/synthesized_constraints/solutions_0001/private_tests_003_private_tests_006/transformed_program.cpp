#include <bits/stdc++.h>
#pragma warning(disable : 4786)
#pragma warning(disable : 4996)
using namespace std;
double dp[1003][1003];
int vis[1003][1003];
int m;

// Check for high recursion depth with large state space
void check_high_recursion_invariant(int n, int m) {
    if (n * m > 900000) { // Example threshold suited for the problem constraints
        cerr << "Warning: High recursion depth with large state space triggered!" << endl;
        abort();
    }
}

// Check for inadequate memoization efficiency
void check_memoization_invariant(int n, int m) {
    if (n > 950 || m > 950) { // Threshold based on possible state coverage
        cerr << "Warning: Memoization efficiency bottleneck triggered - high n or m!" << endl;
        abort();
    }
}

// Check for recursive branching with large inputs
void check_recursive_branching_invariant(int n, int m) {
    if ((n > 950) && (m > 950)) { // High combined input threshold
        cerr << "Warning: Recursive branching with large inputs triggered!" << endl;
        abort();
    }
}

double DP(int total, int n, int k) {
    if (n == 0) return k;
    double &ret = dp[n][k];
    if (vis[n][k]) return ret;
    vis[n][k] = 1;
    ret = 0;
    if (k < m) ret += (1. * m - k) / total * DP(total - 1, n - 1, k + 1);
    if (total > m - k)
        ret += (1. * total - (m - k)) / total * DP(total - 1, n - 1, k);
    return ret;
}

int main() {
    int n;
    scanf("%d %d", &n, &m);

    // Insert checks after reading input
    check_high_recursion_invariant(n, m);
    check_memoization_invariant(n, m);
    check_recursive_branching_invariant(n, m);

    if (n == 1) {
        printf("%.10lf\n", 1.0);
        return 0;
    }
    double ans = (DP(n * m - 1, n - 1, 1)) / n;
    printf("%.10lf\n", ans);
    return 0;
}