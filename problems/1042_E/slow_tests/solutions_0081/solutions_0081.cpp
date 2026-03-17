#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const int INFI = 1000 * 1000 * 1000;
const long long INFL = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;
const int MX_N = 1002;
const long long MOD = 998244353;
int N, M;
long long board[MX_N][MX_N];
long long dp[MX_N][MX_N];
long long fexp(long long a, long long x, long long mod) {
  if (x == 0LL) return 1ll;
  if (x % 2LL == 0) {
    long long y = fexp(a, x / 2, mod);
    return (y * y) % mod;
  }
  return (a * fexp(a, x - 1, mod)) % mod;
}
long long divv(long long a, long long b, long long mod) {
  return (a * fexp(b, mod - 2, mod)) % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j) cin >> board[i][j];
  vector<pair<int, int> > prs;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j) prs.push_back({i, j});
  sort(prs.begin(), prs.end(),
       [](const pair<int, int>& a, const pair<int, int>& b) {
         return board[a.first][a.second] < board[b.first][b.second];
       });
  long long sz = 0;
  long long nsz = 0;
  long long xsm, x2sm, ysm, y2sm;
  xsm = x2sm = ysm = y2sm = 0;
  long long nxsm, nx2sm, nysm, ny2sm;
  nxsm = nx2sm = nysm = ny2sm = 0;
  long long prv = -1;
  long long dpsm, ndpsm;
  dpsm = ndpsm = 0;
  long long x, y;
  for (const auto& i : prs) {
    x = i.first, y = i.second;
    if (board[x][y] != prv) {
      sz = nsz;
      xsm = nxsm;
      x2sm = nx2sm;
      ysm = nysm;
      y2sm = ny2sm;
      dpsm = ndpsm;
      prv = board[x][y];
    }
    dp[x][y] = (((dp[x][y] + dpsm) % MOD + MOD) % MOD);
    dp[x][y] =
        (((dp[x][y] +
           ((((((sz * (((y * y) % MOD + MOD) % MOD)) % MOD + MOD) % MOD) +
              (((-(((2LL * (((y * ysm) % MOD + MOD) % MOD)) % MOD + MOD) %
                   MOD) +
                 y2sm) %
                    MOD +
                MOD) %
               MOD)) %
                 MOD +
             MOD) %
            MOD)) %
              MOD +
          MOD) %
         MOD);
    dp[x][y] =
        (((dp[x][y] +
           ((((((sz * (((x * x) % MOD + MOD) % MOD)) % MOD + MOD) % MOD) +
              (((-(((2LL * (((x * xsm) % MOD + MOD) % MOD)) % MOD + MOD) %
                   MOD) +
                 x2sm) %
                    MOD +
                MOD) %
               MOD)) %
                 MOD +
             MOD) %
            MOD)) %
              MOD +
          MOD) %
         MOD);
    if (sz) dp[x][y] = divv(dp[x][y], sz, MOD);
    ndpsm = (((ndpsm + dp[x][y]) % MOD + MOD) % MOD);
    nxsm = (((nxsm + x) % MOD + MOD) % MOD);
    nx2sm = (((nx2sm + (((x * x) % MOD + MOD) % MOD)) % MOD + MOD) % MOD);
    nysm = (((nysm + y) % MOD + MOD) % MOD);
    ny2sm = (((ny2sm + (((y * y) % MOD + MOD) % MOD)) % MOD + MOD) % MOD);
    nsz = (((nsz + 1) % MOD + MOD) % MOD);
  }
  int r, c;
  cin >> r >> c;
  --r, --c;
  cout << dp[r][c] << endl;
  return 0;
}
