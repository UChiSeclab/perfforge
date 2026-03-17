#include <bits/stdc++.h>
using namespace std;
int n, k, d;
int dp[105][110][2];
int rec(int idx, int sum, bool passed) {
  if (sum > n) return 0;
  if (sum == n) return passed;
  if (dp[idx][sum][passed] != -1) return dp[idx][sum][passed];
  long long answer = 0;
  for (int i = 1; i <= k; i++) {
    answer += rec(idx + 1, sum + i, i >= d || passed);
    if (answer > 1000000007) answer -= 1000000007;
  }
  dp[idx][sum][passed] = answer;
  return answer;
}
int main() {
  memset(dp, 0xFF, sizeof(dp));
  scanf("%d%d%d", &n, &k, &d);
  cout << rec(0, 0, false) << endl;
  return 0;
}
