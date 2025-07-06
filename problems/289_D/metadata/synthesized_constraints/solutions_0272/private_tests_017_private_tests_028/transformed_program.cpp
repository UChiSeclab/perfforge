#include <bits/stdc++.h>

using namespace std;

int n, k, ans = 1, cnt, a[16], st[16];
bool used[16];

int dfs(int x) {
    if (x == 1) return 1;
    if (x == a[x]) return -1;
    if (!st[x]) st[x] = -1;
    if (used[x]) return st[x];
    used[x] = true;
    st[x] = dfs(a[x]);
    return st[x];
}

bool check() {
    for (int i = 1; i <= k; i++) used[i] = st[i] = 0;
    for (int i = 1; i <= k; i++) st[i] = dfs(i);
    for (int i = 1; i <= k; i++) {
        if (st[i] != 1) return 0;
    }
    return 1;
}

void rec(int x) {
    if (x == k + 1) {
        cnt += check();
        return;
    }
    for (int i = 1; i <= k; i++) {
        a[x] = i;
        rec(x + 1);
    }
}

// Phase 4: Integrated checker functions
void check_combinatorial_invariant(int n, int k) {
    if (k > 7 || (k > 5 && k > n / 2)) {
        cerr << "Warning: combinatorial_invariant triggered - high combinatorial space due to large k" << endl;
        abort();
    }
}

void check_recursive_invariant(int k) {
    if (k > 7) {
        cerr << "Warning: recursive_invariant triggered - excessive recursive calls expected for large k" << endl;
        abort();
    }
}

int main() {
    scanf("%d%d", &n, &k);

    // Inserting checks before executing main computations
    check_combinatorial_invariant(n, k); // Detects high combinatorial space
    check_recursive_invariant(k); // Detects excessive recursive calls

    for (int i = k + 1; i <= n; i++) ans = (1ll * ans * (n - k)) % 1000000007;
    rec(1);
    ans = (1ll * ans * cnt) % 1000000007;
    printf("%d\n", ans);

    return 0;
}