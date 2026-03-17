#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) { cout << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << ' ';
  err(++it, args...);
}
int dx[8] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int ini() {
  int x;
  scanf("%d", &x);
  return x;
}
long long inl() {
  long long x;
  scanf("%lld", &x);
  return x;
}
int set_1(int n, int pos) { return n = (n | (1 << pos)); }
int reset_0(int n, int pos) { return n = n & ~(1 << pos); }
bool check_bit(int n, int pos) { return n = n & (1 << pos); }
const int N = (int)2e3 + 5;
const long long M = (long long)998244353;
const double pi = 2 * acos(0.0);
long long dp[N][N];
int n, k, m;
int main() {
  cin >> n >> m >> k;
  long long res = 0ll;
  dp[1][0] = m;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = (dp[i - 1][j] % M + dp[i - 1][j - 1] % M * (m - 1) % M) % M;
    }
  }
  cout << dp[n][k] << endl;
  return 0;
}
