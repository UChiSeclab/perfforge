#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_large_circular_distance(int n, int distance) {
    if (n > 100 && distance > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - large circular distance!" << endl;
        abort();
    }
}

void check_repeated_pos_setup(int n) {
    if (n > 100) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated setup of large pos vector!" << endl;
        abort();
    }
}

void check_high_candy_density(int stationCandyCount, int n) {
    if (stationCandyCount > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - high candy density at a station!" << endl;
        abort();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> v(n);
    for (long long i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        v[x - 1].push_back(y - 1);
    }

    // Check repeated setup of large pos vector
    check_repeated_pos_setup(n);

    for (long long i = 0; i < n; i++) {
        long long ans = 0;
        vector<long long> pos(5005, 0);
        for (long long j = i, c = 0;; j = (j + 1) % n, c++) {
            pos[j] = c;
            if ((j + 1) % n == i) break;
        }
        for (long long j = i;; j = (j + 1) % n) {
            long long tans = 0;
            if (v[j].size() != 0) {
                long long fin, dist = INT_MAX;
                for (auto x : v[j]) {
                    long long tdist;
                    if (pos[x] < pos[j])
                        tdist = pos[x] + n - pos[j];
                    else
                        tdist = pos[x] - pos[j];
                    
                    // Check large circular distance
                    check_large_circular_distance(n, tdist);

                    if (tdist < dist) dist = tdist, fin = x;
                }
                if (pos[fin] < pos[j])
                    tans = pos[fin] + (v[j].size()) * n;
                else
                    tans = (v[j].size() - 1) * n + pos[fin];
                ans = max(ans, tans);

                // Check high candy density
                check_high_candy_density(v[j].size(), n);
            }
            if ((j + 1) % n == i) break;
        }
        cout << ans << " ";
    }
    return 0;
}