#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
void solve() {
  long long int n, k, l;
  cin >> n >> k >> l;
  vector<long long int> d(n + 1);
  for (long long int i = 0; i < n; i++) cin >> d[i];
  d[n] = -INT_MAX;
  vector<long long int> p(2 * k);
  for (long long int i = 0; i < 2 * k; i++) {
    if (i <= k)
      p[i] = i;
    else
      p[i] = 2 * k - i;
  }
  map<pair<long long int, long long int>, bool> visited;
  bool ok = false;
  function<void(long long int, long long int)> dfs = [&](long long int i,
                                                         long long int state) {
    if (i == n) {
      ok = true;
      return;
    }
    long long int t = state;
    while ((d[i] + p[state % (2 * k)] <= l) && ((state - t) <= 2 * k)) {
      if (!visited[{i, state}]) {
        dfs(i + 1, state + 1);
        visited[{i, state}] = true;
      }
      state++;
    }
  };
  for (long long int j = 0; j < 2 * k; j++) {
    if (d[0] + p[j] <= l) {
      dfs(1, j + 1);
    }
  }
  if (ok)
    cout << "Yes";
  else
    cout << "No";
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
