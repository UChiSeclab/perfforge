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

// Check if the number of nodes in the priority queue becomes excessive
void check_queue_size_invariant(int queueSize, int stationCount) {
    if (queueSize > stationCount * 10) {  // Threshold based on n (stations)
        cerr << "Warning: Performance bottleneck condition triggered - excessive nodes in queue!" << endl;
        abort();
    }
}

// Check if there are excessive distance calculations
void check_distance_calculation_invariant(int distanceCalculations, int stationCount) {
    if (distanceCalculations > stationCount * 1000) {  // Arbitrary high threshold
        cerr << "Warning: Performance bottleneck condition triggered - excessive distance calculations!" << endl;
        abort();
    }
}

// Check if the priority queue is repeatedly processing nodes
void check_node_processing_invariant(int nodeProcessedCount, int stationCount) {
    if (nodeProcessedCount > stationCount * 20) {  // Threshold based on n (stations)
        cerr << "Warning: Performance bottleneck condition triggered - excessive node processing!" << endl;
        abort();
    }
}

void dijkstra() {
    priority_queue<Nod> q;
    q.push((Nod){x[n], y[n], 0});
    dis[make_pair(x[n], y[n])] = 0;
    
    int distanceCalculations = 0;
    int nodeProcessedCount = 0;
    
    while (q.size()) {
        // Check queue size invariant before processing
        check_queue_size_invariant(q.size(), n);

        Nod tmp = q.top();
        q.pop();
        int X = tmp.x, Y = tmp.y;
        nodeProcessedCount++;

        if (tmp.dis > d * (abs(x[1] - x[n]) + abs(y[1] - y[n]))) continue;
        if (tmp.dis > dis[make_pair(X, Y)] || X < -100 || X > 100 || Y < -100 || Y > 100)
            continue;

        for (int i = 0; i < 4; i++) {
            int nx = X + dx[i], ny = Y + dy[i];
            int v = d + max(0, tmp.dis - mp[make_pair(X, Y)]);
            distanceCalculations++;

            // Check distance calculation invariant
            check_distance_calculation_invariant(distanceCalculations, n);

            if (!dis.count(make_pair(nx, ny)) || dis[make_pair(nx, ny)] > v) {
                dis[make_pair(nx, ny)] = v;
                q.push((Nod){nx, ny, v});
            }
        }
    }

    // Check node processing invariant after loop
    check_node_processing_invariant(nodeProcessedCount, n);

    printf("%d\n", dis[make_pair(x[1], y[1])]);
}

int main() {
    scanf("%d%d", &n, &d);
    for (int i = 2; i <= n - 1; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
    for (int i = 2; i < n; i++) mp[make_pair(x[i], y[i])] = a[i];
    dijkstra();
}