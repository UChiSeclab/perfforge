#include <bits/stdc++.h>
using namespace std;
const long double ZERO = 1e-15;
const long double EPS = 1e-10;
const int MAXN = 100500;
const int INF9 = 2 * 1e9;
const long long INF18 = 4 * 1e18;
const long long L0 = 0;
const long long L1 = 1;
const long double PI = acos(-1);
const long double sq2 = sqrt(2.0);
long long n, r1, r2, r3, d;
vector<long long> v;
vector<vector<long long> > dp;
void step(long long& a, long long b) { a = (a < b) ? a : b; }
int main() {
  cin >> n >> r1 >> r2 >> r3 >> d;
  v.resize(n);
  for (long long i = 0; i < (n); i++) cin >> v[i];
  dp.resize(n);
  for (long long i = 0; i < (n); i++) {
    dp[i].resize(2);
    dp[i][0] = INF18;
    dp[i][1] = INF18;
  }
  dp[0][0] = r1 * v[0] + r3;
  dp[0][1] = min(r2, r1 * v[0] + r1);
  for (long long i = 0; i < (n - 1); i++) {
    step(dp[i + 1][0], dp[i][0] + d + r1 * v[i + 1] + r3);
    step(dp[i + 1][1], dp[i][0] + d + min(r2, r1 * v[i + 1] + r1));
    step(dp[i + 1][0], dp[i][1] + 3 * d + r1 * v[i + 1] + r3 + r1);
    step(dp[i + 1][0], dp[i][1] + 3 * d + r1 * v[i + 1] + 3 * r1);
    step(dp[i + 1][0], dp[i][1] + 3 * d + 2 * r1 + r2);
    step(dp[i + 1][1], dp[i][1] + 3 * d + r1 + r2);
    step(dp[i + 1][1], dp[i][1] + 3 * d + 2 * r1 + r1 * v[i + 1]);
  }
  step(dp[n - 1][0], dp[n - 2][1] + 2 * d + r1 * v[n - 1] + r1 + r3);
  cout << dp[n - 1][0] << endl;
  return 0;
}
