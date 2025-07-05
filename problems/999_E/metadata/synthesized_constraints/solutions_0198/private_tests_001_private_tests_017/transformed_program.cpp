#include <bits/stdc++.h>
using namespace std;

void check_sparse_road_invariant(long long n, long long m) {
    if (n > 1000 && m < n / 10) {
        cerr << "Warning: Performance bottleneck condition triggered - high city count with sparse roads!" << endl;
        abort();
    }
}

void check_unreachable_cities_invariant(const vector<bool>& vis) {
    long long unvisited_count = count(vis.begin() + 1, vis.end(), false);
    if (unvisited_count > vis.size() / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - multiple unreachable cities!" << endl;
        abort();
    }
}

void check_nested_loops_invariant(long long n, const set<long long>& s) {
    if (s.size() > n / 5) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive nested loops with set operations!" << endl;
        abort();
    }
}

vector<long long> v[5001];
set<long long> s;
long long n, m, cap;
vector<bool> vis;

void dfs(long long cur) {
    vis[cur] = true;
    for (long long adj : v[cur]) {
        if (!vis[adj]) {
            dfs(adj);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m >> cap;
    
    // Checking for sparse road invariant immediately after reading inputs
    check_sparse_road_invariant(n, m);
    
    long long x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        v[x].push_back(y);
    }
    vis = vector<bool>(n + 1, false);
    dfs(cap);
    
    // Check for unreachable cities after initial DFS
    check_unreachable_cities_invariant(vis);
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            s.insert(i);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (s.find(i) != s.end()) {
            vis = vector<bool>(n + 1, false);
            dfs(i);
            for (int j = 1; j <= n; j++) {
                if (vis[j] == 1 && i != j && s.find(j) != s.end()) {
                    s.erase(j);
                }
            }
        }
    }
    
    // Check nested loops invariant right before the final output
    check_nested_loops_invariant(n, s);
    
    cout << s.size() << endl;
}