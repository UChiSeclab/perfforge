#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int M = 1e2 + 30;
const int N = 1003;
const int mo = 1e9 + 7;
const LL inf = 1e16 + 1;

// Check for large permutation space
void check_permutation_invariant(int k, int n) {
    if (k > n - 2) {
        cerr << "Warning: Performance bottleneck condition triggered - large permutation space!" << endl;
        abort();
    }
}

// Check for excessive recursive calls
void check_recursive_invariant(int k) {
    if (k >= 7) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursive calls!" << endl;
        abort();
    }
}

LL qpow(LL a, LL b) {
    LL res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mo;
        b >>= 1;
        a = a * a % mo;
    }
    return res;
}

char s[M][M];
int a[M];
int vis[M];
LL res = 0;

bool check(int u, int n) {
    for (int i = 1; i <= n; i++) vis[i] = 0;
    while (!vis[u]) {
        if (u == 1) return true;
        vis[u] = 1;
        u = a[u];
    }
    return false;
}

void dfs(int u, int n) {
    if (u > n) {
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            if (!check(i, n)) {
                flag = 1;
                break;
            }
        }
        if (!flag) res++;
        return;
    }
    for (int i = 1; i <= n; i++) {
        a[u] = i;
        dfs(u + 1, n);
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    // Check performance invariants
    check_permutation_invariant(k, n);
    check_recursive_invariant(k);

    LL tmp = qpow(n - k, n - k);
    dfs(1, k);
    res = res * tmp % mo;
    printf("%I64d\n", res);
    return 0;
}