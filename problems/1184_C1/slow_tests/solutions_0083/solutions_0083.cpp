#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int mod = 1e9 + 7;
struct pt {
  int x, y;
};
pt ans = {-1, -1};
bool chk(pt a, pt b, pt c) {
  if (a.x == b.x)
    return c.x == a.x && c.y >= min(a.y, b.y) && c.y <= max(a.y, b.y);
  return c.y == a.y && c.x >= min(a.x, b.x) && c.x <= max(a.x, b.x);
}
void solve(int x, int y, int sz, vector<pt>& p) {
  pt a = {x, y}, b = {x + sz, y}, c = {x + sz, y + sz}, d = {x, y + sz};
  int cnt1 = 0, cnt2 = 0;
  pt t;
  for (pt i : p) {
    int cnt = chk(a, b, i) + chk(b, c, i) + chk(c, d, i) + chk(d, a, i);
    if (cnt)
      cnt1++;
    else {
      cnt2++;
      t = i;
    }
  }
  if (cnt2 == 1) ans = t;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<pt> a(4 * n + 1);
  for (pt& i : a) cin >> i.x >> i.y;
  for (int i = 0; i <= 50; i++) {
    for (int j = 0; j <= 50; j++) {
      for (int sz = 1; sz <= 50; sz++) {
        solve(i, j, sz, a);
        if (ans.x != -1) {
          cout << ans.x << " " << ans.y << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}
