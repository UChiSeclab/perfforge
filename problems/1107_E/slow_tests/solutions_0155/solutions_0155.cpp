#include <bits/stdc++.h>
using namespace std;
template <class T>
void minn(T &a, T b) {
  a = min(a, b);
}
template <class T>
void maxx(T &a, T b) {
  a = max(a, b);
}
void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
const long long MOD = 1000000007LL;
const long long PRIME = 105943LL;
const long long INF = 1e18;
int n;
string s;
long long a[101];
long long ans[100][100];
long long dp[100][100][2][101];
long long fans(int l, int r);
long long fdp(int l, int r, int t, int c);
long long fans(int l, int r) {
  if (l > r) return 0;
  long long &best = ans[l][r];
  if (best != 0x3F3F3F3F3F3F3F3F) return best;
  best = -INF;
  for (int c = 1; c <= (int)r - l + 1; c++)
    for (int t = 0; t < (int)(2); t++) maxx(best, fdp(l, r, t, c) + a[c]);
  return best;
}
long long fdp(int l, int r, int t, int c) {
  if (c == 0) return fans(l, r);
  if (l > r) return -INF;
  int psz = 0;
  for (int i = l; i <= (int)r; i++)
    if (s[i] == t + '0') psz++;
  if (c > psz) return -INF;
  long long &best = dp[l][r][t][c];
  if (best != 0x3F3F3F3F3F3F3F3F) return best;
  best = -INF;
  for (int m = l; m <= (int)r; m++)
    if (s[m] == t + '0') maxx(best, fans(l, m - 1) + fdp(m + 1, r, t, c - 1));
  return best;
}
int main() {
  io();
  cin >> n >> s;
  for (int i = 1; i <= (int)n; i++) cin >> a[i];
  memset(ans, 0x3F3F3F3F3F3F3F3F, sizeof ans);
  memset(dp, 0x3F3F3F3F3F3F3F3F, sizeof dp);
  cout << fans(0, n - 1) << "\n";
}
