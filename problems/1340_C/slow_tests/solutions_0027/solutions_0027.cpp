#include <bits/stdc++.h>
using namespace std;
const long long N = 1e4 + 7, M = 1009;
const long long INF = LLONG_MAX;
long long arr[N + 2], vis[N][M], dis[N][M];
long long n, m, G, R;
long long get(long long id, long long g) { return 0; }
long long getit() {
  queue<pair<long long, long long> > q[G + 1];
  long long cur = 0;
  q[cur].push({0, G});
  vis[0][0] = 1;
  dis[0][0] = 0;
  set<long long> st = {cur};
  auto check = [&](long long w, long long idx, long long g,
                   long long edge_weight) {
    if (idx < 0 or idx >= m or g < 0) {
      return false;
    }
    pair<long long, long long> nxt = {idx, g};
    if (!vis[nxt.first][nxt.second]) {
      vis[nxt.first][nxt.second] = 1;
      dis[nxt.first][nxt.second] = w + edge_weight;
      long long y = (cur + edge_weight) % (G + 1);
      st.insert(y);
      q[y].push(nxt);
    }
    return true;
  };
  while (st.size()) {
    auto x = st.lower_bound(cur);
    if (x == st.end())
      cur = *st.begin();
    else
      cur = *x;
    pair<long long, long long> f = q[cur].front();
    q[cur].pop();
    long long id = f.first, g = f.second, w = dis[f.first][f.second];
    long long edge_weight = R;
    if (!g)
      check(w, id, G, R);
    else {
      long long nx = arr[id + 1], pr = -1, cr = arr[id];
      if (id) pr = arr[id - 1];
      edge_weight = abs(cr - nx);
      check(w, id + 1, g - edge_weight, edge_weight);
      edge_weight = abs(cr - pr);
      check(w, id - 1, g - edge_weight, edge_weight);
    }
    if (q[cur].empty()) st.erase(cur);
  }
  long long ans = INF;
  for (long long g = 0; g < (long long)G + 1; g++)
    if (vis[m - 1][g]) ans = min(ans, dis[m - 1][g]);
  if (ans == INF) ans = -1;
  return ans;
}
void solve() {
  cin >> n >> m;
  for (long long i = 0; i < (long long)m; i++) cin >> arr[i];
  sort(arr, arr + m);
  cin >> G >> R;
  cout << getit();
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test = 1;
  while (test--) solve();
}
