#include <bits/stdc++.h>

struct node {
    int x, y;
};
long long fac[200005], inv[200005], ans[2005];
int n, m, k;
node f[2005];

long long fp(long long x, int y) {
    return (y % 2 ? x : 1ll) * (y / 2 ? fp(x * x % 1000000007, y / 2) : 1ll) %
           1000000007;
}

void pre(int n) {
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % 1000000007;
    for (int i = 1; i <= n; i++) inv[i] = fp(fac[i], 1000000007 - 2);
}

long long c(int x, int y) {
    return fac[x] * inv[y] % 1000000007 * inv[x - y] % 1000000007;
}

int cmp(node x, node y) { return x.x != y.x ? x.x < y.x : x.y < y.y; }

// Adding checker functions

void check_large_board_dimensions(int h, int w) {
    if (h + w > 150000) {
        cerr << "Warning: Performance bottleneck due to large board dimensions!" << endl;
        abort();
    }
}

void check_few_black_cells(int h, int w, int n) {
    int potentialPaths = (h - 1) + (w - 1);
    if (n < 5 && potentialPaths > 150000) {
        cerr << "Warning: Potentially too many paths due to few black cells and large board!" << endl;
        abort();
    }
}

void check_complex_obstacle_arrangement(int h, int w, int n, node* f) {
    if (h * w > 5000000 && n < 20) {
        for (int i = 1; i <= n; ++i) {
            if (f[i].x > h / 3 && f[i].x < 2 * h / 3 &&
                f[i].y > w / 3 && f[i].y < 2 * w / 3) {
                cerr << "Warning: Performance issue due to central clustered obstacles on large board!" << endl;
                abort();
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    
    // Insert check for large board dimensions
    check_large_board_dimensions(n, m);

    pre(n + m);
    for (int i = 1; i <= k; i++) scanf("%d%d", &f[i].x, &f[i].y);
    f[++k] = node{n, m};
    std::sort(f + 1, f + k + 1, cmp);

    // Insert check for few black cells
    check_few_black_cells(n, m, k);

    // Insert check for complex obstacle arrangement
    check_complex_obstacle_arrangement(n, m, k, f);

    for (int i = 1; i <= k; i++) {
        long long s = c(f[i].x + f[i].y - 2, f[i].x - 1);
        for (int j = 1; j <= i - 1; j++)
            if (f[j].x <= f[i].x && f[j].y <= f[i].y)
                s = (s -
                     ans[j] * c(f[i].x + f[i].y - f[j].x - f[j].y, f[i].x - f[j].x) %
                         1000000007 +
                     1000000007) %
                    1000000007;
        ans[i] = s;
    }
    printf("%lld\n", ans[k]);
    return 0;
}