#include <bits/stdc++.h>
using namespace std;
int a, n, m, inf = (int)1e9;
vector<unordered_map<int, int>> memo;
vector<int> rain;
vector<int> umbrella;
int fatigue(int pos, int w) {
  if (pos == a) return 0;
  if (not memo[pos].empty()) {
    auto s = memo[pos].find(w);
    if (s != end(memo[pos])) return s->second;
  }
  int best = inf;
  if (umbrella[pos]) {
    best = min(best, umbrella[pos] + fatigue(pos + 1, umbrella[pos]));
  }
  if (not w) {
    if (rain[pos] and not umbrella[pos]) return inf;
  } else {
    best = min(best, w + fatigue(pos + 1, w));
  }
  if (not rain[pos]) {
    best = min(best, fatigue(pos + 1, 0));
  }
  memo[pos][w] = best;
  return best;
}
void solve() {
  cin >> a >> n >> m;
  memo.resize(a + 1);
  rain.resize(a + 1);
  umbrella.resize(a + 1, inf);
  int l, r;
  for (int i = 0; i < n; ++i) {
    cin >> l >> r;
    for (int j = l; j < r; ++j) {
      rain[j] = 1;
    }
  }
  int x, p;
  for (int i = 0; i < m; ++i) {
    cin >> x >> p;
    umbrella[x] = min(p, umbrella[x]);
  }
  int best = fatigue(0, 0);
  cout << (best < inf ? best : -1) << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
