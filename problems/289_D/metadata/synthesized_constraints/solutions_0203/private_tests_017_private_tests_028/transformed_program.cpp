#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int n, k;
vector<vector<short>> vec;
vector<int> sec;
bool mark[20];
vector<int> adj[20];
int cnt = 0;

// Function checkers
void check_combinatorial_explosion(int k) {
    if (k >= 8) {
        cerr << "Warning: Performance bottleneck condition triggered - potential combinatorial explosion due to large k!" << endl;
        abort();
    }
}

void check_dfs_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth or branching!" << endl;
        abort();
    }
}

void check_graph_traversal(int n, int k) {
    if (k == n) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient graph traversal with maximum k!" << endl;
        abort();
    }
}

int dfs(int v) {
    check_dfs_invariant(mark[v]);
    if (mark[v]) return 0;
    mark[v] = 1;
    int ret = 1;
    for (int u : adj[v]) ret += dfs(u);
    return ret;
}

void gen(int rem) {
    if (rem == 0) {
        memset(mark, 0, sizeof(mark));
        for (int i = 0; i < k; i++) adj[i].clear();
        for (int i = 0; i < sec.size(); i++) adj[sec[i]].push_back(i);
        if (dfs(0) == k) cnt++;
        return;
    }
    for (int i = 0; i < k; i++) {
        sec.push_back(i);
        gen(rem - 1);
        sec.pop_back();
    }
}

int main() {
    cin >> n >> k;
    
    check_combinatorial_explosion(k);
    check_graph_traversal(n, k);

    long long ans = 1;
    for (int i = 0; i < n - k; i++) ans = (ans * (n - k)) % MOD;
    gen(k);
    ans = (ans * (long long)cnt) % MOD;
    cout << ans << endl;
    return 0;
}