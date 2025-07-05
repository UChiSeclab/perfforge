#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int max_k = 10;
long long n, k, cnt, ret = 1, niz[max_k], memo[max_k];
bool ok, onstack[max_k];

void check_combinatorial_invariant(int k, int maxK) {
    if (k == maxK) {
        cerr << "Warning: combinatorial_invariant triggered - high value of k!" << endl;
        abort();
    }
}

void check_recursive_depth_invariant(int depth, int threshold) {
    if (depth > threshold) {
        cerr << "Warning: recursive_depth_invariant triggered - excessive recursive depth!" << endl;
        abort();
    }
}

void check_recursive_overhead_invariant(int recursionCalls, int maxCalls) {
    if (recursionCalls > maxCalls) {
        cerr << "Warning: recursive_overhead_invariant triggered - excessive recursive calls!" << endl;
        abort();
    }
}

bool dfs(int curr, int depth) {
    check_recursive_depth_invariant(depth, 50); // Check for excessive recursion depth
    if (!curr) return true;
    if (memo[curr] != -1) return memo[curr];
    if (onstack[curr]) return memo[curr] = false;
    onstack[curr] = true;
    memo[curr] = dfs(niz[curr], depth + 1);
    onstack[curr] = false;
    return memo[curr];
}

void rec(int idx, int *recursionCalls) {
    (*recursionCalls)++;
    check_recursive_overhead_invariant(*recursionCalls, 500000); // Check for excessive recursive calls
    if (idx == k) {
        for (int i = 0; i < k; i++) memo[i] = -1;
        ok = true;
        for (int i = 1; i < k; i++) ok &= dfs(i, 0);
        cnt += ok;
        return;
    }
    for (int i = 0; i < k; i++) {
        niz[idx] = i;
        rec(idx + 1, recursionCalls);
    }
}

int main() {
    cin >> n >> k;
    check_combinatorial_invariant(k, max_k - 2); // Check for high combinatorial value of k

    for (int i = 0; i < n - k; i++) ret = (ret * (n - k)) % MOD;

    int recursionCalls = 0;
    rec(0, &recursionCalls);

    cout << (cnt * ret) % MOD;
    return 0;
}