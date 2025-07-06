#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 5;
const int EMOD = 998244353;
int n, m, k;
long long dp[2222][2222];

// Checker functions
void check_large_n_small_k_invariant(int n, int k, int recursion_depth) {
    if (n > 1800 && k < 10 && recursion_depth > 500) {
        cerr << "Warning: Performance bottleneck condition triggered - large n with small k leading to extensive recursion." << endl;
        abort();
    }
}

void check_recursion_depth_invariant(int i, int n, int k) {
    if (i > n - 10 && k > 0) {
        cerr << "Warning: Performance bottleneck condition triggered - recursion depth approaching n with non-reduced k." << endl;
        abort();
    }
}

long long f(int i, int k, int depth) {
    // Check the invariants within the recursive function
    check_large_n_small_k_invariant(n, k, depth);
    check_recursion_depth_invariant(i, n, k);
    
    if (dp[i][k] != -1) return dp[i][k];
    if (!k && i == n) return 1LL;
    if (i == n) return 0LL;
    return dp[i][k] = ((m * f(i + 1, k - 1, depth + 1)) % EMOD + f(i + 1, k, depth + 1) % EMOD) % EMOD;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    long long ans = m;
    m--;
    memset(dp, -1, sizeof(dp));
    ans = (ans * f(1, k, 0)) % EMOD;
    printf("%lld\n", ans);
    return 0;
}