#include <bits/stdc++.h>
using namespace std;
const int N = 105, M = 1e5 + 5;
int n, k, taste[N], cal[N];
map<pair<int, int>, int> dp;
int solve(int i, int ratio) {
  if (i == n) {
    if (!ratio) return 0;
    return -1e9;
  }
  if (dp.find({i, ratio}) != dp.end()) return dp[{i, ratio}];
  int ch1 = solve(i + 1, ratio);
  int ch2 = solve(i + 1, ratio + k * cal[i] - taste[i]) + taste[i];
  return dp[{i, ratio}] = max(ch1, ch2);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> taste[i];
  for (int i = 0; i < n; i++) cin >> cal[i];
  int ans = solve(0, 0);
  if (ans <= 0) ans = -1;
  cout << ans << "\n";
  ;
  return 0;
}
