#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const long long N = 0;
long long dp[80][80];
long long rowdp[80][80][80];
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long a[n][m];
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  for (long long i = 0; i < 80; ++i) {
    for (long long j = 0; j < 80; ++j) {
      dp[i][j] = -M;
    }
  }
  dp[0][0] = 0;
  for (long long i = 0; i < n; ++i) {
    for (long long ii = 0; ii < 80; ++ii) {
      for (long long jj = 0; jj < 80; ++jj) {
        for (long long kk = 0; kk < 80; ++kk) {
          rowdp[ii][jj][kk] = -M;
        }
      }
    }
    rowdp[0][0][0] = 0;
    for (long long j = 0; j < m; ++j) {
      for (long long c = 0; c <= j + 1; ++c) {
        for (long long r = 0; r < k; ++r) {
          if (c < m)
            amax(rowdp[j + 1][c + 1][(r + a[i][j]) % k],
                 rowdp[j][c][r] + a[i][j]);
          amax(rowdp[j + 1][c][r], rowdp[j][c][r]);
        }
      }
    }
    long long mxr[k];
    for (long long r = 0; r < k; ++r) {
      mxr[r] = -M;
      for (long long j = 0; j <= m / 2; ++j) {
        amax(mxr[r], rowdp[m][j][r]);
      }
    }
    for (long long prev = 0; prev < k; ++prev) {
      for (long long wen = 0; wen < k; ++wen) {
        amax(dp[i + 1][(wen + prev) % k], dp[i][prev] + mxr[wen]);
      }
    }
  }
  cout << dp[n][0] << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
