#include <bits/stdc++.h>
using namespace std;

int N;
long long C[1001][1001];
long long dp[1001];
long long color[1001];

// Checker functions
void check_recursive_overhead_invariant(int sum, int totalBalls) {
    if (sum > totalBalls * 0.9) {
        cerr << "Warning: Performance bottleneck condition triggered - High recursive overhead!" << endl;
        abort();
    }
}

void check_cache_ineffectiveness_invariant(int n, int p) {
    if (n > 900 || p > 900) {
        cerr << "Warning: Performance bottleneck condition triggered - Cache ineffectiveness!" << endl;
        abort();
    }
}

void check_high_branching_invariant(int k, int maxBallCount) {
    if (k > 900 && maxBallCount > 900) {
        cerr << "Warning: Performance bottleneck condition triggered - High branching in recursion!" << endl;
        abort();
    }
}

long long combination(int n, int p) {
    // Check for cache ineffectiveness before calculating
    check_cache_ineffectiveness_invariant(n, p);

    if (n == p || p == 0) {
        return C[n][p] = 1;
    }
    if (C[n][p] != -1) {
        return C[n][p];
    } else {
        long long ans = combination(n - 1, p) % 1000000007L;
        ans = ans + (combination(n - 1, p - 1) % 1000000007L);
        return C[n][p] = ans % 1000000007L;
    }
}

long long solve(int k) {
    if (k == 1) {
        return 1;
    } else if (dp[k] != -1) {
        return dp[k];
    } else {
        long long sum = 0;
        int maxBallCount = 0;
        for (int i = 1; i <= k; i++) {
            sum += color[i];
            maxBallCount = max(maxBallCount, static_cast<int>(color[i]));
        }
        
        // Check for recursive overhead
        check_recursive_overhead_invariant(sum, 1000); // Total balls constraint

        sum--;
        long long ans = combination(sum, color[k] - 1);
        ans *= solve(k - 1);
        ans %= 1000000007L;

        // Check for high branching
        check_high_branching_invariant(k, maxBallCount);

        return dp[k] = ans;
    }
}

int main() {
    scanf("%d\n", &N);

    for (int i = 1; i <= N; i++) {
        cin >> color[i];
    }

    memset(dp, -1, sizeof dp);
    memset(C, -1, sizeof C);

    long long ans = solve(N);
    cout << ans << endl;

    return 0;
}