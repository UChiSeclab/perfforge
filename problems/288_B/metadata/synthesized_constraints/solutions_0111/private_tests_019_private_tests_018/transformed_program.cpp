#include <bits/stdc++.h>
using namespace std;
const int inf = 1000 * 1000 * 1000 + 7;
int n, k, p[10];
long long ans = 1, sum;
bool mark[10];
vector<int> rew[10];

void check_backtracking_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: backtracking invariant triggered - excessive permutations explored" << endl;
        abort();
    }
}

void check_dfs_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: dfs invariant triggered - high depth and branching factor" << endl;
        abort();
    }
}

void check_data_structure_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: data structure invariant triggered - repeated operations on large structures" << endl;
        abort();
    }
}

void check_combinatorial_explosion_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: combinatorial explosion invariant triggered" << endl;
        abort();
    }
}

// DFS function used to explore the reachability
void dfs(int v) {
    mark[v] = true;
    for (int i = 0; i < rew[v].size(); i++)
        if (!mark[rew[v][i]]) dfs(rew[v][i]);
}

// Backtracking function to explore permutations of plaques
void bt(int x) {
    if (x == k + 1) {
        memset(mark, 0, sizeof mark);
        dfs(1);
        for (int i = 1; i <= k; i++) rew[i].clear();
        for (int i = 1; i <= k; i++) rew[p[i]].push_back(i);
        for (int i = 1; i <= k; i++)
            if (!mark[i]) return;
        sum++;
        return;
    }
    for (int i = 1; i <= k; i++) {
        p[x] = i;
        bt(x + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;

    // Check for combinatorial explosion when k is large
    check_combinatorial_explosion_invariant(k >= 8);

    // Calculate initial part of the answer
    for (int i = 1; i <= n - k; i++) ans = (ans * (n - k)) % inf;

    // Check for excessive backtracking when k is large
    check_backtracking_invariant(k >= 8);

    bt(1); // Begin backtracking

    // Check for repetitive data structure operations when k is large
    check_data_structure_invariant(k >= 8);

    ans = (ans * sum) % inf;
    cout << ans << endl;
    return 0;
}