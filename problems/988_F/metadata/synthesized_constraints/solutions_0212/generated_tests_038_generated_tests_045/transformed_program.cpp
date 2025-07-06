#include <bits/stdc++.h>
using namespace std;

const int N = 2001;
const int inf = (int)1e9 + 1;
const long long big = (long long)1e18 + 1;
const int p = 239;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const double eps = 1e-9;

struct Line {
    long long k, b;
    Line() {}
    Line(long long k, long long b) : k(k), b(b) {}
    long long val(long long x) { return k * x + b; }
};

int cnt_v;
Line tree[N * 4];

void build(int n) {
    cnt_v = 1;
    while (cnt_v < n) cnt_v = cnt_v << 1;
    for (int i = 0; i < 2 * (cnt_v)-1; ++i) {
        tree[i] = Line(0, inf);
    }
}

void check_update_frequency(int updates) {
    if (updates > 2000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive segment tree updates!" << endl;
        abort();
    }
}

void check_search_frequency(int searches) {
    if (searches > 2000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive segment tree searches!" << endl;
        abort();
    }
}

void check_umbrella_management(int num_umbrellas, int num_segments) {
    if (num_umbrellas * num_segments > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - complex umbrella management!" << endl;
        abort();
    }
}

void check_scenario_complexity(int n, int m, int L) {
    if ((n > m) && (L > 1500)) {
        cerr << "Warning: Performance bottleneck condition triggered - complex scenario combinations!" << endl;
        abort();
    }
}

void upd(int x, int lx, int rx, Line line) {
    static int update_count = 0;
    update_count++;
    check_update_frequency(update_count);

    int m = (lx + rx) >> 1;
    if (line.val(m) < tree[x].val(m)) swap(tree[x], line);
    if (rx - lx == 1) return;
    if (line.val(lx) < tree[x].val(lx))
        upd(x + x + 1, lx, m, line);
    else
        upd(x + x + 2, m, rx, line);
}

long long get(long long p) {
    static int search_count = 0;
    search_count++;
    check_search_frequency(search_count);

    int x = p + cnt_v - 1;
    long long res = tree[x].val(p);
    while (x > 0) {
        x = (x - 1) >> 1;
        res = min(res, tree[x].val(p));
    }
    return res;
}

int add[N];
int best[N];
long long dp[N];

int main(void) {
    int L, n, m;
    scanf("%d%d%d", &L, &n, &m);

    check_scenario_complexity(n, m, L);
    check_umbrella_management(n, m);

    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        add[l]++;
        add[r]--;
    }
    for (int i = 1; i <= L; ++i) add[i] = add[i] + add[i - 1];
    fill(best, best + L + 1, inf);
    for (int i = 0; i < m; ++i) {
        int x, p;
        scanf("%d%d", &x, &p);
        best[x] = min(best[x], p);
    }
    build(L + 1);
    fill(dp, dp + L + 1, inf);
    dp[0] = 0;
    upd(0, 0, cnt_v, Line(best[0], dp[0] - best[0] * 0));
    for (int i = 1; i <= L; ++i) {
        dp[i] = get(i);
        if (add[i - 1] == 0) dp[i] = min(dp[i], dp[i - 1]);
        upd(0, 0, cnt_v, Line(best[i], dp[i] - best[i] * i));
    }
    if (dp[L] != inf)
        cout << dp[L] << endl;
    else {
        printf("-1");
    }
}