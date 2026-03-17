#include <bits/stdc++.h>
int dp[2][101][101], n, d, k;
bool seen[2][101][101];
int sol(int index, int w, bool in) {
  if (w == n) {
    if (in)
      return 1;
    else
      return 0;
  }
  if (index == n || w > n) return 0;
  if (seen[in][index][w]) return dp[in][index][w];
  int ans = 0;
  for (int i = 1; i <= k; i++)
    ans = (ans +
           (sol(index + 1, w + i, (in == 1 || i >= d ? 1 : 0)) % 1000000007)) %
          1000000007;
  seen[in][index][w] = true;
  return dp[in][index][w] = ans;
}
int main() {
  scanf("%d %d %d", &n, &k, &d);
  printf("%d\n", sol(0, 0, 0));
}
