#include <bits/stdc++.h>
using namespace std;
void read(int a = 0) {
  freopen("in", "r", stdin);
  if (a) freopen("out", "w", stdout);
}
int dp[100009], l, r, n, p, pr, q, k;
int main() {
  cin >> n;
  r = n;
  for (int i = 1; i <= n; i++) {
    cin >> dp[i];
  }
  for (int i = 1; i <= n; i++)
    dp[i] =
        min(n - i + 1, min(i, min(dp[i], min(dp[i - 1] + 1, dp[i + 1] + 1))));
  for (int i = n; i >= 1; i--)
    dp[i] =
        min(n - i + 1, min(i, min(dp[i], min(dp[i - 1] + 1, dp[i + 1] + 1))));
  for (int i = 1; i <= n; i++) k = max(k, dp[i]);
  cout << k;
}
