#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline long long fpow(long long di, long long top) {
  long long ret = 1;
  while (top) {
    if (top % 2) ret = ret * di % mod;
    top /= 2, di = di * di % mod;
  }
  return ret;
}
inline long long inv(int k) { return (int)fpow(k, mod - 2); }
struct node {
  int x, y, val;
  bool operator<(const node &a) const { return val < a.val; }
};
node sth[1000010];
vector<node> nt;
int n, m, nval, scnt;
long long xsum, ysum, xss, yss;
long long pans, pcnt;
long long dp[1010][1010];
int l, r;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &nval);
      sth[++scnt] = (node){i, j, nval};
    }
  }
  sort(sth + 1, sth + scnt + 1), sth[scnt + 1].val = -998244353;
  int nl = 1;
  while (nl <= scnt) {
    int las = 0, nval = 1900000000;
    nt.clear();
    for (int i = nl; i <= scnt + 1; ++i) {
      nl = i;
      if (sth[i].val > nval || i > scnt) break;
      nt.push_back(sth[i]), nval = sth[i].val;
    }
    for (int i = 0; i < nt.size(); ++i) {
      node nk = nt[i];
      long long xdis = xss + 1ll * pcnt * nk.x * nk.x - 1ll * 2 * xsum * nk.x;
      xdis %= mod, xdis += mod, xdis %= mod;
      long long ydis = yss + 1ll * pcnt * nk.y * nk.y - 1ll * 2 * ysum * nk.y;
      ydis %= mod, ydis += mod, ydis %= mod;
      dp[nk.x][nk.y] += (xdis + ydis);
      dp[nk.x][nk.y] += pans;
      dp[nk.x][nk.y] %= mod;
      dp[nk.x][nk.y] *= inv(pcnt);
      dp[nk.x][nk.y] %= mod;
    }
    for (int i = 0; i < nt.size(); ++i) {
      node nk = nt[i];
      xsum += nk.x, ysum += nk.y;
      xss += 1ll * nk.x * nk.x, yss += 1ll * nk.y * nk.y;
      pans += dp[nk.x][nk.y], pcnt++;
      xsum %= mod, ysum %= mod, xss %= mod, yss %= mod, pans %= mod;
    }
  }
  cin >> l >> r;
  cout << dp[l][r];
  return 0;
}
