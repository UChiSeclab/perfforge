#include <bits/stdc++.h>
using namespace std;
const int N = 502;
int n, d, a[N];
int x[N], y[N];
map<pair<int, int>, int> dis, mp;
struct Nod {
    int x, y, dis;
    bool operator<(const Nod& o) const { return dis > o.dis; }
};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void check_node_processing_invariant(int nodesProcessed) {
    if (nodesProcessed > 50000) {  // Arbitrary threshold for node processing
        cerr << "Warning: Performance bottleneck condition triggered - excessive nodes being processed!" << endl;
        abort();
    }
}

void check_equivalent_paths_invariant(int equivalentPaths) {
    if (equivalentPaths > 20000) {  // Arbitrary threshold for equivalent paths
        cerr << "Warning: Performance bottleneck condition triggered - excessive equivalent paths!" << endl;
        abort();
    }
}

void check_dense_station_clusters(int stationMoves) {
    if (stationMoves > 100000) {  // Arbitrary threshold for station moves
        cerr << "Warning: Performance bottleneck condition triggered - dense station clusters causing excessive moves!" << endl;
        abort();
    }
}

void dijkstra() {
    priority_queue<Nod> q;
    q.push((Nod){x[n], y[n], 0});
    dis[make_pair(x[n], y[n])] = 0;

    int nodesProcessed = 0;
    int equivalentPaths = 0;
    int stationMoves = 0;

    while (q.size()) {
        Nod tmp = q.top();
        q.pop();
        int X = tmp.x, Y = tmp.y;
        nodesProcessed++;
        check_node_processing_invariant(nodesProcessed);

        if (tmp.dis > d * (abs(x[1] - x[n]) + abs(y[1] - y[n]))) continue;
        if (tmp.dis > dis[make_pair(X, Y)] || X < -100 || X > 100 || Y < -100 || Y > 100)
            continue;
        if (X == x[1] && Y == y[1]) break;
        for (int i = 0; i < 4; i++) {
            int nx = X + dx[i], ny = Y + dy[i];
            int v = d + max(0, tmp.dis - mp[make_pair(X, Y)]);
            stationMoves++;
            check_dense_station_clusters(stationMoves);

            if (!dis.count(make_pair(nx, ny)) || dis[make_pair(nx, ny)] > v) {
                dis[make_pair(nx, ny)] = v;
                q.push((Nod){nx, ny, v});
                equivalentPaths++;
                check_equivalent_paths_invariant(equivalentPaths);
            }
        }
    }
    printf("%d\n", dis[make_pair(x[1], y[1])]);
}

int main() {
    scanf("%d%d", &n, &d);
    for (int i = 2; i <= n - 1; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
    for (int i = 2; i < n; i++) mp[make_pair(x[i], y[i])] = a[i];
    dijkstra();
}