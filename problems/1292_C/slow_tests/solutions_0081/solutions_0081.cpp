#include <bits/stdc++.h>
using namespace std;
int n, s[4000];
long long dp[4000][4000];
vector<int> e[4000];
void dfss(int i = 0, int p = -1) {
  s[i] = 1;
  for (int j : e[i])
    if (j != p) dfss(j, i), s[i] += s[j];
}
long long dfs(int k, int i, int pi, int j, int pj) {
  if (dp[i][j] != -1) return dp[i][j];
  long long ss = 0;
  for (int o : e[i]) {
    if (o == pi) continue;
    long long ssh = s[o] * s[j];
    ssh += dfs(k + 1, o, i, j, pj);
    ss = max(ss, ssh);
  }
  for (int o : e[j]) {
    if (o == pj) continue;
    long long ssh = s[o] * s[i];
    ssh += dfs(k + 1, i, pi, o, j);
    ss = max(ss, ssh);
  }
  return dp[i][j] = ss;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n;
  int a, b;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) dp[i][j] = -1;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b, a--, b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  long long r = 0;
  for (int i = 0; i < n; i++) {
    for (int j : e[i]) {
      dfss(i, j);
      dfss(j, i);
      r = max(r, dfs(1, i, j, j, i) + s[i] * s[j]);
    }
  }
  cout << r << "\n";
}
