#include <bits/stdc++.h>
using namespace std;
int find(vector<int> &v) {
  for (int i = 0; i < v.size(); ++i)
    if (v[i]) return i;
  return 0;
}
int main() {
  int n, x, y;
  while (cin >> n >> x >> y) {
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    if (x > y)
      cout << n << '\n';
    else {
      int lim = 5 * 1e5;
      while (lim-- > 0) {
        sort(v.begin(), v.end());
        int ind = find(v);
        for (int i = ind; i < n; ++i) {
          if (v[i] > v[ind] && v[i] <= x) {
            ind = i;
          }
        }
        v[ind] = max(0, v[ind] - x);
        sort(v.begin(), v.end());
        ind = find(v);
        if (v[ind]) {
          v[ind] += y;
        }
      }
      int ans = 0;
      for (int i = 0; i < n; ++i) {
        ans += (v[i] == 0);
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
