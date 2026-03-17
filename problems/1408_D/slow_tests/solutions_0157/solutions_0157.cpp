#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
const int M = 22;
const long long mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
int a[N];
int b[N];
int c[N];
int d[N];
int lg[N];
int dp[N][M];
vector<pair<int, int> > v;
int get(int l, int r) {
  int x = lg[r - l + 1];
  return max(dp[l][x], dp[r - (1 << x) + 1][x]);
}
int can(int x) {
  int l = 0, r = (int)v.size() - 1;
  while (l < r) {
    int m = (l + r) / 2;
    if (v[m + 1].first > x)
      r = m;
    else
      l = m + 1;
  }
  if (v[l].first > x) {
    return x + get(l, (int)v.size() - 1);
  }
  if (v[(int)v.size() - 1].first <= x) {
    return x;
  } else {
    return x + get(l + 1, (int)v.size() - 1);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> c[i] >> d[i];
  }
  int ans = 1e9;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i] <= c[j] && b[i] <= d[j]) {
        v.push_back({c[j] - a[i] + 1, d[j] - b[i] + 1});
      }
    }
  }
  if (v.empty()) {
    cout << 0;
    return 0;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < (int)v.size(); i++) {
    dp[i][0] = v[i].second;
  }
  int mn = (int)v.size();
  for (int i = 1; i < M; i++) {
    for (int j = 0; j + (1 << i) - 1 < mn; j++) {
      dp[j][i] = max(dp[j][i - 1], dp[j + (1 << i - 1)][i - 1]);
    }
  }
  for (int i = 2; i < N; i++) {
    lg[i] = lg[i / 2] + 1;
  }
  for (int i = 0; i <= 1e6 + 1; i++) {
    ans = min(ans, can(i));
  }
  cout << ans;
}
