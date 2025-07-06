#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2, M = 1e5;
int n, x[N], y[N], fac[N], vis[N], last[N];

// Checkers based on derived invariants
void check_divisor_count_invariant(int divisorCount) {
    if (divisorCount > 500) {
        cerr << "Warning: Performance bottleneck condition triggered - high number of divisors!" << endl;
        abort();
    }
}

void check_large_range_invariant(int mx) {
    if (mx > 95000) {
        cerr << "Warning: Performance bottleneck condition triggered - large range for validation!" << endl;
        abort();
    }
}

void check_frequent_revalidation_invariant(int y, int k) {
    if (y == k - 1) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent re-validation of divisors!" << endl;
        abort();
    }
}

void check_high_iteration_invariant(int pn) {
    if (pn > 100) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration over divisors!" << endl;
        abort();
    }
}

int main() {
    int n, mx = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
    check_large_range_invariant(mx);  // Check for large range validation before processing

    for (int k = 1; k <= n; k++) {
        int a = x[k], pn = 0;
        for (int i = 1; i * i <= a; i++) {
            if (a % i == 0) {
                fac[++pn] = i;
                if (i * i != a) fac[++pn] = a / i;
            }
        }
        // Check high divisor count
        check_divisor_count_invariant(pn);

        for (int i = 1; i <= pn; i++) vis[i] = 0;
        for (int i = 1; i <= pn; i++) {
            if (i == 1) {
                if (y[k]) vis[i] = 1;
                continue;
            }
            int b = fac[i];
            for (int j = b; j <= mx; j += b) {
                if (last[j] >= k - y[k]) {
                    vis[i] = 1;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= pn; i++) {
            if (!vis[i]) ans++;
            last[fac[i]] = k;
        }
        printf("%d\n", ans);
        last[a] = k, mx = max(mx, a);

        // Check frequently re-validating divisors
        check_frequent_revalidation_invariant(y[k], k);

        // Check high iteration over divisors
        check_high_iteration_invariant(pn);
    }
    return 0;
}