#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
const int mod = 1e9 + 7;
int dcmp(long double x, long double y) {
  return fabs(x - y) <= 1e-12 ? 0 : x < y ? -1 : 1;
}
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
int n, m;
vector<long long> pre[4];
long long dp[30 * 100 * 100 + 5];
int cnt1[30 * 100 * 100 + 5], cnt2[30 * 100 * 100 + 5];
int main() {
  fast();
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    pre[x].push_back(y);
  }
  for (int i = 0; i < 4; i++) {
    sort(pre[i].rbegin(), pre[i].rend());
  }
  if (pre[1].size()) {
    dp[1] = pre[1][0];
    cnt1[1] = 1;
  }
  for (int i = 2; i < 30 * 100 * 100 + 5; i++) {
    int idxa = cnt1[i - 1], idxb = cnt2[i - 2];
    if (idxa < pre[1].size()) {
      if (dp[i] < dp[i - 1] + pre[1][idxa]) {
        dp[i] = dp[i - 1] + pre[1][idxa];
        cnt1[i] = 1 + idxa;
        cnt2[i] = cnt2[i - 1];
      }
    }
    if (idxb < pre[2].size()) {
      if (dp[i] < dp[i - 2] + pre[2][idxb]) {
        dp[i] = dp[i - 2] + pre[2][idxb];
        cnt1[i] = cnt1[i - 2];
        cnt2[i] = 1 + idxb;
      }
    }
  }
  for (int i = 1; i < 30 * 100 * 100 + 5; i++) dp[i] = max(dp[i - 1], dp[i]);
  long long ans = dp[m], tot = 0, idxc = 0;
  while (m >= 0) {
    ans = max(ans, dp[m] + tot);
    m -= 3;
    if (idxc < pre[3].size()) tot += pre[3][idxc++];
  }
  cout << ans << '\n';
  return 0;
}
