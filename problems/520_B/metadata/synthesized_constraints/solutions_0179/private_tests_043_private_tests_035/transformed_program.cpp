#include <bits/stdc++.h>
using namespace std;

int n, m, f[30010];

void check_deep_recursion_invariant(int w, int t, int maxDepth) {
    if (w < m / 2 && t > maxDepth) {
        cerr << "Warning: deep_recursion_invariant triggered - excessive recursion depth!" << endl;
        abort();
    }
}

void check_large_search_space_invariant(int w, int operations) {
    if (w < m / 2 && operations > 10000) { // Arbitrary threshold
        cerr << "Warning: large_search_space_invariant triggered - excessive operations!" << endl;
        abort();
    }
}

void check_high_computational_path_invariant(int w, int t) {
    if (w < m && t > 2000) { // Assuming depth of 2000 is considerable
        cerr << "Warning: high_computational_path_invariant triggered - deep computational path!" << endl;
        abort();
    }
}

int operations = 0; // Track operations for large search space detection

void dfs(int w, int t) {
    operations++;
    check_deep_recursion_invariant(w, t, 1000); // Example max depth
    check_large_search_space_invariant(w, operations);
    check_high_computational_path_invariant(w, t);

    if (w <= 0 || w >= m * 2) return;
    if (f[w] <= t) return;
    f[w] = t;
    dfs(w * 2, t + 1);
    dfs(w - 1, t + 1);
}

int main() {
    scanf("%d%d", &n, &m);
    memset(f, 60, sizeof(f));
    if (n >= m)
        printf("%d\n", n - m);
    else {
        dfs(n, 0);
        printf("%d\n", f[m]);
    }
    return 0;
}