#include <bits/stdc++.h>
using namespace std;
const unsigned long long int INF = 10e8;
struct pt {
  double x;
  double y;
};
vector<unsigned long long int> dp;
unsigned long long int f(pt t) {
  int x = (int)t.x;
  int y = (int)t.y;
  unsigned long long int res(0);
  unsigned long long int st(0);
  for (int i(0); i <= y; i++) {
    res += dp[x] + (x + 1) * st;
    st++;
  }
  return res;
}
bool solve() {
  double m, b;
  cin >> m >> b;
  pt ox, oy;
  ox.x = b * m;
  ox.y = 0;
  oy.x = 0;
  oy.y = b;
  dp.resize(ox.x + 1);
  unsigned long long int cr(0);
  for (int i(0); i < dp.size(); i++) {
    cr += i;
    dp[i] = cr;
  }
  pt tmp;
  unsigned long long int ans(0);
  for (int i(0); i <= b; i++) {
    tmp.x = (b - i) * m;
    tmp.y = i;
    ans = max(ans, f(tmp));
  }
  cout << ans;
  return 1;
}
int main() {
  solve();
  return 0;
}
