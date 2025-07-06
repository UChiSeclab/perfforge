#include <bits/stdc++.h>
using namespace std;

int n, k, d;
int dp[105][110][2];

int rec(int idx, int sum, bool passed) {
    if (sum > n) return 0;
    if (sum == n) return passed;
    if (dp[idx][sum][passed] != -1) return dp[idx][sum][passed];
    long long answer = 0;
    for (int i = 1; i <= k; i++) {
        answer += rec(idx + 1, sum + i, i >= d || passed);
        if (answer > 1000000007) answer -= 1000000007;
    }
    dp[idx][sum][passed] = answer;
    return answer;
}

void check_deep_recursive_invariant(int n, int k, int d) {
    if (n > 50 && d <= k / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - deep recursive exploration!" << endl;
        abort();
    }
}

void check_branching_factor_invariant(int n, int k) {
    if (k > 50 && n > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - high branching factor!" << endl;
        abort();
    }
}

void check_memoization_invariant(int n, int k) {
    if (n * k > 5000) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient memoization!" << endl;
        abort();
    }
}

void check_path_length_threshold_invariant(int n, int d) {
    if (n > 90 && d < 10) {
        cerr << "Warning: Performance bottleneck condition triggered - path length threshold!" << endl;
        abort();
    }
}

int main() {
    memset(dp, 0xFF, sizeof(dp));
    scanf("%d%d%d", &n, &k, &d);

    // Insert checks here before the main computation
    check_deep_recursive_invariant(n, k, d);
    check_branching_factor_invariant(n, k);
    check_memoization_invariant(n, k);
    check_path_length_threshold_invariant(n, d);

    cout << rec(0, 0, false) << endl;
    return 0;
}