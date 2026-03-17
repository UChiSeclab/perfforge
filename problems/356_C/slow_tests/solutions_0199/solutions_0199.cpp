#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
int res;
int ct[5];
int dp[32][32][32][32];
int calc(int c1, int c2, int c3, int c4) {
  if (c1 == 0 && c2 == 0) return 0;
  if (c1 + c2 * 2 + c3 * 3 + c4 * 4 < 3) return oo;
  if (dp[c1][c2][c3][c4] == -1) {
    if (c1 >= 32) return oo;
    int& cr = dp[c1][c2][c3][c4];
    cr = oo;
    if (c1 >= 4) cr = min(cr, 3 + calc(c1 - 4, c2, c3, c4));
    if (c1 >= 3) cr = min(cr, 2 + calc(c1 - 3, c2, c3, c3));
    if (c1 >= 2 && c2 >= 1) cr = min(cr, 2 + calc(c1 - 2, c2 - 1, c3, c4));
    if (c1 >= 1 && c2 >= 1) cr = min(cr, 1 + calc(c1 - 1, c2 - 1, c3, c4));
    if (c1 >= 1 && c3 >= 1) cr = min(cr, 1 + calc(c1 - 1, c2, c3 - 1, c4));
    if (c2 >= 1 && c3 >= 1) cr = min(cr, 1 + calc(c1 + 1, c2 - 1, c3 - 1, c4));
    if (c2 >= 2) cr = min(cr, 2 + calc(c1, c2 - 2, c3, c4));
    if (c2 >= 3) cr = min(cr, 2 + calc(c1, c2 - 3, c3, c4));
    if (c2 >= 1 && c4 >= 1) cr = min(cr, 1 + calc(c1, c2 - 1, c3, c4 - 1));
    if (c1 >= 2 && c4 >= 1) cr = min(cr, 2 + calc(c1 - 2, c2, c3, c4 - 1));
    if (c1 >= 1 && c4 >= 2) cr = min(cr, 2 + calc(c1 - 1, c2, c3, c4 - 2));
  }
  return dp[c1][c2][c3][c4];
}
int main() {
  int N;
  cin >> N;
  for (int i = (0); i < (5); i++) ct[i] = 0;
  while (N--) {
    int t;
    cin >> t;
    ct[t]++;
  }
  res = 0;
  while (ct[1] > 5 && ct[2] > 0) {
    ++res;
    --ct[1];
    --ct[2];
    ++ct[3];
  }
  while (ct[1] > 20) {
    res += 2;
    ct[1] -= 3;
    ct[3]++;
  }
  while (ct[2] > 30) {
    res += 2;
    ct[2] -= 3;
  }
  memset(dp, -1, sizeof(dp));
  res += calc(ct[1], ct[2], min(ct[3], 30), min(ct[4], 30));
  if (res >= oo)
    cout << -1 << endl;
  else
    cout << res << endl;
  return 0;
}
