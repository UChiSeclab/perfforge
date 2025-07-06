#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")
#pragma GCC target("sse2")
#pragma GCC target("sse3")
#pragma GCC target("sse4.1")
#pragma GCC target("sse4.2")
#pragma GCC target("popcnt")
#pragma GCC target("abm")
#pragma GCC target("mmx")
#pragma GCC target("tune=native")
using namespace std;

const int N = 2048;
const int M = N / 2;
const int inf = 1e9;

void check_long_green_light(int g, int max_distance) {
    if (g > max_distance) {
        cerr << "Warning: Performance bottleneck due to long green light duration relative to safety island distances." << endl;
        abort();
    }
}

void check_dense_islands(const vector<int>& d, int threshold) {
    for (size_t i = 1; i < d.size(); ++i) {
        if (d[i] - d[i - 1] < threshold) {
            cerr << "Warning: Performance bottleneck due to dense distribution of safety islands." << endl;
            abort();
        }
    }
}

void check_red_light_duration(int r, int min_duration) {
    if (r < min_duration) {
        cerr << "Warning: Performance bottleneck due to insufficient red light duration for planning." << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> d(m);
    cin >> d;
    int g, r;
    cin >> g >> r;
    sort(d.begin(), d.end());

    // Insert checks after input
    int max_distance = n / (m - 1); // Estimate max distance between islands for green light check
    int min_red_duration = 5; // Arbitrary threshold for min red light duration
    check_long_green_light(g, max_distance);
    check_dense_islands(d, 2); // Arbitrary threshold for minimum distance between islands
    check_red_light_duration(r, min_red_duration);

    vector<vector<int>> gr(m);
    for (int i = 0; i < m; ++i) {
        gr[i].reserve(g + 5);
    }
    auto calc = [&](int i) {
        bitset<N> mask = 0;
        int ind = i;
        while (ind >= 0) {
            if (d[i] - d[ind] <= g)
                mask[M - (d[i] - d[ind])] = 1;
            else
                break;
            --ind;
        }
        ind = i;
        while (ind < m) {
            if (d[ind] - d[i] <= g)
                mask[M + (d[ind] - d[i])] = 1;
            else
                break;
            ++ind;
        }
        bitset<N> gol = 0, gor = 0;
        gol[M] = 1;
        gor[M] = 1;
        for (int i = 0; i < g; ++i) {
            gor <<= 1;
            gol >>= 1;
            gor |= (gol & mask);
            gol |= (gor & mask);
        }
        mask &= (gol | gor);
        ind = i + 1;
        while (ind < m) {
            if (d[ind] - d[i] <= g) {
                if ((mask[M + (d[ind] - d[i])])) gr[i].push_back(ind);
            } else {
                break;
            }
            ++ind;
        }
    };
    vector<int> dist(m, inf);
    dist[0] = 0;
    for (int i = 0; i < m; ++i) {
        if (dist[i] != inf) {
            calc(i);
            for (auto k : gr[i]) {
                dist[k] = min(dist[k], dist[i] + 1);
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < m; ++i) {
        if (dist[i] == inf) continue;
        if (d[i] + g >= n) {
            if (ans == -1 || ans > dist[i] * (r + g) + (n - d[i]))
                ans = dist[i] * (r + g) + (n - d[i]);
        }
    }
    cout << ans << endl;
    return 0;
}