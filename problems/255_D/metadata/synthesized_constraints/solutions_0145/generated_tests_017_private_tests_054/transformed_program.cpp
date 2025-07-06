#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LLINF = 1e18;
const int maxN = 1e5;
long long n, row, col, c;

// Checker functions
void check_large_grid_with_edge_start(long long n, long long row, long long col) {
    if (n > 1e8 && (row <= 10 || row >= n-10 || col <= 10 || col >= n-10)) {
        cerr << "Warning: Performance bottleneck condition triggered - large grid with edge start!" << endl;
        abort();
    }
}

void check_high_target_c(long long n, long long c) {
    if (c > 0.9 * n * n) {
        cerr << "Warning: Performance bottleneck condition triggered - high target c relative to grid size!" << endl;
        abort();
    }
}

long long sum(long long t) {
    long long max_l = col - 1, max_r = n - col;
    long long ans = 0;
    ans += 1 + min(t, max_l) + min(t, max_r);
    long long aux_t = t;
    for (int i = row - 1; i >= 1; i--) {
        aux_t--;
        if (aux_t < 0) break;
        ans += 1 + min(aux_t, max_l) + min(aux_t, max_r);
    }
    for (int i = row + 1; i <= n; i++) {
        t--;
        if (t < 0) break;
        ans += 1 + min(t, max_l) + min(t, max_r);
    }
    return ans;
}

int main() {
    scanf("%lld %lld", &n, &row);
    scanf("%lld %lld", &col, &c);

    // Insert performance checks here
    check_large_grid_with_edge_start(n, row, col);
    check_high_target_c(n, c);

    long long lo = 0, hi = 1e6;
    while (lo < hi) {
        long long mi = lo + (hi - lo) / 2;
        if (sum(mi) >= c)
            hi = mi;
        else
            lo = mi + 1;
    }
    printf("%lld\n", hi);
    return 0;
}