#include <bits/stdc++.h>
using ll = long long;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};

struct HopcroftKarp {
    std::vector<std::vector<ll>> graph;
    std::vector<ll> level, match;
    std::vector<bool> used, vv;
    HopcroftKarp(ll n, ll m) : graph(n), match(m, -1), used(n) {}

    void add_edge(ll u, ll v) { graph[u].push_back(v); }
    
    void bfs() {
        level.assign(graph.size(), -1);
        std::queue<ll> q;
        for (int i = 0; i < graph.size(); i++) {
            if (!used[i]) {
                q.push(i);
                level[i] = 0;
            }
        }
        while (!q.empty()) {
            ll u = q.front();
            q.pop();
            for (auto v : graph[u]) {
                ll c = match[v];
                if (level[c] == -1 && c >= 0) {
                    level[c] = level[u] + 1;
                    q.push(c);
                }
            }
        }
    }
    
    bool dfs(ll u) {
        vv[u] = true;
        for (auto v : graph[u]) {
            ll c = match[v];
            if (c < 0 || (!vv[c] && level[c] == level[u] + 1 && dfs(c))) {
                match[v] = u;
                used[u] = true;
                return true;
            }
        }
        return false;
    }
    
    ll bipartite_matching() {
        ll ret = 0LL;
        while (1) {
            bfs();
            vv.assign(graph.size(), false);
            ll flow = 0LL;
            for (int i = 0; i < graph.size(); i++) {
                if (!used[i] && dfs(i)) {
                    flow++;
                }
            }
            if (flow == 0) {
                return ret;
            }
            ret += flow;
        }
    }
    
    void print() {
        for (int i = 0; i < match.size(); i++) {
            if (match[i] >= 0) {
                std::cout << match[i] << " " << i << std::endl;
            }
        }
    }
};

// Implementing check functions as defined in Phase 3
void check_field_size_invariant(int n, int m) {
    if (n * m > 500000) {
        std::cerr << "Warning: Performance bottleneck condition triggered - large field size leading to dense graph representation!" << std::endl;
        abort();
    }
}

void check_graph_density_invariant(int n, int m) {
    if (std::max(n, m) > 900) {
        std::cerr << "Warning: Performance bottleneck condition triggered - high graph density!" << std::endl;
        abort();
    }
}

void check_edge_construction_invariant(int n, int m) {
    if (n * m > 500000) {
        std::cerr << "Warning: Performance bottleneck condition triggered - extensive edge construction!" << std::endl;
        abort();
    }
}

int main() {
    ll n, m;
    std::cin >> n >> m;
    
    // Place checks right after input is read
    check_field_size_invariant(n, m);
    check_graph_density_invariant(n, m);
    check_edge_construction_invariant(n, m);

    HopcroftKarp bm(n * m, n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 8; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (0 <= x && x < n && 0 <= y && y < m) {
                    if ((i + j) % 2 == 0) {
                        bm.add_edge(m * i + j, m * x + y);
                    } else {
                        bm.add_edge(m * x + y, m * i + j);
                    }
                }
            }
        }
    }
    std::cout << n * m - bm.bipartite_matching() << std::endl;
    return 0;
}