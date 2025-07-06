#include <bits/stdc++.h>
using namespace std;

// Checker function for recursive exploration in funa
void check_recursive_depth_invariant(int shelfSize, int remainingItems) {
    if (shelfSize > 70 && remainingItems > 50) { // arbitrary thresholds
        cerr << "Warning: Performance bottleneck condition triggered in funa - large recursive exploration!" << endl;
        abort();
    }
}

// Checker function for depth and breadth of recursive calls
void check_recursion_breadth_invariant(int recursionDepth, int branchingFactor) {
    if (recursionDepth > 50 && branchingFactor > 20) { // arbitrary thresholds
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth and branching factor!" << endl;
        abort();
    }
}

// Checker function for dynamic programming state space in funb
void check_dynamic_programming_invariant(int m) {
    if (m > 9000) { // near the constraint limit
        cerr << "Warning: Performance bottleneck condition triggered in funb - large dynamic programming state space!" << endl;
        abort();
    }
}

// Checker function for high hit count on recursive conditions
void check_high_hit_count_invariant(int shelfSize, int remainingItems) {
    if (shelfSize > 80 && remainingItems > 40) { // arbitrary thresholds
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursive calls!" << endl;
        abort();
    }
}

int n, m;
long long dpa[111][111][111], a[111][111], dpb[111][10011];
int arr[111][111], sz[111], idx;
int vis[111][111][111], cnt = 1;

long long funa(int l, int r, int rem) {
    check_recursive_depth_invariant(r - l + 1, rem); // Check condition for large recursive exploration
    if (!rem || l > r) return 0;
    long long &ret = dpa[l][r][rem];
    if (vis[l][r][rem] == cnt) return ret;
    long long a = arr[idx][l] + funa(l + 1, r, rem - 1);
    long long b = arr[idx][r] + funa(l, r - 1, rem - 1);
    vis[l][r][rem] = cnt;
    return ret = max(a, b);
}

long long funb(int id, int rem) {
    check_dynamic_programming_invariant(rem); // Check condition for large dynamic programming state space
    if (rem == 0) return 0;
    if (id == n) return 0;
    long long &ret = dpb[id][rem];
    if (ret != -1) return ret;
    for (int i = 0; i <= sz[id]; ++i) {
        check_high_hit_count_invariant(sz[id], rem); // Check condition for excessive recursive calls
        if (i <= rem) ret = max(ret, a[id][i] + funb(id + 1, rem - i));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    check_dynamic_programming_invariant(m); // Initial check for large m
    for (int i = 0; i < n; ++i) {
        cin >> sz[i];
        for (int j = 0; j < sz[i]; ++j) cin >> arr[i][j];
    }
    memset(dpb, -1, sizeof dpb);
    for (int i = 0; i < n; ++i) {
        idx = i;
        for (int j = 0; j <= sz[i]; ++j) {
            a[i][j] = funa(0, sz[i] - 1, j);
        }
        ++cnt;
    }
    cout << funb(0, m) << '\n';
}