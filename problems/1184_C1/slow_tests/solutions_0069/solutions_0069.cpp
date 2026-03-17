#include <bits/stdc++.h>
using namespace std;
long long inf = 4e18, mod = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<pair<long long, long long> > v;
  for (int i = 1; i <= 4 * n + 1; i++) {
    int x, y;
    cin >> x >> y;
    v.push_back({x, y});
  }
  for (int lx = 0; lx <= 50; lx++) {
    for (int ly = 0; ly <= 50; ly++) {
      for (int ux = lx + 1; ux <= 50; ux++) {
        for (int uy = ly + 1; uy <= 50; uy++) {
          vector<pair<long long, long long> > res;
          for (auto it : v)
            if ((it.first == lx || it.first == ux) && it.second >= ly &&
                it.second <= uy) {
            } else if ((it.second == ly || it.second == uy) && it.first >= lx &&
                       it.first <= ux) {
            } else
              res.push_back(it);
          if (res.size() == 1) {
            cout << res[0].first << " " << res[0].second << endl;
            return;
          }
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) solve();
}
