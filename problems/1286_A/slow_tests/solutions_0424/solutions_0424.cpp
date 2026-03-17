#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const double PI = acos(-1);
const long long MOD = 1000000007;
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < (int)(N); i++) cin >> A[i];
  vector<vector<vector<vector<int>>>> dp(
      N + 1, vector<vector<vector<int>>>(
                 N + 1, vector<vector<int>>(N + 1, vector<int>(2, (1e9)))));
  dp[0][0][0][0] = dp[0][0][0][1] = 0;
  int o = (N + 1) / 2;
  int e = N / 2;
  for (int i = 0; i < (int)(N); i++) {
    for (int j = 0; j < (int)(N); j++) {
      for (int k = 0; k < (int)(N); k++) {
        if (A[i] == 0) {
          dp[i + 1][j + 1][k][0] = min(dp[i][j][k][0], dp[i][j][k][1] + 1);
          dp[i + 1][j][k + 1][1] = min(dp[i][j][k][0] + 1, dp[i][j][k][1]);
        } else if (A[i] % 2 == 0) {
          dp[i + 1][j][k][1] = (1e9);
          dp[i + 1][j][k][0] = min(dp[i][j][k][0], dp[i][j][k][1] + 1);
        } else {
          dp[i + 1][j][k][0] = (1e9);
          dp[i + 1][j][k][1] = min(dp[i][j][k][1], dp[i][j][k][0] + 1);
        }
      }
    }
    if (A[i] != 0 && A[i] % 2 == 0) e--;
    if (A[i] != 0 && A[i] % 2 == 1) o--;
  }
  cout << min(dp[N][e][o][0], dp[N][e][o][1]) << endl;
}
