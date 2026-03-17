#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, long long> a, pair<int, long long> b) {
  return a.second / a.first > b.second / b.first;
}
int main() {
  int n, m, w, l, r;
  long long c, dp[300500], mx;
  cin >> n >> m;
  vector<pair<int, long long>> t(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%I64d", &w, &c);
    t[i] = make_pair(w, c);
  }
  sort(t.begin(), t.end(), cmp);
  memset(dp, 0, sizeof(dp));
  r = 0;
  for (int i = 0; i < n; ++i) {
    r = min(r + t[i].first, m);
    l = max(t[i].first, r - 6);
    for (int j = r; j >= l; --j) {
      dp[j] = max(dp[j], dp[j - t[i].first] + t[i].second);
    }
  }
  mx = 0;
  for (int i = 0; i <= m; ++i) {
    mx = max(mx, dp[i]);
  }
  cout << mx << endl;
  return 0;
}
