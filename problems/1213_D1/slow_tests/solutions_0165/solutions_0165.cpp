#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  vector<int> res;
  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    int x = v[i];
    while (x > 0) {
      res.push_back(x);
      x /= 2;
    }
  }
  for (auto x : res) {
    vector<int> cnt;
    for (int i = 0; i < n; i++) {
      int r = 0;
      int cur = 0;
      int p = v[i];
      while (p > x) {
        p /= 2;
        cur++;
      }
      if (p == x) cnt.push_back(cur);
    }
    if (cnt.size() >= k) {
      sort(cnt.begin(), cnt.end());
      ans = min(ans, accumulate(cnt.begin(), cnt.begin() + k, 0));
    }
  }
  cout << ans << "\n";
}
