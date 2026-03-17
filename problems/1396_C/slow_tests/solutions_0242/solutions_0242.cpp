#include <bits/stdc++.h>
using namespace std;
int n;
long long r[4], d;
vector<long long> lvl;
vector<vector<long long> > dp;
long long cal(int pos, int remain) {
  if (dp[pos][remain] == -1LL) {
    if (pos == n - 1) {
      long long p1 = (r[1] * lvl[pos]) + r[3];
      long long res =
          p1 + min(cal(pos - 1, 0) + d, cal(pos - 1, 1) + (2LL * d) + r[1]);
      long long p2 = min(r[1] * (lvl[pos] + 1LL), r[2]);
      res = min(res, p2 + cal(pos - 1, 0) + (3LL * d) + r[1]);
      res = min(res, p2 + cal(pos - 1, 1) + (3LL * d) + (2LL * r[1]));
      dp[pos][remain] = res;
    } else {
      if (remain == 0) {
        long long p1 = (r[1] * lvl[pos]) + r[3];
        long long res =
            p1 + min(cal(pos - 1, 0) + d, cal(pos - 1, 1) + (3LL * d) + r[1]);
        long long p2 = min(r[1] * (lvl[pos] + 1LL), r[2]);
        res = min(res, p2 + cal(pos - 1, 1) + (3LL * d) + (2LL * r[1]));
        dp[pos][remain] = res;
      } else {
        long long p1 = min(r[1] * (lvl[pos] + 1LL), r[2]);
        long long res = p1 + cal(pos - 1, 0) + d;
        res = min(res, cal(pos - 1, 1) + p1 + r[1] + (3LL * d));
        dp[pos][remain] = res;
      }
    }
  }
  return dp[pos][remain];
}
int main() {
  cin >> n >> r[1] >> r[2] >> r[3] >> d;
  lvl.resize(n, 0LL);
  dp.resize(n);
  for (int i = 0; i < n; i++) {
    dp[i].resize(2, -1LL);
    cin >> lvl[i];
  }
  dp[0][0] = (r[1] * lvl[0]) + r[3];
  dp[0][1] = min(r[1] * (lvl[0] + 1LL), r[2]);
  cout << cal(n - 1, 0) << endl;
}
