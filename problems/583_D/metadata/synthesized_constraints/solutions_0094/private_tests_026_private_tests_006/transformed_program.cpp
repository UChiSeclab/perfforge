#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long n, m, i, j, k, l, r, a[1001], dp1[100001], dp2[100001], d[100001];
long long t[301];

// Checker functions for performance invariants
void check_large_T_vs_n(long long n, long long T) {
    if (T >= 2 * n) {
        cerr << "Warning: Performance bottleneck condition triggered - T is significantly larger than n!" << endl;
        abort();
    }
}

void check_large_n(long long n) {
    if (n == 100) {
        cerr << "Warning: Performance bottleneck condition triggered - large n with nested loops!" << endl;
        abort();
    }
}

void check_large_sequence_computation(long long n, long long T) {
    if (n * T > 10000) { // This threshold is chosen based on complexity considerations
        cerr << "Warning: Performance bottleneck condition triggered - large sequence computation!" << endl;
        abort();
    }
}

void solve() {
    vector<long long> dp;
    dp.push_back(0);
    for (int i = 0; i < n * m; i++) {
        long long l = 0, r = dp.size() - 1;
        while (l < r) {
            long long w = (l + r) / 2 + (l + r) % 2;
            if (dp[w] <= a[i % n])
                l = w;
            else
                r = w - 1;
        }
        if (l == dp.size() - 1)
            dp.push_back(a[i % n]);
        else
            dp[l + 1] = min(dp[l + 1], a[i % n]);
    }
    cout << dp.size() - 1 << "\n";
    exit(0);
}

void build(long long h, long long l, long long r) {
    if (l == r) {
        d[h] = l;
        return;
    }
    long long w = (l + r) / 2;
    build(h * 2, l, w);
    build(h * 2 + 1, w + 1, r);
    if (t[d[h * 2]] < t[d[h * 2 + 1]])
        d[h] = d[h * 2 + 1];
    else
        d[h] = d[h * 2];
}

long long get(long long h, long long l, long long r, long long x, long long y) {
    if (x > y) return 0;
    if (l == x && y == r) return d[h];
    long long w = (l + r) / 2;
    long long o1 = get(h * 2, l, w, x, min(y, w)),
              o2 = get(h * 2 + 1, w + 1, r, max(x, w + 1), y);
    if (t[o1] > t[o2])
        return o1;
    else
        return o2;
}

int main() {
    long long ans = 0;
    cin >> n >> m;

    // Insert performance checks after reading input
    check_large_T_vs_n(n, m);
    check_large_n(n);
    check_large_sequence_computation(n, m); 

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t[a[i]]++;
        ans = max(ans, t[a[i]] * m);
    }
    if (m < n * 2) solve();
    build(1, 1, 300);
    if (m == 1) solve();
    vector<long long> v1, v2;
    v1.push_back(0);
    v2.push_back(0);
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++) v1.push_back(a[i]);
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++) v2.push_back(a[i]);
    m -= n * 2;
    m = max(m, 0ll);
    for (int i = 1; i <= n * n; i++) {
        dp1[i] = 1;
        for (int j = i - 1; j > 0; j--)
            if (v1[j] <= v1[i]) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
    }
    for (int i = n * n; i > 0; i--) {
        dp2[i] = 1;
        for (int j = i + 1; j <= n * n; j++)
            if (v2[j] >= v2[i]) dp2[i] = max(dp2[i], dp2[j] + 1);
    }
    for (int i = n * (n - 1); i <= n * n; i++)
        for (int j = 1; j <= n; j++)
            if (v1[i] <= v2[j]) {
                long long p = 0;
                for (int u = v1[i]; u <= v2[j]; u++)
                    if (t[p] < t[u]) p = u;
                ans = max(dp1[i] + dp2[j] + t[p] * m, ans);
            }
    cout << ans;
}