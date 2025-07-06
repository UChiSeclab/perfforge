#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const long long mod = 1e9 + 7;
long long inv[maxn * 2], fac[maxn * 2], n, h, w, dp[maxn];

long long fpm(long long a, long long p) {
    long long res = 1;
    while (p) {
        if (p & 1) res = res * a % mod;
        a = a * a % mod;
        p /= 2;
    }
    return res;
}

struct node {
    long long x, y;
};

bool cmp(node a1, node b1) {
    if (a1.x == b1.x) {
        return a1.y < b1.y;
    } else
        return a1.x < b1.x;
}

node a[maxn];

void init() {
    inv[0] = fac[0] = 1;
    for (int i = 1; i <= h + w; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = fpm(fac[i], mod - 2);
    }
}

long long c(long long n, long long m) {
    if (n < m || n < 0 || m < 0) return 0;
    return fac[n] * inv[n - m] % mod * inv[m] % mod;
}

// Performance Invariant Checkers
void check_large_board_size_invariant(long long h, long long w) {
    if (h + w > 200000) {
        cerr << "Warning: Performance bottleneck condition triggered - large board size!" << endl;
        abort();
    }
}

void check_modular_exponentiation_invariant(long long h, long long w) {
    if ((h + w) > 200000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive modular exponentiation!" << endl;
        abort();
    }
}

void check_black_cells_invariant(int n) {
    if (n > 1000 && n < 2000) {
        cerr << "Warning: Performance bottleneck condition triggered - dense black cell configuration!" << endl;
        abort();
    }
}

int main() {
    cin >> h >> w >> n;
    
    // Insert performance checks after input
    check_large_board_size_invariant(h, w);
    check_modular_exponentiation_invariant(h, w);
    check_black_cells_invariant(n);
    
    init();
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &a[i].x, &a[i].y);
    }
    init();
    sort(a + 1, a + n + 1, cmp);
    long long ans = c(h + w - 1 - 1, h - 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = c(a[i].x - 1 + a[i].y - 1, a[i].x - 1);
        for (int j = 1; j <= i - 1; j++) {
            if (a[j].x <= a[i].x && a[j].y <= a[i].y) {
                dp[i] = (dp[i] -
                         dp[j] * c(a[i].x + a[i].y - a[j].x - a[j].y, a[i].x - a[j].x) %
                             mod +
                         mod) %
                        mod;
            }
        }
        ans = (ans - dp[i] * c(h - a[i].x + w - a[i].y, h - a[i].x) % mod + mod) %
              mod;
    }
    cout << ans << endl;
}