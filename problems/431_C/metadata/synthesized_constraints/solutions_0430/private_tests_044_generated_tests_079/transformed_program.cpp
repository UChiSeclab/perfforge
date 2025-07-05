#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 1;
const int mod = 1e9 + 7;
int n, k, d, f[N + 1][N][2], x[N];

inline void add(int& src, const int& dt) {
    src = (src % mod + dt % mod) % mod;
}

void check_high_recursion_depth(int n, int k) {
    if (n >= 90 && k >= 90) {  // Threshold adjusted within input constraints
        cerr << "Warning: High recursion depth with large search space!" << endl;
        abort();
    }
}

void check_large_k_small_d(int k, int d) {
    if (k >= 90 && d < k / 2) {  // Example threshold: large k but d smaller than half of k
        cerr << "Warning: Inefficient handling of large k with small d!" << endl;
        abort();
    }
}

void check_high_weight_requirement(int n, int d) {
    if (n >= 95 && d >= 5) {  // Emphasizing larger n with a minimum d
        cerr << "Warning: High weight requirement causes excessive path accumulation!" << endl;
        abort();
    }
}

int dfs(int rank, int sum, int check) {
    if (sum > n) return 0;
    int& res = f[rank][sum][check];
    if (~res) return res;
    res = 0;
    if (sum == n) {
        if (!check) return res = 0;
        return res = 1;
    }
    for (int v = 1; v <= k; ++v) {
        x[rank] = v;
        res = (res + dfs(rank + 1, sum + v, check | (v >= d))) % mod;
    }
    return res;
}

int main() {
    scanf("%d%d%d", &n, &k, &d);

    // Insert checkers to diagnose potential performance issues
    check_high_recursion_depth(n, k);  // Check for high recursion depth
    check_large_k_small_d(k, d);       // Check for inefficient handling of large k with small d
    check_high_weight_requirement(n, d); // Check for high weight requirement

    memset(f, -1, sizeof f);
    cout << dfs(1, 0, 0);
    return 0;
}