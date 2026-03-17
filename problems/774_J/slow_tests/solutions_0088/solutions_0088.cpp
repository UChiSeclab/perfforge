#include <bits/stdc++.h>
using namespace std;
template <typename T>
T abs(T x) {
  return x > 0 ? x : -x;
}
template <typename T>
T sqr(T x) {
  return x * x;
}
bool dp[105][105][105];
int main() {
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  s.push_back('Y');
  n++;
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int gap = 0; gap <= n; gap++)
      for (int mx = 0; mx <= n; mx++) {
        if (!dp[i][gap][mx]) continue;
        if (s[i] == 'Y') {
          dp[i + 1][0][max(mx, gap)] = 1;
        }
        if (s[i] == 'N') {
          dp[i + 1][gap + 1][mx] = 1;
        }
        if (s[i] == '?') {
          dp[i + 1][0][max(mx, gap)] = 1;
          dp[i + 1][gap + 1][mx] = 1;
        }
      }
  bool ans = dp[n][0][k];
  cout << (ans ? "YES" : "NO") << "\n";
  return 0;
}
