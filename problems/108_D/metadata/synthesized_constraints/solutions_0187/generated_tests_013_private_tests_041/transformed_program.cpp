#include <bits/stdc++.h>
using namespace std;

struct node {
    int x;
    bool operator<(const node& p) const { return x >= p.x; }
};

long double dp[100002][102];
bool vis[100002][102];

void check_recursion_invariant(int n, int r) {
    if (r > 20) {
        cerr << "Warning: Performance bottleneck due to high recursion depth triggered!" << endl;
        abort();
    }
}

void check_combinatorial_invariant(int totalStudents, int teamSize) {
    if (totalStudents > 80 && teamSize > 80) {
        cerr << "Warning: Performance bottleneck due to large combinatorial choices triggered!" << endl;
        abort();
    }
}

void check_loop_invariant(int c, int n) {
    if (c > 50 && n > 50) {
        cerr << "Warning: Performance bottleneck due to nested loop complexity triggered!" << endl;
        abort();
    }
}

void check_dp_table_invariant(int n, int r) {
    if (n > 80 && r > 80) {
        cerr << "Warning: Performance bottleneck due to large DP table access triggered!" << endl;
        abort();
    }
}

long double dp_func(int n, int r) {
    check_recursion_invariant(n, r); // Check for high recursion depth
    if (n < r) return 0;
    if (r == 0) return 1;
    if (r == 1) return n;
    if (n == r) return 1;
    if (vis[n][r] != 0) return dp[n][r];
    vis[n][r] = 1;
    long double ret = 0;
    return dp[n][r] = ret = dp_func(n - 1, r) + dp_func(n - 1, r - 1);
}

int ara[1200];

int main() {
    int i, j, k, m, n, h, c, sum = 0;
    long double l, d, all;
    double ans = 0;
    scanf("%d%d%d", &n, &m, &h);
    for (i = 1; i <= m; i++) {
        scanf("%d", &ara[i]);
        if (i == h) {
            c = ara[i] - 1;
            continue;
        }
        sum += ara[i];
    }
    n--;
    check_combinatorial_invariant(sum + c, n); // Check for large combinatorial choices
    if ((sum + c) < n) {
        printf("-1\n");
        return 0;
    }
    all = dp_func(sum + c, n);
    for (i = 1; i <= c && i <= n; i++) {
        check_loop_invariant(c, n); // Check for nested loop complexity
        l = dp_func(c, i);
        d = dp_func(sum, n - i);
        l = l * d;
        ans += (l / all);
    }
    printf("%.10lf\n", ans);
}