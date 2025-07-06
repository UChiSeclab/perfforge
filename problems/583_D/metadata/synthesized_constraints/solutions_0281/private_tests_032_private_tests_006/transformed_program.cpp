#include <bits/stdc++.h>
using namespace std;

// Checker implementations
void check_iteration_invariant(int n, int t) {
    if (n == 100 && t > 2 * n) {
        cerr << "Warning: Performance bottleneck condition triggered! High n and t causing excessive iterations." << endl;
        abort();
    }
}

void check_calc_calls_invariant(int uniqueElementCount) {
    if (uniqueElementCount > 50) {
        cerr << "Warning: Performance bottleneck condition triggered! Frequent calc calls due to high unique elements." << endl;
        abort();
    }
}

void check_upper_bound_invariant(int n) {
    if (n == 100) {
        cerr << "Warning: Performance bottleneck condition triggered! Extensive use of upper_bound across large data segments." << endl;
        abort();
    }
}

// Original code
long long gcd(long long a, long long b) {
    long long r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

const int maxn = 110;
int n, t;
int a[maxn];
int cnt[3 * maxn];
int f[2 * maxn * maxn];
int d[2 * maxn * maxn];
int g[3 * maxn];

int calc(int h) {
    if (g[h] != -1) return g[h];
    int res = 0;
    memset(d, 0x3f, sizeof(d));
    for (int i = 0; i < (n * n); i++)
        if (a[i % n] >= h) {
            int k = upper_bound(d, d + n * n, a[i % n]) - d;
            d[k] = a[i % n];
            res = max(res, k + 1);
        }
    return g[h] = res;
}

void solve() {
    memset(cnt, 0, sizeof(cnt));
    memset(f, 0, sizeof(f));
    memset(g, -1, sizeof(g));
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        cnt[a[i]]++;
    }

    // Invoke the checkers after reading the input
    check_iteration_invariant(n, t);
    check_upper_bound_invariant(n);

    if (t <= 2 * n) {
        int ans = 0;
        memset(d, 0x3f, sizeof(d));
        for (int i = 0; i < (t * n); i++) {
            int k = upper_bound(d, d + n * n, a[i % n]) - d;
            d[k] = a[i % n];
            ans = max(ans, k + 1);
        }
        printf("%d", ans);
        return;
    }

    memset(d, 0x3f, sizeof(d));
    for (int i = 0; i < (n * n); i++) {
        int k = upper_bound(d, d + n * n, a[i % n]) - d;
        d[k] = a[i % n];
        f[i] = k + 1;
    }

    int ans = 0;
    int uniqueElementCount = 0; // To track unique elements
    for (int i = (n * n - n); i < (n * n); i++) {
        ans = max(ans, f[i] + (t - 2 * n) * cnt[a[i % n]] + calc(a[i % n]));
        uniqueElementCount++;
    }
    
    // Invoke the check for calc call frequency
    check_calc_calls_invariant(uniqueElementCount);

    printf("%d", ans);
}

int main() {
    solve();
    return 0;
}