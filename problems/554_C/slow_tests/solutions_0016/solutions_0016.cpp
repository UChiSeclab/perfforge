#include <bits/stdc++.h>
using namespace std;
long long mod_minus(long long a, long long b) {
  return (a - b + 1000000007) % 1000000007;
}
int ara[1005];
long long dp[1005], fake_place[1005][1005];
long long func(int seat, int ball) {
  if (!ball) return 1;
  if (seat == 1) return 1;
  if (fake_place[seat][ball] != -1) return fake_place[seat][ball];
  int i;
  long long ans = 0;
  for (i = 0; i <= ball; i++) {
    ans += func(seat - 1, i);
    ans %= 1000000007;
  }
  return fake_place[seat][ball] = ans;
}
int main() {
  int k, i, j;
  for (i = 0; i < 1005; i++)
    for (j = 0; j < 1005; j++) fake_place[i][j] = -1;
  scanf("%d", &k);
  for (i = 0; i < k; i++) scanf("%d", &ara[i]);
  dp[0] = 1;
  int total = ara[0];
  for (i = 1; i < k; i++) {
    dp[i] =
        dp[i - 1] * (mod_minus(func(total + 1, ara[i]), func(total, ara[i])));
    dp[i] %= 1000000007;
    total += ara[i];
  }
  printf("%I64d\n", dp[k - 1]);
  return 0;
}
