#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using ulint = unsigned long long;
const int N = 500 + 1;
const int K = 10 + 1;
int h[K];
int dp[N * K];
int n, k;
int solve(int p, int c) {
  if (p == 0 || c == 0) {
    return 0;
  }
  fill(begin(dp), end(dp), 0);
  while (p--) {
    for (int i = 0; i <= c; i++) {
      for (int j = 0; j <= k; j++) {
        if (i >= j) {
          dp[i - j] = max(dp[i - j], dp[i] + h[j]);
        }
      }
    }
  }
  return *max_element(begin(dp), end(dp));
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  map<int, int> fav, cnt;
  for (int i = 0; i < n * k; i++) {
    int c;
    cin >> c;
    cnt[c]++;
  }
  for (int i = 0; i < n; i++) {
    int f;
    cin >> f;
    fav[f]++;
  }
  for (int i = 1; i <= k; i++) {
    cin >> h[i];
  }
  int ans = 0;
  for (auto e : fav) {
    ans += solve(e.second, cnt[e.first]);
  }
  cout << ans << endl;
}
