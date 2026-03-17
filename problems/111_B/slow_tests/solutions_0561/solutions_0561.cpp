#include <bits/stdc++.h>
using namespace std;
using namespace std;
map<int, set<int> > m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    int ans = 0;
    for (int j = 1; j * j <= x; ++j) {
      if (x % j == 0 && j * j != x) {
        if (m[j].upper_bound(i - y - 1) == m[j].end()) {
          ++ans;
        }
        if (m[x / j].upper_bound(i - y - 1) == m[x / j].end()) {
          ++ans;
        }
      } else if (x % j == 0) {
        if (m[j].upper_bound(i - y - 1) == m[j].end()) {
          ++ans;
        }
      }
    }
    for (int j = 1; j * j <= x; ++j) {
      if (x % j == 0) {
        m[j].insert(i);
        m[x / j].insert(i);
      }
    }
    cout << ans << '\n';
  }
}
