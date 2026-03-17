#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-parameter"
using namespace std;
const long long INF_LL = 1e17;
const int INF = 1e9 + 100;
const int MOD = 1e9 + 7;
const int Base = 30;
const long double EPS = 1e-9;
const int BLOCK = 1000;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
void open_file() {}
const int maxN = 1e5 + 10;
int dp[202][202][202];
void sol() {
  int n, limits;
  cin >> n >> limits;
  string s;
  cin >> s;
  string t;
  cin >> t;
  memset(dp, 0xc0, sizeof(dp));
  dp[0][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k <= limits; k++) {
      for (int number = 0; number <= i; number++) {
        for (int c = 0; c < 26; c++) {
          int diff = c != (int)(s[i - 1] - 'a');
          int prev = number - (c == (int)(t[0] - 'a'));
          if (k >= diff && prev >= 0) {
            dp[i][k][number] =
                max(dp[i][k][number], dp[i - 1][k - diff][prev] +
                                          (c == (int)(t[1] - 'a')) * prev);
          }
        }
      }
    }
  }
  int res = 0;
  for (int k = 0; k <= limits; k++) {
    for (int i = 0; i <= n; i++) res = max(res, dp[n][k][i]);
  }
  cout << res;
}
void solve() {
  int T;
  T = 1;
  int TestCase = 0;
  while (T--) {
    TestCase += 1;
    sol();
  }
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  open_file();
  solve();
}
