#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& stream, const vector<T> v) {
  stream << "[ ";
  for (int i = 0; i < (int)v.size(); i++) stream << v[i] << " ";
  stream << "]";
  return stream;
}
long long fpow(long long x, long long p, long long m) {
  long long r = 1;
  for (; p; p >>= 1) {
    if (p & 1) r = r * x % m;
    x = x * x % m;
  }
  return r;
}
long long inv(long long a, long long b) {
  return a < 2 ? a : ((a - inv(b % a, a)) * b + 1) / a % b;
}
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int N, p[200], cnt[2];
bool v[200];
int dp[110][110][110][2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  int i, j, k, t;
  for (i = 1; i <= N; i++) {
    cin >> p[i];
    if (p[i] != 0) {
      v[p[i]] = 1;
    }
  }
  for (i = 1; i <= N; i++)
    if (!v[i]) cnt[i % 2]++;
  for (i = N; i > 0; i--) {
    for (j = 0; j <= N; j++)
      for (k = 0; k <= N; k++)
        for (t = 0; t < 2; t++) {
          dp[i][j][k][t] = 2 * N;
          if (p[i] != 0) {
            int v = 0;
            if (i != 1 && p[i] % 2 != t) v = 1;
            dp[i][j][k][t] = v + dp[i + 1][j][k][p[i] % 2];
          } else {
            if (j > 0) {
              int v = 0;
              if (i != 1 && t != 0) v = 1;
              dp[i][j][k][t] = min(dp[i][j][k][t], v + dp[i + 1][j - 1][k][0]);
            }
            if (k > 0) {
              int v = 0;
              if (i != 1 && t != 1) v = 1;
              dp[i][j][k][t] = min(dp[i][j][k][t], v + dp[i + 1][j][k - 1][1]);
            }
          }
        }
  }
  cout << dp[1][cnt[0]][cnt[1]][0] << "\n";
  return 0;
}
