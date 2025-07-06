#include <bits/stdc++.h>
using namespace std;
const long long P = 1000000007;
long long n, m;
long long f[2][5010], g[5010];

inline long long pm(long long x, long long y) {
    long long z = 1;
    while (y) {
        if (y & 1) z = z * x % P;
        x = x * x % P, y >>= 1;
    }
    return z;
}

// Check functions for performance bottlenecks
void check_nested_loop_invariant(long long n, long long m) {
    if (n > m && m > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - nested loop expansion!" << endl;
        abort();
    }
}

void check_power_computation_invariant(long long n, long long m) {
    if (n > m && n > 2000) {
        cerr << "Warning: Performance bottleneck condition triggered - expensive power computations!" << endl;
        abort();
    }
}

void check_iterative_computation_invariant(long long n, long long m) {
    if (n > m && m > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration overhead!" << endl;
        abort();
    }
}

int main() {
    scanf("%lld%lld", &n, &m);
    int i, j, d;

    // Insert checks after reading inputs
    check_nested_loop_invariant(n, m);
    check_power_computation_invariant(n, m);
    check_iterative_computation_invariant(n, m);

    if (n <= m) {
        for (i = 0; i <= n; i++) {
            d = i & 1;
            memset(f[d], 0, sizeof(f[d]));
            f[d][0] = 1;
            for (j = 1; j <= i; j++) f[d][j] = (f[d ^ 1][j - 1] + f[d ^ 1][j]) % P;
        }
        long long ans = 0;
        for (i = 1; i <= n; i++) ans = (ans + f[n & 1][i] * pm(i, m)) % P;
        printf("%lld", ans);
        return 0;
    }

    long long tmp = pm(2, n - m);
    for (i = 1; i <= m + 1; i++) g[i] = 1;
    for (i = m; i >= 0; i--) f[0][i] = tmp - 1, tmp = (tmp << 1) % P;
    for (i = 1; i <= m; i++) {
        d = i & 1;
        memset(f[d], 0, sizeof(f[d]));
        for (j = 0; j <= m - i; j++)
            f[d][j] = ((n - j) * (f[d ^ 1][j + 1] + g[j + 1]) % P + j * f[d ^ 1][j]) % P,
            g[j + 1] = g[j + 1] * (j + 1) % P;
    }
    printf("%lld", f[m & 1][0]);
    return 0;
}