#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

const int mods[10] = {1000000007, 999999937, 999999929, 999999893, 999999883,
                      999999797, 999999761, 999999757, 999999751, 999999739};
const int mod = 1000000007;
int rand_mods[2];
const long double eps = 1e-10;
const int siz = 1e5 + 5, siz2 = 1e6 + 5, lg = 21, block = 448, block2 = 1000,
          mxv = 1e5 + 1, sqrt_mod = 31630;
const int alpha_sz = 26;
int n, m, xv[85], s[85], dp[siz];
bool cov[siz];

void check_recursive_call_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered by extensive recursion due to antenna positioning!" << endl;
        abort();
    }
}

void check_clustering_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to clustered antennas with small initial scopes!" << endl;
        abort();
    }
}

int solve(int i) {
    if (i > m) {
        return 0;
    }
    int &ret = dp[i];
    if (ret != -1) {
        return ret;
    }
    if (cov[i]) {
        return ret = solve(i + 1);
    }
    ret = INT_MAX;
    bool ent = 0;
    for (int j = 1; j <= n; j++) {
        if (xv[j] < i) {
            continue;
        }
        ent = 1;
        int added = max(xv[j] - s[j] - i, 0);
        ret = min(ret, added + solve(xv[j] + s[j] + added + 1));
    }
    return ent ? ret : (ret = m - i + 1);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &xv[i], &s[i]);
        for (int j = max(xv[i] - s[i], 1); j <= min(xv[i] + s[i], m); j++) {
            cov[j] = 1;
        }
    }
    
    // Integrate performance checks
    int max_distance = 0;
    for (int i = 1; i <= n; ++i) {
        max_distance = max(max_distance, max(1 - (xv[i] - s[i]), m - (xv[i] + s[i])));
    }
    check_recursive_call_invariant(max_distance > 10000); // Check for expansive recursive needs

    int small_scope_count = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 0 && i > 1 && abs(xv[i] - xv[i - 1]) < 1000) {
            small_scope_count++;
        }
    }
    check_clustering_invariant(small_scope_count > 10); // Check for clustering with small scopes
    
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(1));
    return 0;
}