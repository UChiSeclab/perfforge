#include <bits/stdc++.h>
using namespace std;

void io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

const int INF = 1e9;
const int InfCost = 1e9;

struct MCMF {
    static const int InfCapacity = INF;

    struct Edge {
        int to;
        int rev;
        int capacity;
        int cost;
    };

    vector<vector<Edge>> g;
    
    void init(int n) { 
        g.assign(n, vector<Edge>()); 
    }
    
    void add(int i, int j, int capacity = InfCapacity, int cost = int()) {
        Edge e, f;
        e.to = j, f.to = i;
        e.capacity = capacity, f.capacity = 0;
        e.cost = cost, f.cost = -cost;
        g[i].push_back(e);
        g[j].push_back(f);
        g[i].back().rev = (int)g[j].size() - 1;
        g[j].back().rev = (int)g[i].size() - 1;
    }

    pair<int, int> minimumCostMaximumFlow(int s, int t, int f = InfCapacity, bool bellmanFord = false) {
        int n = g.size();
        vector<int> dist(n);
        vector<int> prev(n);
        vector<int> prevEdge(n);
        pair<int, int> total = make_pair(0, 0);
        vector<int> potential(n);

        while (f > 0) {
            fill(dist.begin(), dist.end(), InfCost);
            if (bellmanFord || total.second == 0) {
                dist[s] = 0;
                for (int k = 0; k < n; k++) {
                    bool update = false;
                    for (int i = 0; i < n; i++)
                        if (dist[i] != InfCost)
                            for (int ei = 0; ei < (int)g[i].size(); ei++) {
                                const Edge &e = g[i][ei];
                                if (e.capacity <= 0) continue;
                                int j = e.to;
                                int d = dist[i] + e.cost;
                                if (dist[j] > d) {
                                    dist[j] = d;
                                    prev[j] = i;
                                    prevEdge[j] = ei;
                                    update = true;
                                }
                            }
                    if (!update) break;
                }
            } else {
                vector<bool> vis(n);
                priority_queue<pair<int, int>> q;
                q.push(make_pair(-0, s));
                dist[s] = 0;
                while (!q.empty()) {
                    int i = q.top().second;
                    q.pop();
                    if (vis[i]) continue;
                    vis[i] = true;
                    for (int ei = 0; ei < (int)g[i].size(); ei++) {
                        const Edge &e = g[i][ei];
                        if (e.capacity <= 0) continue;
                        int j = e.to;
                        int d = dist[i] + e.cost + potential[i] - potential[j];
                        if (d < dist[i]) d = dist[i];
                        if (dist[j] > d) {
                            dist[j] = d;
                            prev[j] = i;
                            prevEdge[j] = ei;
                            q.push(make_pair(-d, j));
                        }
                    }
                }
            }
            if (dist[t] == InfCost) break;
            if (!bellmanFord)
                for (int i = 0; i < n; i++) potential[i] += dist[i];
            int d = f;
            int distt = 0;
            for (int v = t; v != s;) {
                int u = prev[v];
                const Edge &e = g[u][prevEdge[v]];
                d = min(d, e.capacity);
                distt += e.cost;
                v = u;
            }
            f -= d;
            total.first += d * distt;
            total.second += d;
            for (int v = t; v != s; v = prev[v]) {
                Edge &e = g[prev[v]][prevEdge[v]];
                e.capacity -= d;
                g[e.to][e.rev].capacity += d;
            }
        }
        return total;
    }
};

int m, n;
string typ[105];
int pwr1[105];
int pwr2[105];

// Checkers for performance bottlenecks
void check_graph_construction_invariant(int n, int m) {
    if (n * m > 5000) {
        cerr << "Warning: Graph construction might be expensive due to large input size combination!" << endl;
        abort();
    }
}

void check_traversal_intensity_invariant(int potentialPaths) {
    if (potentialPaths > 10000) {
        cerr << "Warning: High traversal intensity might slow down the execution!" << endl;
        abort();
    }
}

void check_priority_queue_invariant(int nodes, int activeEdges) {
    if (nodes * activeEdges > 10000) {
        cerr << "Warning: Priority queue operations might be excessive due to dense graph!" << endl;
        abort();
    }
}

void check_iteration_invariant(int n, int m) {
    if (m > 90 && n > 90) {
        cerr << "Warning: Nested iterations might lead to performance issues!" << endl;
        abort();
    }
}

int solve1() {
    if (m < n) return 0;
    MCMF mcmf;
    mcmf.init(2 * m + 2);
    int src = 2 * m;
    int snk = 2 * m + 1;
    for (int i = 0; i < m; i++) {
        mcmf.add(src, i, 1, 0);
    }
    for (int i = m; i < 2 * m; i++) {
        mcmf.add(i, snk, 1, 0);
    }
    int potentialPaths = 0;  // Assumed variable to check potential paths
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (j < n) {
                if (typ[j] == "ATK") {
                    if (pwr1[i] >= pwr2[j]) {
                        mcmf.add(i, j + m, 1, -(pwr1[i] - pwr2[j]));
                        potentialPaths++;
                    }
                } else {
                    if (pwr1[i] > pwr2[j]) {
                        mcmf.add(i, j + m, 1, 0);
                        potentialPaths++;
                    }
                }
            } else {
                mcmf.add(i, j + m, 1, -pwr1[i]);
                potentialPaths++;
            }
        }
    }

    // Check traversal intensity based on an estimated count of paths
    check_traversal_intensity_invariant(potentialPaths);

    pair<int, int> ans = mcmf.minimumCostMaximumFlow(src, snk);
    if (ans.second < m) return 0;
    return -ans.first;
}

int solve2() {
    MCMF mcmf;
    mcmf.init(m + n + 2);
    int src = m + n;
    int snk = m + n + 1;
    for (int i = 0; i < m; i++) {
        mcmf.add(src, i, 1, 0);
        mcmf.add(i, snk, 1, 0);
    }
    for (int j = 0; j < n; j++) {
        mcmf.add(j + m, snk, 1, 0);
    }
    int potentialPaths = 0;  // Assumed variable to check potential paths
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (typ[j] == "ATK") {
                if (pwr1[i] >= pwr2[j]) {
                    mcmf.add(i, j + m, 1, -(pwr1[i] - pwr2[j]));
                    potentialPaths++;
                }
            }
        }
    }

    // Check traversal intensity based on an estimated count of paths
    check_traversal_intensity_invariant(potentialPaths);

    pair<int, int> ans = mcmf.minimumCostMaximumFlow(src, snk);
    return -ans.first;
}

int main(int argc, char *argv[]) {
    io();
    cin >> n >> m;
    
    check_graph_construction_invariant(n, m);
    check_iteration_invariant(n, m);

    for (int i = 0; i < n; i++) {
        cin >> typ[i] >> pwr2[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> pwr1[i];
    }

    int an1 = solve1();
    int an2 = solve2();
    cout << max(an1, an2) << '\n';
    return 0;
}