#include <bits/stdc++.h>
using namespace std;
void guan() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const int maxn = 100010;
const long long mod = 1e9 + 7;
const double pi = acos(-1.0);
const long long maxx = 1LL << 61;
const double eps = 1e-7;
int n, k;
inline int read() { return cin >> n >> k ? 1 : 0; }
int dp[510][12][5100];
int h[555], f[555];
map<int, int> cnt;
map<int, int> p;
void init() {
  int tk = k;
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i <= 10; i++) dp[0][i][0] = 0;
  for (int i = 1; i <= 505; i++) {
    for (int k = 1; k <= 5010; ++k) {
      for (int j = 1; j <= tk; j++) {
        int maxx = 0;
        if (j > k) break;
        for (int q = 1; q <= j; q++) {
          maxx = max(dp[i - 1][q][k - j], maxx);
        }
        dp[i][j][k] = h[j] + maxx;
      }
    }
  }
}
void solve() {
  for (int i = 1; i <= k * n; i++) {
    int t;
    cin >> t;
    cnt[t]++;
  }
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
    p[f[i]]++;
  }
  for (int i = 1; i <= k; i++) cin >> h[i];
  init();
  int ans = 0;
  for (map<int, int>::iterator it = p.begin(); it != p.end(); ++it) {
    int nump = it->second, sum = cnt[it->first];
    sum = min(sum, nump * k);
    int maxx = 0;
    for (int i = 1; i <= k; i++) {
      maxx = max(maxx, dp[nump][i][sum]);
    }
    ans += maxx;
  }
  cout << ans << endl;
}
int main() {
  guan();
  int t = 1;
  while (t--) {
    while (read()) solve();
  }
  return 0;
}
