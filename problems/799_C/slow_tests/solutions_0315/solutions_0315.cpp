#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, k, ans = 0, za, ma, xi = -1, yi = -1, q, ma1 = -1, ma2 = -1, x,
                   y, c, d, in;
vector<pair<int, int> > vx[2];
char ch;
int func(int p) {
  if (p == 0) {
    in = c;
  } else {
    in = d;
  }
  q = -1;
  m = vx[p].size();
  multiset<int> mu;
  multiset<int>::iterator it;
  for (i = 1; i < m; i++) {
    x = vx[p][i].first;
    y = vx[p][i].second;
    if (x == vx[p][i - 1].first && 2 * x <= in) {
      q = max(q, y + vx[p][i - 1].second);
    }
  }
  for (i = 0; i < m; i++) {
    x = vx[p][i].first;
    y = vx[p][i].second;
    if (2 * x <= in) {
      mu.insert(y);
    }
  }
  if (mu.size() > 1) {
    it = mu.end();
    it--;
    x = *it;
    it--;
    y = *it;
    q = max(q, x + y);
  }
  int dp[100005] = {0};
  for (i = 0; i < m; i++) {
    x = vx[p][i].first;
    y = vx[p][i].second;
    dp[x] = max(dp[x], y);
  }
  for (i = 1; 2 * i <= in; i++) {
    dp[i] = max(dp[i], dp[i - 1]);
  }
  for (i = in; i > 0; i--) {
    j = in - i;
    if (dp[i] > 0 && dp[j] > 0 && i != j) {
      q = max(q, dp[i] + dp[j]);
    }
  }
  return q;
}
int main() {
  cin >> n >> c >> d;
  for (i = 0; i < n; i++) {
    cin >> x >> y >> ch;
    if (ch == 'C') {
      vx[0].push_back(make_pair(y, x));
    } else {
      vx[1].push_back(make_pair(y, x));
    }
  }
  sort(vx[0].begin(), vx[0].end());
  sort(vx[1].begin(), vx[1].end());
  for (i = 0; i < vx[0].size(); i++) {
    x = vx[0][i].first;
    y = vx[0][i].second;
    if (x <= c) {
      xi = max(xi, y);
    }
  }
  for (i = 0; i < vx[1].size(); i++) {
    x = vx[1][i].first;
    y = vx[1][i].second;
    if (x <= d) {
      yi = max(yi, y);
    }
  }
  za = func(0);
  ma = max(ma, za);
  za = func(1);
  ma = max(ma, za);
  if (ma == -1) {
    if (xi == -1 || yi == -1) {
      cout << "0";
    } else {
      cout << xi + yi;
    }
  } else {
    if (xi == -1 || yi == -1) {
      cout << ma;
    } else {
      cout << max(ma, xi + yi);
    }
  }
  return 0;
}
