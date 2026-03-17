#include <bits/stdc++.h>
using namespace std;
int dp[1000];
int here[1000][1000];
int solve(string s) {
  memset(dp, 0, sizeof(dp));
  dp[0] = (s[0] == 'N');
  for (int i = int(1); i < int(int((s).size())); ++i) {
    if (s[i] != 'N')
      dp[i] = 0;
    else
      dp[i] = dp[i - 1] + 1;
  }
  int mx = 0;
  for (int i = int(0); i < int(int((s).size())); ++i) mx = max(mx, dp[i]);
  return mx;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int mn = solve(s);
  if (k < mn) {
    cout << "NO" << endl;
    return 0;
  }
  if (k == 0) {
    cout << "YES" << endl;
    return 0;
  }
  bool find = false;
  s.push_back('Y');
  for (int i = int(0); i < int(n); ++i)
    for (int tam = int(1); tam < int(i + 2); ++tam) {
      if (s[i + 1] == 'N') continue;
      here[i][tam] = true;
      for (int j = int(i - tam + 1); j < int(i + 1); ++j)
        if (s[j] == 'Y') here[i][tam] = false;
      if (i - tam >= 0 && s[i - tam] == 'N') here[i][tam] = false;
      if (tam == k && here[i][tam]) find = true;
    }
  if (find)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
