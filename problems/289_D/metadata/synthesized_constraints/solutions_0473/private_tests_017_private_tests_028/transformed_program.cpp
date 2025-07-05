#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
bool vis[10], good[10];
int n, k;
long long ans, mod = 1000000007;
vector<int> v;

void check_recursive_invariant(int recursionDepth, int maxThreshold) {
    if (recursionDepth > maxThreshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursion depth!" << endl;
        abort();
    }
}

void check_backtracking_invariant(int k, int threshold) {
    if (k >= threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - large branching factor in backtracking!" << endl;
        abort();
    }
}

void check_recursion_repetition_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated recursion on same nodes!" << endl;
        abort();
    }
}

bool dfs(int u) {
    if (vis[u]) return good[u];
    vis[u] = 1;
    if (u == 1) return good[u] = 1;
    return good[u] = dfs(v[u]);
}

bool check() {
    memset(good, 0, sizeof good);
    memset(vis, 0, sizeof vis);
    bool ret = 1;
    for (int i = 1; i <= k; i++) ret &= dfs(i);
    return ret;
}

void bt(int i, int depth) {
    // Check for excessive recursion depth
    check_recursive_invariant(depth, 10);

    if (i == k + 1) {
        ans += check();
        return;
    }
    for (int num = 1; num <= k; num++) {
        v.push_back(num);
        bt(i + 1, depth + 1);
        v.pop_back();
    }
}

int main() {
    scanf("%d%d", &n, &k);

    // Check for large branching factor in backtracking
    check_backtracking_invariant(k, 8);

    v.push_back(0);
    bt(1, 0);
    for (int i = k + 1; i <= n; i++) ans = (ans * (n - k)) % mod;
    printf("%lld\n", ans);
}