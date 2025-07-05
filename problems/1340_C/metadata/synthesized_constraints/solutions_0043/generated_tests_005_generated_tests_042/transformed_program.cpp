#include <bits/stdc++.h>
using namespace std;
const long long oo = 8e18;

void check_excessive_waiting_invariant(int currentTime, int G, int R) {
    int cycleTime = G + R;
    if ((currentTime % cycleTime) >= G) {
        cerr << "Warning: excessive waiting invariant triggered - too much waiting during red light" << endl;
        abort();
    }
}

void check_complex_navigation_invariant(int position, int prevPosition, const vector<int>& d) {
    auto it = find(d.begin(), d.end(), position);
    auto prevIt = find(d.begin(), d.end(), prevPosition);
    if (it == d.end() || prevIt == d.end()) {
        cerr << "Warning: complex navigation invariant triggered - moving off safety islands" << endl;
        abort();
    }
}

void solve() {
    int N, M;
    scanf("%d%d", &N, &M);
    vector<int> d(M);
    for (int i = 0; i < M; i++) scanf("%d", &d[i]);
    sort(d.begin(), d.end());
    int G, R;
    scanf("%d%d", &G, &R);

    vector<vector<bool>> mk(G, vector<bool>(M, 0));
    vector<vector<int>> dist(G, vector<int>(M, 0));
    mk[0][0] = 1;
    deque<pair<int, int>> bfs;
    bfs.push_back({0, 0});
    long long ans = oo;

    while (!bfs.empty()) {
        int x = bfs.front().first;
        int T = bfs.front().second;
        bfs.pop_front();

        check_excessive_waiting_invariant(T, G, R); // Check for excessive waiting

        if (T == 0) {
            int need = N - d[x];
            if (need <= G) {
                long long build = (G + R);
                build *= dist[T][x];
                build += need;
                ans = min(ans, build);
            }
        }

        if (x) {
            int nT = T + d[x] - d[x - 1];
            if (nT == G) nT = 0;
            if (nT <= G && !mk[nT][x - 1]) {
                mk[nT][x - 1] = 1;
                dist[nT][x - 1] = dist[T][x];
                if (!nT) {
                    dist[nT][x - 1]++;
                    bfs.push_back({x - 1, nT});
                } else {
                    bfs.push_front({x - 1, nT});
                }
                check_complex_navigation_invariant(d[x], d[x - 1], d); // Check for complex navigation
            }
        }

        if (x < M - 1) {
            int nT = T + d[x + 1] - d[x];
            if (nT == G) nT = 0;
            if (nT <= G && !mk[nT][x + 1]) {
                mk[nT][x + 1] = 1;
                dist[nT][x + 1] = dist[T][x];
                if (!nT) {
                    dist[nT][x + 1]++;
                    bfs.push_back({x + 1, nT});
                } else {
                    bfs.push_front({x + 1, nT});
                }
                check_complex_navigation_invariant(d[x], d[x + 1], d); // Check for complex navigation
            }
        }
    }

    if (ans == oo) {
        puts("-1");
    } else {
        printf("%lld\n", ans);
    }
}

int main() {
    solve();
    return 0;
}