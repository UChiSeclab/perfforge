#include <bits/stdc++.h>
using namespace std;
long long INF = 1 << 28;
const double pi = acos(-1.0);
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
int dir[4][2] = {1, 0, -1, 0, 0, -1, 0, 1};
int knight[8][2] = {1, 2, 1, -2, 2, 1, 2, -1, -1, 2, -1, -2, -2, 1, -2, -1};
const long double EPS = 1e-7;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
bool cmp(int a, int b) { return a < b; }
int on(int mask, int st) { return mask | (1 << st); }
int off(int mask, int st) { return mask & (~(1 << st)); }
bool check(int mask, int st) { return mask & (1 << st); }
long long inf = 1e18;
long long MOD = 1e9 + 7;
long long mod = 1e9;
int n, m;
int koto[200];
int element[200][200];
long long pre[200][200];
long long dp[110][10010];
long long fun(int pos, int k) {
  if (k == 0) {
    return 0;
  }
  if (pos == n) {
    return 0;
  }
  long long &ret = dp[pos][k];
  if (ret != -1) return ret;
  long long ans = 0;
  for (int i = 0; i <= min(k, koto[pos]); i++) {
    ans = max(ans, pre[pos][i] + fun(pos + 1, k - i));
  }
  return ret = ans;
}
int predp[101][101][101];
int row;
int funpre(int l, int r, int k) {
  if (l > r) return 0;
  if (k == 0) {
    return 0;
  }
  int &ret = predp[l][r][k];
  if (ret != -1) return ret;
  int ans = 0;
  ans = max(ans, element[row][l] + funpre(l + 1, r, k - 1));
  ans = max(ans, element[row][r] + funpre(l, r - 1, k - 1));
  return ret = ans;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &koto[i]);
    for (int j = 0; j < koto[i]; j++) {
      scanf("%d", &element[i][j]);
    }
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int c = 0;
    sum = 0;
    memset(predp, -1, sizeof(predp));
    row = i;
    for (int j = 0; j <= koto[i]; j++) {
      pre[i][j] = funpre(0, koto[i] - 1, j);
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << fun(0, m) << endl;
  return 0;
}
