#include <bits/stdc++.h>
using namespace std;
long long n, k, d;
long long arr[110];
long long dp[110][110][3];
long long myfunc(long long i, long long sum, long long cnt) {
  if (i >= d) cnt = 1;
  if (sum <= 0) {
    if (sum == 0) {
      if (cnt == 1) return 1;
    }
    return 0;
  }
  if (dp[i][sum][cnt] != -1) return dp[i][sum][cnt];
  long long ret1 = 0;
  for (long long j = 1; j <= k; j++) {
    ret1 = (ret1 + myfunc(j, sum - j, cnt) % 1000000007) % 1000000007;
  }
  dp[i][sum][cnt] = ret1 % 1000000007;
  return dp[i][sum][cnt];
}
int main() {
  cin >> n >> k >> d;
  memset(dp, -1, sizeof dp);
  long long ans = 0;
  for (long long i = 1; i <= k; i++) {
    ans = (ans + myfunc(i, n - i, 0) % 1000000007) % 1000000007;
  }
  cout << ans << endl;
  return 0;
}
