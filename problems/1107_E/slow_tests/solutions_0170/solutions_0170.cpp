#include <bits/stdc++.h>
using namespace std;
const int N = 102;
const long long INF = 1e12;
int n;
string s;
int a[N];
long long ans[N][N];
long long dp[2][N][N][N];
long long calcDp(int c, int l, int r, int cnt);
long long calcAns(int l, int r) {
  if (l >= r) return 0;
  long long &res = ans[l][r];
  if (res != -1) return res;
  res = 0;
  for (int cnt = 1; cnt <= r - l; ++cnt) {
    res = max(res, calcDp(0, l, r, cnt) + a[cnt - 1]);
    res = max(res, calcDp(1, l, r, cnt) + a[cnt - 1]);
  }
  return res;
}
long long calcDp(int c, int l, int r, int cnt) {
  if (cnt == 0) return calcAns(l, r);
  long long &res = dp[c][l][r][cnt];
  if (res != -1) return res;
  res = -INF;
  for (int i = l; i < r; ++i) {
    if (c == s[i] - '0')
      res = max(res, calcAns(l, i) + calcDp(c, i + 1, r, cnt - 1));
  }
  return res;
}
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; ++i) cin >> a[i];
  memset(dp, -1, sizeof dp);
  memset(ans, -1, sizeof ans);
  cout << calcAns(0, n) << endl;
  return 0;
}
