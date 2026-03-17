#include <bits/stdc++.h>
using namespace std;
int dbg = 0;
const long long oo = 8e18;
void solve() {
  int N, M;
  scanf("%d%d", &N, &M);
  vector<int> d(M);
  for (int i = 0; i < M; i++) scanf("%d", &d[i]);
  sort((d).begin(), (d).end());
  int G, R;
  scanf("%d%d", &G, &R);
  vector<vector<bool>> mk(G, vector<bool>(M, 0));
  vector<vector<int>> dist(G, vector<int>(M, 0));
  mk[0][0] = 1;
  deque<pair<int, int>> bfs;
  bfs.push_back({0, 0});
  int ptr = 0;
  long long ans = oo;
  while (((int)(bfs).size())) {
    int x = bfs.front().first;
    int T = bfs.front().second;
    bfs.pop_front();
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
        } else
          bfs.push_front({x - 1, nT});
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
        } else
          bfs.push_front({x + 1, nT});
      }
    }
  }
  if (ans == oo)
    puts("-1");
  else
    printf("%lld\n", ans);
}
int main() {
  solve();
  return 0;
}
