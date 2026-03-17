#include <bits/stdc++.h>
int n, m;
std::vector<std::vector<int> > g;
std::vector<int> kt;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> n >> m;
  g.resize(n);
  for (int i = 0; i < (m); ++i) {
    int a, b;
    std::cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
  }
  for (int i = 0; i < (n); ++i)
    std::sort(g[i].begin(), g[i].end(), [&](const int &a, const int &b) {
      return a - i + (i > a ? n : 0) < b - i + (i > b ? n : 0);
    });
  int mx = 0;
  for (int i = 0; i < (n); ++i) {
    mx = std::max(mx, (int)(g[i]).size());
  }
  int todo = 0;
  int add = 0;
  add += n * std::max(0, mx - 3);
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (mx - 3); ++j) {
      if (g[i].empty()) break;
      g[i].pop_back();
    }
    todo += (int)(g[i]).size();
  }
  kt.resize(n);
  for (int s = 0; s < (n); ++s) {
    for (int i = 0; i < (n); ++i) kt[i] = (int)(g[i]).size() - 1;
    int td = todo;
    int cnt = 0;
    int mxwait = 0;
    int ps = s;
    while (td > 0 || mxwait > 0) {
      if (kt[ps] >= 0) {
        mxwait =
            std::max(mxwait, g[ps][kt[ps]] - ps + (g[ps][kt[ps]] < ps ? n : 0));
        kt[ps]--;
        td--;
      }
      ps = (ps + 1) % n;
      mxwait = std::max(0, mxwait - 1);
      cnt++;
    }
    std::cout << cnt + add << " ";
  }
  return 0;
}
