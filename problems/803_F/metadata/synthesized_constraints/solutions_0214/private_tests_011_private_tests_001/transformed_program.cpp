#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 9;
const int MOD = 1000000007;
int N, n = 1;
int w[maxn], mu[maxn], cnt[maxn], P[maxn];

// Checkers for performance-characterizing invariants
void check_divisors_invariant(int maxElement) {
    int divisorThreshold = 10000; // Threshold for high number of divisors
    if (maxElement > divisorThreshold) {
        cerr << "Warning: Performance bottleneck due to high number of divisors!" << endl;
        abort();
    }
}

void check_nested_loops_invariant(int n) {
    int nestedLoopThreshold = 50000; // Threshold for nested loop iterations
    if (n > nestedLoopThreshold) {
        cerr << "Warning: Performance bottleneck due to excessive nested loop iterations!" << endl;
        abort();
    }
}

void check_power_calculation_invariant(int maxElement) {
    int powerCalculationThreshold = 15000; // Threshold for large power calculations
    if (maxElement > powerCalculationThreshold) {
        cerr << "Warning: Performance bottleneck due to large power calculations!" << endl;
        abort();
    }
}

int main() {
    cin >> N;
    memset(cnt, 0, sizeof cnt);
    P[0] = 1;
    for (int i = 0; i < N; i++) {
        scanf("%d", w + i);
        n = max(n, w[i]);
        cnt[w[i]]++;
        P[i + 1] = 2 * P[i] % MOD;
    }

    // Invoke checkers after inputs are processed
    check_divisors_invariant(n);
    check_nested_loops_invariant(N);
    check_power_calculation_invariant(n);

    memset(mu, 0, sizeof mu);
    mu[1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            mu[j] -= mu[i];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int c = 0;
        for (int j = i; j <= n; j += i) {
            c += cnt[j];
        }
        ans = ((ans + mu[i] * (P[c] - 1) % MOD) % MOD + MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}