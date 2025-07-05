#include <bits/stdc++.h>
using namespace std;

void check_time_range_invariant(int maxTime, int numTasks) {
    if (maxTime > 10 * numTasks) { // Arbitrary threshold for inefficiency
        cerr << "Warning: Performance bottleneck condition triggered - excessive time range with sparse tasks!" << endl;
        abort();
    }
}

void check_server_decrement_invariant(int timeRange) {
    if (timeRange > 1000000) { // Inefficient for too large a time range
        cerr << "Warning: Performance bottleneck condition triggered - frequent server state changes!" << endl;
        abort();
    }
}

void check_task_demand_invariant(int requiredServers, int totalServers) {
    if (requiredServers > totalServers / 2) { // Arbitrarily chosen threshold for heavy demand
        cerr << "Warning: Performance bottleneck condition triggered - heavy server demand!" << endl;
        abort();
    }
}

void solve() {
    int n, m, i, j, k, l, p;
    cin >> n >> m;
    vector<int> servers(n + 1, 0);
    vector<pair<pair<int, int>, int> > v(m);
    
    for (auto &i : v) {
        cin >> i.first.first >> i.first.second >> i.second;
        // Check for high server demand
        check_task_demand_invariant(i.first.second, n);
    }

    int maxTaskTime = v.back().first.first;  // Assuming v is sorted by task time
    check_time_range_invariant(maxTaskTime, m); // Check for inefficient time range
    
    for (int time = 1, cur = 0; time <= 1000000 && cur < m; time++) {
        if (v[cur].first.first == time) {
            for (i = 1, j = 0; i <= n; i++) {
                if (servers[i] == 0) j++;
            }
            if (j < v[cur].first.second) {
                cout << -1 << "\n";
            } else {
                for (i = 1, j = k = 0; i <= n && k < v[cur].first.second; i++) {
                    if (servers[i] == 0) {
                        servers[i] = v[cur].second;
                        j += i;
                        k++;
                    }
                }
                cout << j << "\n";
            }
            cur++;
        }
        check_server_decrement_invariant(1000000); // Check for frequent server state changes
        
        for (auto &i : servers) {
            if (i) i--;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}