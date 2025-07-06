#include <bits/stdc++.h>
using namespace std;

long long a[(1 << 18) + 5], pos, n;
long long calc[30], dp[(1 << 18) + 5][20];

// Checkers for invariants
void check_recursion_invariant(int depth, int threshold) {
    if (depth > threshold) {
        cerr << "Warning: Recursion depth exceeds threshold, potential performance bottleneck!" << endl;
        abort();
    }
}

void check_memoization_invariant(long long dpValue) {
    if (dpValue == -1) {
        cerr << "Warning: Frequent cache misses in memoization detected, performance may degrade!" << endl;
        abort();
    }
}

void check_branching_invariant(int branchCount, int maxBranches) {
    if (branchCount > maxBranches) {
        cerr << "Warning: Excessive branching in recursive calls, potential performance degradation!" << endl;
        abort();
    }
}

void check_function_call_invariant(int callCount, int maxCalls) {
    if (callCount > maxCalls) {
        cerr << "Warning: Excessive function calls detected, possible performance bottleneck!" << endl;
        abort();
    }
}

// Declare a global call counter to monitor recursion
int callCounter = 0;

long long solve(int u, int bribe) {
    callCounter++;
    check_function_call_invariant(callCounter, 10000); // Example threshold for maximum recursive calls

    if (u == pos) return 0;
    if (bribe > 18) return 1e18;

    check_memoization_invariant(dp[u][bribe]); // Check for memoization inefficiencies

    if (dp[u][bribe] != -1) return dp[u][bribe];
    
    int len = n - u + 1;
    check_branching_invariant(calc[bribe], len); // Monitor excessive branching

    long long res = solve(u - 1, bribe + 1) + a[u];
    if (calc[bribe] >= len) res = min(res, solve(u - 1, bribe));
    
    return dp[u][bribe] = res;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == -1) pos = i;
    }
    for (int i = 1, aux = n / 2; i < 20; i++, aux /= 2)
        calc[i] = calc[i - 1] + aux;
    cout << solve(n, 0) << endl;
    return 0;
}