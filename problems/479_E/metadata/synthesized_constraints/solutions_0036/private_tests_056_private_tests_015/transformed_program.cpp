#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5, MOD = 1e9 + 7;
int n, a, b, m, ans;
int f[N], sum[N], g[N];

// Checkers for performance invariants
void check_large_difference_invariant(int a, int b, int threshold) {
    if (b - a > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to large difference between a and b!" << endl;
        abort();
    }
}

void check_high_trips_invariant(int k, int threshold) {
    if (k > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to high number of trips!" << endl;
        abort();
    }
}

void check_proximity_invariant(int a, int b, int n, int proximity_threshold) {
    if (abs(a - b) < proximity_threshold || abs(b - (n-a)) < proximity_threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to proximity to forbidden floor!" << endl;
        abort();
    }
}

int main() {
    scanf("%d%d%d%d", &n, &a, &b, &m);
    
    // Performance checks
    check_large_difference_invariant(a, b, 2500); // Threshold for large difference
    check_high_trips_invariant(m, 3000);          // Threshold for high number of trips
    check_proximity_invariant(a, b, n, 2);        // Threshold for proximity to forbidden floor

    f[a] = 1;
    if (a < b) {
        sum[0] = 0;
        for (register int i = 1; i < b; ++i) sum[i] = (sum[i - 1] + f[i]) % MOD;
        for (register int i = 1; i < b; ++i) g[i] = f[i];
        for (register int i = 1; i <= m; ++i) {
            for (register int j = 1; j < b; ++j)
                f[j] = ((sum[j + (b - j + 1) / 2 - 1] - sum[0] - g[j]) % MOD + MOD) % MOD;
            sum[0] = 0;
            for (register int j = 1; j < b; ++j) sum[j] = (sum[j - 1] + f[j]) % MOD;
            for (register int j = 1; j < b; ++j) g[j] = f[j];
        }
        for (register int i = 1; i < b; ++i) ans = (ans + f[i]) % MOD;
        printf("%d\n", ans);
    } else {
        sum[b] = 0;
        for (register int i = b + 1; i <= n; ++i)
            sum[i] = (sum[i - 1] + f[i]) % MOD;
        for (register int i = b + 1; i <= n; ++i) g[i] = f[i];
        for (register int i = 1; i <= m; ++i) {
            for (register int j = b + 1; j <= n; ++j)
                f[j] = ((sum[n] - sum[j - (j - b + 1) / 2] - g[j]) % MOD + MOD) % MOD;
            sum[b] = 0;
            for (register int j = b + 1; j <= n; ++j)
                sum[j] = (sum[j - 1] + f[j]) % MOD;
            for (register int j = b + 1; j <= n; ++j) g[j] = f[j];
        }
        for (register int i = b + 1; i <= n; ++i) ans = (ans + f[i]) % MOD;
        printf("%d\n", ans);
    }
    return 0;
}