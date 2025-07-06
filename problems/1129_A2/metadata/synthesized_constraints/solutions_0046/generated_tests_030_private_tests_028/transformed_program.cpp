#include <bits/stdc++.h>
using namespace std;

int n, m;
pair<int, int> A[20005];
vector<int> v[5005];
int atleast[5005], r[5005], vis[5005], mindist[5005];

// Checker functions for performance invariants
void check_station_candy_count(int n, int m) {
    if (n > 4000 && m > 15000) {
        cerr << "Warning: Performance bottleneck condition triggered! High station and candy counts." << endl;
        abort();
    }
}

void check_frequent_reset(int n) {
    if (n > 4000) {
        cerr << "Warning: Performance bottleneck condition triggered! Frequent reset and calculation for large n." << endl;
        abort();
    }
}

void check_circular_traversal(int n, const vector<int>& v) {
    int highTraversalStations = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i].size() > n / 2) {
            highTraversalStations++;
        }
    }
    if (highTraversalStations > n / 4) {
        cerr << "Warning: Performance bottleneck condition triggered! High traversal in circular network." << endl;
        abort();
    }
}

void check_nested_loops(int n, const vector<int>& r) {
    int heavyProcessingStations = 0;
    for (int i = 1; i <= n; i++) {
        if (r[i] > n / 4) {
            heavyProcessingStations++;
        }
    }
    if (heavyProcessingStations > n / 4) {
        cerr << "Warning: Performance bottleneck condition triggered! Resource-intensive nested loops." << endl;
        abort();
    }
}

int main() {
    scanf("%d %d", &n, &m);
    
    // Check for potential performance bottlenecks based on initial input
    check_station_candy_count(n, m);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) mindist[j] = r[j] = vis[j] = 0;

        // Check for frequent resets
        check_frequent_reset(n);

        for (int cur = 1; cur <= n; cur++) {
            int j = i + cur - 1;
            if (j > n) j -= n;
            vis[j] = 1;
            r[j] = v[j].size();
            for (int k : v[j]) {
                int dist;
                if (vis[k] == 0) {
                    if (k > j)
                        dist = k - j;
                    else
                        dist = k + n - j;
                } else {
                    if (k > j)
                        dist = k - j;
                    else
                        dist = k + n - j;
                }
                if (mindist[j] == 0)
                    mindist[j] = dist;
                else
                    mindist[j] = min(mindist[j], dist);
            }
        }

        // Check for circular network traversal
        check_circular_traversal(n, r);

        long long res = 0;
        int t = 0;
        for (int cur = 1; cur <= n; cur++) {
            int j = i + cur - 1;
            if (j > n) j -= n;
            long long tmp = r[j];
            if (tmp == 0) {
                t++;
                continue;
            }
            tmp = 1ll * (tmp - 1) * n + t + mindist[j];
            res = max(res, tmp);
            t++;
        }

        // Check for resource-intensive loops
        check_nested_loops(n, r);

        printf("%lld ", res);
    }
    puts("");
    return 0;
}