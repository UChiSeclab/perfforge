#include <bits/stdc++.h>
const int MAXN = 11000;
long long f[MAXN], g[MAXN];

void check_large_c_and_n(int n, int c) {
    if (n > 8000 && c > 4000) {
        cerr << "Warning: Performance bottleneck due to large c and n values!" << endl;
        abort();
    }
}

void check_exhaustive_combinations(int b, int c, int n) {
    if (b > 4000 && c > 4000 && n > 8000) {
        cerr << "Warning: Performance bottleneck due to exhaustive combinations of b and c!" << endl;
        abort();
    }
}

void check_large_state_space(int b, int c) {
    if (b + c > 8000) {
        cerr << "Warning: Performance bottleneck due to extensive state space in DP!" << endl;
        abort();
    }
}

int main() {
    int n, a, b, c;
    scanf("%d%d%d%d", &n, &a, &b, &c);

    // Check performance-characterizing invariants after input
    check_large_c_and_n(n, c);
    check_exhaustive_combinations(b, c, n);
    check_large_state_space(b, c);

    memset(f, 0, sizeof(f));
    for (int i = 0; i <= b && i <= n; i++) {
        f[i] = 1;
    }
    memset(g, 0, sizeof(g));
    for (int i = 0; i <= b && i <= n; i++) {
        for (int j = 0; j <= c && i + j * 2 <= n; j++) {
            g[i + j * 2] += f[i];
        }
    }
    long long res = 0LL;
    for (int i = 0; i <= n; i++) {
        if ((n - i) * 2 <= a) {
            res += g[i];
        }
    }
    printf("%lld\n", res);
    return 0;
}