#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int k, c[1010];
long long dp[1010][1010];
long long calc(int id, int ball) {
  if (id == 1)
    return 1;
  else if (ball == 0)
    return 1;
  long long& ans = dp[id][ball];
  if (ans == -1)
    ans = (calc(id - 1, ball) % MOD + calc(id, ball - 1) % MOD) % MOD;
  return ans;
}
int main(void) {
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> c[i];
  }
  memset(dp, -1, sizeof(dp));
  long long ans = 1;
  int ball = 1;
  for (int i = 0; i < k; i++) {
    ans *= calc(ball, c[i] - 1);
    ans %= MOD;
    ball += c[i];
  }
  cout << ans << "\n";
  return 0;
}
