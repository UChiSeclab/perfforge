#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int INF = (int)(1e9 + 1e6);
const long long LINF = (long long)(4e18);
const double EPS = 1e-9;
mt19937 ggen;
const int MOD = 1000000007;
int add(int a, int b, int m = MOD) {
    int res = a + b;
    if (res >= m) res -= m;
    return res;
}
int sub(int a, int b, int m = MOD) {
    int res = a - b;
    if (res < 0) res += m;
    return res;
}
int mul(int a, int b, int m = MOD) { return (long long)a * b % m; }
const int MAXN = 105000;
int k, n;
int mas[MAXN];
int full;
int c[MAXN];

void check_high_combinatorial_evaluations(int k, int maskEvaluations) {
    if (maskEvaluations > (1 << (k * 2))) {
        cerr << "Warning: Performance bottleneck condition triggered due to high combinatorial evaluations!" << endl;
        abort();
    }
}

void check_repeated_early_exits(int earlyExits, int maskEvaluations) {
    if (earlyExits > (maskEvaluations * 0.75)) {
        cerr << "Warning: Performance bottleneck condition triggered due to repeated early exits!" << endl;
        abort();
    }
}

void check_bitmask_complexity(int k, int validMasks) {
    if (validMasks > (1 << k)) {
        cerr << "Warning: Performance bottleneck condition triggered due to bitmask complexity!" << endl;
        abort();
    }
}

void init() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; ++j) {
            int q;
            scanf("%d", &q);
            mas[i] <<= 1;
            mas[i] |= q;
        }
    }
}

bool check_mask(int mask, int &earlyExits) {
    int cnt[4] = {0, 0, 0, 0};
    int pr = 0;
    for (int i = 0; i < (1 << k); ++i) {
        if (mask & (1 << i)) {
            if (!c[i]) {
                ++earlyExits;
                return false;
            }
            ++pr;
            for (int j = 0; j < k; ++j) {
                if (i & (1 << j)) {
                    ++cnt[j];
                }
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        if (cnt[i] * 2 > pr) {
            ++earlyExits;
            return false;
        }
    }
    return true;
}

void solve() {
    init();
    full = (1 << k) - 1;
    for (int i = 1; i <= n; ++i) {
        ++c[mas[i]];
    }
    int maskEvaluations = 0;
    int earlyExits = 0;
    int validMasks = 0;

    for (int mask = 1; mask <= (1 << full); ++mask) {
        ++maskEvaluations;
        if (check_mask(mask, earlyExits)) {
            ++validMasks;
            printf("YES\n");
            return;
        }
    }

    // Placing checks after the loops to catch performance bottlenecks
    check_high_combinatorial_evaluations(k, maskEvaluations);
    check_repeated_early_exits(earlyExits, maskEvaluations);
    check_bitmask_complexity(k, validMasks);

    printf("NO\n");
}

int main() {
    iostream::sync_with_stdio(false);
    cin.tie(0);
    ggen = mt19937(1337);
    solve();
    return 0;
}