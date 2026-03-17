#include <bits/stdc++.h>
using namespace std;
const int Nmax = 505;
int Mod;
int dp[Nmax][Nmax];
int S[Nmax][Nmax];
int A[Nmax];
int main() {
  ios::sync_with_stdio(false);
  int N, M, B;
  cin >> N >> M >> B >> Mod;
  for (int i = 1; i <= N; ++i) cin >> A[i];
  dp[0][0] = 1 % Mod;
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j <= M; ++j) {
      for (int k = 0; k <= B; ++k) {
        S[j][k] = dp[j][k];
        if (j > 0 && k >= A[i]) S[j][k] = (S[j][k] + S[j - 1][k - A[i]]) % Mod;
      }
    }
    for (int j = 1; j <= M; ++j) {
      for (int k = A[i]; k <= B; ++k) {
        dp[j][k] = (dp[j][k] + S[j - 1][k - A[i]]) % Mod;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= B; ++i) ans = (ans + dp[M][i]) % Mod;
  cout << ans << '\n';
}
