#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > px[200010], py[200010];
const int N = 1e5 + 1;
pair<int, int> ans[200010], P[200010];
int main() {
  int n, w, h;
  cin >> n >> w >> h;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    int g, p, t;
    scanf("%d %d %d", &g, &p, &t);
    if (g == 1)
      px[p - t + N].push_back(pair<int, int>(p, i));
    else
      py[p - t + N].push_back(pair<int, int>(p, i));
    mx = max(mx, p - t + N);
  }
  for (int i = 1; i <= mx; i++) sort(px[i].begin(), px[i].end());
  for (int i = 1; i <= mx; i++) sort(py[i].begin(), py[i].end());
  for (int i = 1; i <= mx; i++) {
    int nn = 0;
    for (auto p : px[i]) {
      P[++nn] = pair<int, int>(p.first, h);
    }
    for (int j = py[i].size() - 1; j >= 0; j--)
      P[++nn] = pair<int, int>(w, py[i][j].first);
    for (int j = px[i].size() - 1; j >= 0; j--) {
      int id = px[i][j].second;
      ans[id] = P[nn--];
    }
    for (auto p : py[i]) {
      int id = p.second;
      ans[id] = P[nn--];
    }
  }
  for (int i = 1; i <= n; i++) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
