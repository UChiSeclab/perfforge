#include <bits/stdc++.h>
#pragma GCC optimize "-O3"
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using namespace std;
int dg[20];
int a[7];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  set<pair<int, int>> e;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    e.emplace(u, v);
  }
  int ans = 0;
  for (a[0] = 0; a[0] < 6; a[0]++) {
    for (a[1] = 0; a[1] < 6; a[1]++) {
      for (a[2] = 0; a[2] < 6; a[2]++) {
        for (a[3] = 0; a[3] < 6; a[3]++) {
          for (a[4] = 0; a[4] < 6; a[4]++) {
            for (a[5] = 0; a[5] < 6; a[5]++) {
              for (a[6] = 0; a[6] < 6; a[6]++) {
                set<pair<int, int>> gao;
                for (auto ed : e) {
                  int u = a[ed.first], v = a[ed.second];
                  if (u > v) {
                    swap(u, v);
                  }
                  gao.emplace(u, v);
                  ans = max(ans, (int)gao.size());
                }
              }
            }
          }
        }
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
