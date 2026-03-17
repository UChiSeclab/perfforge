#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int dp[1000002][9];
int best[1000002][9][2];
int cal(int l, int nd) {
  if (dp[l][nd] != -1) return dp[l][nd];
  int i, mx, ind, il, in, nl;
  if (l < v[nd]) {
    dp[l][nd] = 0;
    return dp[l][nd];
  }
  nl = l - v[nd];
  mx = 1 + cal(nl, 8);
  il = nl;
  in = 8;
  for (i = 7; i >= 0; i--) {
    if (mx < 1 + cal(nl, i)) {
      mx = 1 + cal(nl, i);
      il = nl;
      in = i;
    }
  }
  best[l][nd][0] = il;
  best[l][nd][1] = in;
  dp[l][nd] = mx;
  return dp[l][nd];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, tem, m, mx, il, in, j;
  cin >> m;
  for (i = 0; i < 9; i++) {
    cin >> tem;
    v.emplace_back(tem);
  }
  for (i = 0; i <= m; i++) {
    for (j = 0; j < 9; j++) {
      dp[i][j] = -1;
      best[i][j][0] = -1;
      best[i][j][1] = -1;
    }
  }
  mx = cal(m, 8);
  il = m;
  in = 8;
  for (i = 7; i >= 0; i--) {
    if (mx < cal(m, i)) {
      mx = cal(m, i);
      il = m;
      in = i;
    }
  }
  if (mx == 0)
    cout << -1;
  else {
    for (i = 0; i < mx; i++) {
      cout << in + 1;
      int tl = il;
      int tn = in;
      il = best[tl][tn][0];
      in = best[tl][tn][1];
    }
  }
  return 0;
}
