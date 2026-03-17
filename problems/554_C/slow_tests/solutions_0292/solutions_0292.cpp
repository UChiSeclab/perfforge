#include <bits/stdc++.h>
using namespace std;
int N;
int arr[1010];
int sum[1010];
long long c[1010][1010], dp[1010][1010];
long long C(int n, int r) {
  if (n == r || r == 0) return 1;
  if (c[n][r] != -1) return c[n][r];
  return c[n][r] = (C(n - 1, r - 1) % 1000000007 + C(n - 1, r) % 1000000007) %
                   1000000007;
}
long long solve(int ind, int pos) {
  if (pos == sum[N - 1] + 1) {
    if (ind == N) return 1;
    return 0;
  }
  if (dp[ind][pos] != -1) return dp[ind][pos];
  long long p1 = 0, p2 = 0;
  if (pos - sum[ind] < 0)
    p1 = solve(ind, pos + 1);
  else {
    p1 = solve(ind, pos + 1);
    p2 = (solve(ind + 1, pos + 1) % 1000000007 *
          C(pos - sum[ind] + arr[ind] - 1, arr[ind] - 1) % 1000000007) %
         1000000007;
  }
  return dp[ind][pos] = (p1 % 1000000007 + p2 % 1000000007) % 1000000007;
}
int main() {
  memset(c, -1, sizeof(c));
  memset(dp, -1, sizeof(dp));
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    if (i == 0)
      sum[i] = arr[i];
    else
      sum[i] = sum[i - 1] + arr[i];
  }
  cout << solve(0, 1) << endl;
}
