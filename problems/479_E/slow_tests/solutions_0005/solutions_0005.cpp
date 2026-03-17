#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f;
const int MAXN = 5e3 + 5;
const int MOD = 1e9 + 7;
const int MAX_ASCII_CODE = 26;
const int MAX_NUMBER_OF_NODES = 1e5 + 5;
int dp[MAXN];
int temp[MAXN];
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(NULL);
  cout << fixed << setprecision(10);
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  dp[a] = 1;
  int ans = 0;
  int sav;
  if (a > b) {
    for (int i = (int)0; i < (int)(k); i++) {
      for (int j = (int)b + 2; j < (int)(n + 1); j++) {
        if (j + j - b - 1 < n)
          temp[j + j - b - 1] = (temp[j + j - b - 1] + dp[j]) % MOD;
        else
          temp[n] = (temp[n] + dp[j]) % MOD;
      }
      for (int j = n; j > b; j--) {
        temp[j] = (temp[j] + temp[j + 1]) % MOD;
        dp[j] = (MOD + temp[j] - dp[j]) % MOD;
      }
      sav = temp[b + 1];
      memset(temp, 0, sizeof(temp));
    }
    for (int j = (int)b + 2; j < (int)(n + 1); j++) {
      ans = (ans + dp[j]) % MOD;
    }
    ans = (ans + sav) % MOD;
    cout << ans << "\n";
  }
  if (b > a) {
    for (int i = (int)0; i < (int)(k); i++) {
      for (int j = b - 2; j > 0; j--) {
        if (j - b + j + 1 > 0)
          temp[j + j - b + 1] = (temp[j + j - b - 1] + dp[j]) % MOD;
        else
          temp[1] = (temp[1] + dp[j]) % MOD;
      }
      for (int j = (int)1; j < (int)(b); j++) {
        temp[j] = (temp[j] + temp[j - 1]) % MOD;
        dp[j] = (temp[j] - dp[j] + MOD) % MOD;
      }
      sav = temp[b - 1];
      memset(temp, 0, sizeof(temp));
    }
    for (int j = (int)1; j < (int)(b - 1); j++) {
      ans = (ans + dp[j]) % MOD;
    }
    ans = (ans + sav) % MOD;
    cout << ans << "\n";
  }
}
