#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 1e6 + 1, M = 1e4 + 1, G = 1e3 + 1, inf = 1e9 + 1;
int n, m, g, r;
int d[M];
bool used[M][G];

// Checker functions for performance bottlenecks
void check_island_distance_invariant(int green_time, const vector<int>& islands) {
    for (size_t i = 1; i < islands.size(); ++i) {
        if (islands[i] - islands[i - 1] > green_time) {
            cerr << "Warning: Performance bottleneck - Green light time not sufficient to cover distance between islands!" << endl;
            abort();
        }
    }
}

void check_backtracking_invariant(int green_time, const vector<int>& islands) {
    for (size_t i = 1; i < islands.size(); ++i) {
        if ((islands[i] - islands[i - 1]) > green_time) {
            cerr << "Warning: Performance bottleneck - Requires backtracking due to insufficient green light period!" << endl;
            abort();
        }
    }
}

void check_revisiting_states_invariant(int green_time, int total_distance) {
    if (green_time < total_distance) {
        cerr << "Warning: Performance bottleneck - Frequent revisits to states due to green light constraints!" << endl;
        abort();
    }
}

void check_bfs_exploration_invariant(int red_time, int green_time, const deque<pair<int, int>>& queue) {
    if (queue.size() > 1000 && red_time < green_time) {
        cerr << "Warning: Performance bottleneck - Excessive BFS state exploration due to traffic light constraints!" << endl;
        abort();
    }
}

void check_traffic_light_sync_invariant(int green_time, const vector<int>& islands) {
    for (size_t i = 1; i < islands.size(); ++i) {
        if ((islands[i] - islands[i - 1]) % green_time != 0) {
            cerr << "Warning: Performance bottleneck - Traffic light synchronization misalignment!" << endl;
            abort();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> n >> m;
    vector<int> islands(m);
    for (int i = 0; i < m; ++i) cin >> islands[i];
    sort(islands.begin(), islands.end());
    cin >> g >> r;

    // Check for potential performance bottlenecks
    check_island_distance_invariant(g, islands);
    check_backtracking_invariant(g, islands);
    check_traffic_light_sync_invariant(g, islands);

    deque<pair<int, int>> q;
    q.emplace_front(0, 0);
    q.emplace_back(-1, -1);
    used[0][0] = true;
    bool found = false;
    int rw = 0;

    while (rw < M) {
        check_bfs_exploration_invariant(r, g, q); // Check excessive BFS exploration
        int w = q.front().first, v = q.front().second;
        q.pop_front();
        if (w == -1) {
            if (found) break;
            ++rw;
            q.emplace_back(-1, -1);
            continue;
        }
        if (w == g) {
            q.emplace_back(0, v);
            continue;
        }
        if (v != 0) {
            int new_w = w + islands[v] - islands[v - 1];
            if (new_w <= g && !used[v - 1][new_w]) {
                used[v - 1][new_w] = true;
                q.emplace_front(new_w, v - 1);
            }
        }
        if (v != m - 1) {
            int new_w = w + islands[v + 1] - islands[v];
            if (new_w <= g && !used[v + 1][new_w]) {
                used[v + 1][new_w] = true;
                if (v + 1 == m - 1) found = true;
                q.emplace_front(new_w, v + 1);
            }
        }
    }
    if (rw == M) {
        cout << "-1\n";
        return 0;
    }
    int ans = inf;
    for (int i = 0; i <= g; ++i)
        if (used[m - 1][i]) ans = min(ans, rw * (r + g) + i);
    cout << ans << '\n';
}