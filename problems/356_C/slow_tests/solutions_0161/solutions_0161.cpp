#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  map<int, int> c;
  int ans = 0;
  for (int i = 0, v; i < n; ++i) {
    cin >> v;
    ++c[v];
  }
  int t;
  t = min(c[1], c[2]);
  c[1] -= t, c[2] -= t;
  c[3] += t;
  ans += t;
  if (c[2] == 0 && c[1] == 0) {
    cout << ans;
    return 0;
  }
  if (c[2] == 0) {
    t = c[1] / 3;
    c[3] += t;
    c[1] %= 3;
    ans += 2 * t;
    if (c[1] != 0) {
      t = min(c[1] / 2, c[4]);
      c[3] += t;
      c[4] -= t;
      c[1] -= t * 2;
      ans += t * 2;
      t = min(c[1], c[3]);
      c[4] += t;
      c[1] -= t;
      c[3] -= t;
      ans += t;
      t = min(c[4] / 2, c[1]);
      c[1] -= t;
      c[4] -= 2 * t;
      c[3] += t;
      ans += t * 2;
    }
  } else {
    t = c[2] / 3;
    c[3] += 2 * t;
    c[2] %= 3;
    ans += 2 * t;
    if (c[2] != 0) {
      t = c[2] / 2;
      c[4] += t;
      c[2] -= t * 2;
      ans += t * 2;
      t = min(c[2], c[4]);
      ans += t;
      c[4] -= t, c[2] -= t;
      c[3] += t;
      t = min(c[2], c[3] / 2);
      ans += 2 * t;
      c[4] += 2 * t;
      c[3] -= 2 * t;
      c[2] -= t;
    }
  }
  if (c[1] != 0 || c[2] != 0) {
    ans = -1;
  }
  cout << ans;
  return 0;
}
