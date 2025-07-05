#include <bits/stdc++.h>
using namespace std;

// Checker functions implementation (from Phase 3)
// ...

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, d;
    cin >> n >> d;
    vector<long long> a(n);
    for (long long i = 1; i < n - 1; i++) {
        cin >> a[i];
    }
    vector<pair<long long, long long> > v(n);
    for (long long i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    // Insert invariant checks before the main algorithm
    check_computation_invariant(n);

    // Calculate max distance to use for checking distance cost
    int maxDist = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
            maxDist = max(maxDist, dist);
        }
    }
    check_distance_cost_invariant(maxDist, d);

    long long l = 0, h = 1e12;
    while (l < h) {
        long long mid = (l + h) / 2;
        long long t = mid;
        bool ok = true;
        long long dis[n];
        long long par[n];
        for (long long i = 0; i < n; i++) dis[i] = -(1LL << 61), par[i] = -1;
        dis[0] = mid;
        for (long long i = 0; i < n; i++) {
            for (long long j = 0; j < n; j++) {
                for (long long k = 0; k < n; k++) {
                    if (j == k) continue;
                    if (dis[k] < dis[j] -
                                   d * (abs(v[j].first - v[k].first) +
                                        abs(v[j].second - v[k].second)) +
                                   a[k] &&
                        (dis[j] -
                         d * (abs(v[j].first - v[k].first) +
                              abs(v[j].second - v[k].second)) +
                         a[k]) >= 0) {
                        dis[k] = dis[j] -
                                 d * (abs(v[j].first - v[k].first) +
                                      abs(v[j].second - v[k].second)) +
                                 a[k];
                        par[k] = j;
                    }
                }
            }
        }
        if (dis[n - 1] < 0) ok = false;
        if (ok)
            h = mid;
        else
            l = mid + 1;
    }
    cout << l << '\n';
}