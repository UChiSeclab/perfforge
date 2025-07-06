#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool ptime;
void inline fileIO() {
    ptime = false;
    srand((unsigned)time(0));
}
const int mxN = 1e3 + 5;
const int mod = 1e9 + 7;
long long n, k;
int vis[10];

void check_recursion_invariant(int k) {
    if (k == 8) {
        cerr << "Warning: Performance bottleneck condition triggered - High recursion depth with large k" << endl;
        abort();
    }
}

void check_branching_invariant(int k) {
    if (k == 8) {
        cerr << "Warning: Performance bottleneck condition triggered - Increased branching factor with large k" << endl;
        abort();
    }
}

void check_dfs_invariant(int k) {
    if (k == 8) {
        cerr << "Warning: Performance bottleneck condition triggered - Excessive DFS calls with large k" << endl;
        abort();
    }
}

void check_state_space_invariant(int k) {
    if (k == 8) {
        cerr << "Warning: Performance bottleneck condition triggered - Combinatorial state space with large k" << endl;
        abort();
    }
}

int dfs(int curr, vector<long long>& state) {
    vis[curr] = 1;
    int go = 0;
    if (curr == 1) return 1;
    if (!vis[state[curr]]) {
        go |= dfs(state[curr], state);
    }
    return go;
}

long long rec(long long curr, vector<long long>& state) {
    if (curr == k + 1) {
        long long flag = 1;
        for (int i = 2; i <= k; i++) {
            memset(vis, 0, sizeof vis);
            flag &= dfs(i, state);
        }
        if (k > 1) flag &= 1;
        return flag;
    }
    long long res = 0;
    for (long long nxt = 1; nxt <= k; nxt++) {
        state[curr] = nxt;
        res += rec(curr + 1, state);
        res = (res > mod ? res - mod : res);
        state[curr] = 0;
    }
    return res;
}

void inline solve(int tt) {
    cin >> n >> k;

    // Insert invariant checks here
    check_recursion_invariant(k);
    check_branching_invariant(k);
    check_dfs_invariant(k);
    check_state_space_invariant(k);

    long long ways = 1;
    for (int i = k + 1; n - k && i <= n; i++) {
        ways = (ways * (n - k)) % mod;
    }
    vector<long long> to(k + 1, 0);
    ways = ways * rec(1, to);
    ways %= mod;
    cout << ways << "\n";
}

int main() {
    fileIO();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 0, t = 1;
    while (t--) {
        solve(++tt);
    }
    if (ptime)
        cerr << "processor time: " << clock() / (double)CLOCKS_PER_SEC << "s    ";
    return 0;
}