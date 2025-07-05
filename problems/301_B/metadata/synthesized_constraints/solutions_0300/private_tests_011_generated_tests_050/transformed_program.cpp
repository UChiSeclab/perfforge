#include <bits/stdc++.h>
using namespace std;

int a[102], x[102], y[102];
int n, d;
bool vis[102];
int dist_call_count = 0; // Counter for distance calculations

int dist(int a, int b) {
    dist_call_count++; // Increment distance calculation counter
    return abs(x[a] - x[b]) + abs(y[a] - y[b]);
}

void check_path_exploration_invariant(int explored_paths, int threshold) {
    if (explored_paths > threshold) {
        cerr << "Warning: Performance bottleneck due to excessive path exploration!" << endl;
        abort();
    }
}

void check_priority_queue_invariant(int pq_size, int threshold) {
    if (pq_size > threshold) {
        cerr << "Warning: Performance bottleneck due to large priority queue size!" << endl;
        abort();
    }
}

void check_distance_calculation_invariant(int dist_calls, int threshold) {
    if (dist_calls > threshold) {
        cerr << "Warning: Performance bottleneck due to excessive distance calculations!" << endl;
        abort();
    }
}

bool first(long long val) {
    priority_queue<pair<long long, int> > q;
    q.push(make_pair(val, 1));
    memset(vis, false, sizeof(vis));

    int explored_paths = 0; // Counter for path exploration

    while (!q.empty()) {
        pair<long long, int> now = q.top();
        q.pop();
        if (vis[now.second]) continue;
        vis[now.second] = true;
        if (now.second == n) return true;
        for (int i = 1; i <= n; i++) {
            if (now.first >= d * dist(now.second, i)) {
                q.push(make_pair(now.first - d * dist(now.second, i) + a[i], i));
            }
        }
        explored_paths++; // Increment the exploration path count
        check_priority_queue_invariant(q.size(), 1000); // Check priority queue size
    }

    check_path_exploration_invariant(explored_paths, 5000); // Check path exploration
    return false;
}

int main() {
    int i, j;
    scanf("%d", &n);
    scanf("%d", &d);

    for (i = 2; i < n; i++) scanf("%d", &a[i]);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
        scanf("%d", &y[i]);
    }

    long long lo = 0, hi = (long long)1e15;
    while (hi - lo > 1) {
        long long mid = (hi + lo) / 2;
        dist_call_count = 0; // Reset the distance calculation counter for each iteration
        if (first(mid))
            hi = mid;
        else
            lo = mid;
        check_distance_calculation_invariant(dist_call_count, 10000); // Check distance calculations
    }

    cout << hi << endl;
    return 0;
}