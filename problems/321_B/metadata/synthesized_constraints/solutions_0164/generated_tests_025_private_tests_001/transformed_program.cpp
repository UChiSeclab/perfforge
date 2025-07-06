#include <bits/stdc++.h>
using namespace std;
const long long INF = numeric_limits<long long>::max() / 4;
int n, m, S, T, SCRAP;
long long res = 0;
string enemy[1234];
int enemyi[1234], mei[1234];

void check_graph_complexity_invariant(int edgeCount, int threshold) {
    if (edgeCount > threshold) {
        cerr << "Warning: Performance bottleneck due to high graph density!" << endl;
        abort();
    }
}

void check_relaxation_invariant(int relaxationSteps, int threshold) {
    if (relaxationSteps > threshold) {
        cerr << "Warning: Performance bottleneck due to excessive relaxation steps!" << endl;
        abort();
    }
}

void check_card_interaction_invariant(int interactionCount, int threshold) {
    if (interactionCount > threshold) {
        cerr << "Warning: Performance bottleneck due to complex card interactions!" << endl;
        abort();
    }
}

void check_node_edge_invariant(int nodeCount, int edgeCount, int nodeThreshold, int edgeThreshold) {
    if (nodeCount > nodeThreshold || edgeCount > edgeThreshold) {
        cerr << "Warning: Performance bottleneck due to excessive nodes or edges!" << endl;
        abort();
    }
}

struct MinCostMaxFlow {
    int N;
    vector<vector<long long> > cap, flow, cost;
    vector<int> found;
    vector<long long> dist, pi, width;
    vector<pair<int, int> > dad;
    MinCostMaxFlow(int N)
        : N(N),
          cap(N, vector<long long>(N)),
          flow(N, vector<long long>(N)),
          cost(N, vector<long long>(N)),
          found(N),
          dist(N),
          pi(N),
          width(N),
          dad(N) {}

    void AddEdge(int from, int to, long long cap, long long cost) {
        this->cap[from][to] = cap;
        this->cost[from][to] = cost;
    }

    void Relax(int s, int k, long long cap, long long cost, int dir) {
        long long val = dist[s] + pi[s] - pi[k] + cost;
        if (cap && val < dist[k]) {
            dist[k] = val;
            dad[k] = make_pair(s, dir);
            width[k] = min(cap, width[s]);
        }
    }

    long long Dijkstra(int s, int t) {
        fill(found.begin(), found.end(), false);
        fill(dist.begin(), dist.end(), INF);
        fill(width.begin(), width.end(), 0);
        dist[s] = 0;
        width[s] = INF;
        int relaxationSteps = 0; // Count relaxation steps
        while (s != -1) {
            int best = -1;
            found[s] = true;
            for (int k = 0; k < N; k++) {
                if (found[k]) continue;
                Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
                Relax(s, k, flow[k][s], -cost[k][s], -1);
                relaxationSteps += 2;
                if (best == -1 || dist[k] < dist[best]) best = k;
            }
            s = best;
        }
        check_relaxation_invariant(relaxationSteps, 50000); // Arbitrary threshold for demo
        for (int k = 0; k < N; k++) pi[k] = min(pi[k] + dist[k], INF);
        return width[t];
    }

    pair<long long, long long> GetMaxFlow(int s, int t) {
        long long totflow = 0, totcost = 0;
        int edgeCount = 0; // Count edges
        while (long long amt = Dijkstra(s, t)) {
            totflow += amt;
            for (int x = t; x != s; x = dad[x].first) {
                if (dad[x].second == 1) {
                    flow[dad[x].first][x] += amt;
                    totcost += amt * cost[dad[x].first][x];
                } else {
                    flow[x][dad[x].first] -= amt;
                    totcost -= amt * cost[x][dad[x].first];
                }
                edgeCount++;
            }
            long long tot = min<long long>(n, totflow) * 10000LL +
                            max<long long>(0, totflow - n) * 1000000LL;
            res = max(res, tot - totcost);
        }
        check_graph_complexity_invariant(edgeCount, 5000); // Arbitrary threshold for demo
        return make_pair(totflow, totcost);
    }
};

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        cin >> enemy[i] >> enemyi[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> mei[i];
    }
    S = n + m, T = S + 1, SCRAP = T + 1;
    MinCostMaxFlow mf(n + m + 3);
    for (int i = 0; i < m; ++i) {
        mf.AddEdge(S, i, 1, 0);
    }
    mf.AddEdge(SCRAP, T, 100, 0);
    int interactionCount = 0; // Count interactions
    for (int i = 0; i < n; ++i) {
        mf.AddEdge(i + m, T, 1, 0);
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (enemy[j] == "ATK") {
                if (enemyi[j] <= mei[i]) {
                    mf.AddEdge(i, j + m, 1, 10000 - (-enemyi[j] + mei[i]));
                }
            } else {
                if (enemyi[j] < mei[i]) {
                    mf.AddEdge(i, j + m, 1, 10000);
                }
            }
            mf.AddEdge(i, SCRAP, 1, 1000000 - mei[i]);
            interactionCount++;
        }
    }
    check_card_interaction_invariant(interactionCount, 2000); // Arbitrary threshold for demo
    mf.GetMaxFlow(S, T);
    cout << res << endl;
    return 0;
}