#include <bits/stdc++.h>
using namespace std;

int n, k, c[5005], fa[505], h[15], f[505][5005];

void check_recursive_depth_invariant(int recursionDepth, int threshold) {
    if (recursionDepth > threshold) {
        cerr << "Warning: Performance bottleneck due to excessive recursion depth!" << endl;
        abort();
    }
}

void check_iteration_invariant(int iterations, int threshold) {
    if (iterations > threshold) {
        cerr << "Warning: Performance bottleneck due to excessive card match iterations!" << endl;
        abort();
    }
}

void check_dp_table_invariant(int tableUsage, int threshold) {
    if (tableUsage > threshold) {
        cerr << "Warning: Performance bottleneck due to excessive dynamic programming table usage!" << endl;
        abort();
    }
}

int solve(int in, int st) {
    static int recursionDepth = 0;
    static int iterationCount = 0;
    recursionDepth++;

    check_recursive_depth_invariant(recursionDepth, 500); // Example threshold for recursion depth

    if (in == n + 1) {
        recursionDepth--;
        return 0;
    }
    if (st == n * k + 1) {
        recursionDepth--;
        return 0;
    }
    if (f[in][st] != -1) {
        recursionDepth--;
        return f[in][st];
    }

    int cur = 0, cnt = 0;
    cur = max(cur, solve(in + 1, st));

    for (int i = st; i <= n * k; i++) {
        iterationCount++;
        check_iteration_invariant(iterationCount, 10000); // Example threshold for iterations

        if (c[i] > fa[in]) break;
        if (c[i] == fa[in]) {
            cnt++;
            cur = max(cur, solve(in + 1, i + 1) + h[cnt]);
            if (cnt == k) break;
        }
    }
    
    check_dp_table_invariant(f[in][st], 1000000); // Example threshold for DP table usage
    f[in][st] = cur;

    recursionDepth--;
    return cur;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n * k; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> fa[i];
    for (int i = 1; i <= k; i++) cin >> h[i];

    sort(c + 1, c + n * k + 1);
    sort(fa + 1, fa + n + 1);
    
    memset(f, -1, sizeof f);
    cout << solve(1, 1);
    return 0;
}