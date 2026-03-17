#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long dp[51][2051];
long long a[100];
void go() {
  long long n, s, k;
  cin >> n >> s >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  memset(dp, -1, sizeof(dp));
  string color;
  cin >> color;
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 greater<pair<long long, long long>>>
      q;
  for (long long i = 1; i <= n; i++) {
    q.push({abs(i - s), i});
    dp[i][abs(i - s)] = a[i];
  }
  while (!q.empty()) {
    long long sec = q.top().first;
    long long pos = q.top().second;
    q.pop();
    if (dp[pos][sec] >= k) {
      cout << sec;
      return;
    }
    for (long long i = 1; i <= n; i++) {
      if (a[i] > a[pos] && color[pos - 1] != color[i - 1] &&
          dp[i][sec + abs(i - pos)] < dp[pos][sec] + a[i]) {
        q.push({sec + abs(i - pos), i});
        dp[i][sec + abs(i - pos)] = dp[pos][sec] + a[i];
      }
    }
  }
  cout << -1 << endl;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long t = 1;
  cout << fixed << setprecision(12);
  while (t--) {
    go();
  }
}
