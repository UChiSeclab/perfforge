#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int MAXM = 10005;
int N, M;
int dp[MAXN][MAXN][MAXN];
int a[MAXN][MAXN];
int meh[MAXN][MAXN];
int sz[MAXN];
int dp2[MAXN][MAXM];

void check_recursion_invariant(int mv, int shelfSize) {
    if (mv > 5000 && shelfSize > 50) {
        cerr << "Warning: Recursion invariant triggered - excessive branching and recursion depth." << endl;
        abort();
    }
}

void check_memoization_invariant(bool isResetting, int mv) {
    if (isResetting && mv > 5000) {
        cerr << "Warning: Memoization invariant triggered - redundant calculations due to frequent resets." << endl;
        abort();
    }
}

void check_shelf_size_invariant(int mv, int shelfSize) {
    if (shelfSize > 80 && mv > 5000) {
        cerr << "Warning: Shelf size invariant triggered - large shelf and high moves leading to slowdown." << endl;
        abort();
    }
}

int solve(int x, int l, int r, int mv) {
    if (mv <= 0) return 0;
    int &ref = dp[l][r][mv];
    if (ref > -1) return ref;
    if (l == r)
        ref = a[x][l];
    else
        ref = max(a[x][l] + solve(x, l + 1, r, mv - 1),
                  a[x][r] + solve(x, l, r - 1, mv - 1));
    return ref;
}

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &M);
    for (int i = 0, _i = N; i < _i; ++i) {
        int x;
        scanf("%d", &x);
        sz[i] = x;
        for (int j = 0, _j = x; j < _j; ++j) {
            scanf("%d", &a[i][j + 1]);
        }
    }
    for (int i = 0, _i = N; i < _i; ++i) {
        memset(dp, -1, sizeof dp);
        check_memoization_invariant(true, sz[i]); // Check before solving for this shelf
        check_shelf_size_invariant(sz[i], M); // Check based on shelf size and move count
        for (int j = (1), _j = (sz[i]); j <= _j; ++j) {
            meh[i][j] = solve(i, 1, sz[i], j);
            check_recursion_invariant(j, sz[i]); // Check during recursion
        }
    }
    int ans = 0;
    for (int i = (1), _i = (N); i <= _i; ++i) {
        for (int j = (0), _j = (M); j <= _j; ++j) {
            for (int k = (0), _k = (min(sz[i - 1], j)); k <= _k; ++k) {
                if (k > j) continue;
                dp2[i][j] = max(dp2[i][j], dp2[i - 1][j - k] + meh[i - 1][k]);
                ans = max(ans, dp2[i][j]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}