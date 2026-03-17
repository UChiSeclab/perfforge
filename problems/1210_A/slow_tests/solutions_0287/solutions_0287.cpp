#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> gs;
int main() {
  gs.clear();
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int a, b;
    cin >> a >> b;
    gs.push_back(make_pair(a, b));
  }
  int cs[8];
  int ans = 0;
  for (int a = 1; a <= 6; ++a) {
    for (int b = 1; b <= 6; ++b) {
      for (int c = 1; c <= 6; ++c) {
        for (int d = 1; d <= 6; ++d) {
          for (int e = 1; e <= 6; ++e) {
            for (int f = 1; f <= 6; ++f) {
              for (int g = 1; g <= 6; ++g) {
                cs[1] = a;
                cs[2] = b;
                cs[3] = c;
                cs[4] = d;
                cs[5] = e;
                cs[6] = f;
                cs[7] = g;
                int tot = 0;
                set<pair<int, int>> vis;
                vis.clear();
                for (int i = 0; i < gs.size(); ++i) {
                  int u = gs[i].first;
                  int v = gs[i].second;
                  if (cs[u] > cs[v]) swap(u, v);
                  if (vis.find(make_pair(cs[u], cs[v])) == vis.end()) {
                    tot++;
                    vis.insert(make_pair(cs[u], cs[v]));
                  }
                }
                ans = max(ans, tot);
              }
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
