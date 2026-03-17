#include <bits/stdc++.h>
using namespace std;
int N;
long long C[1001][1001];
long long dp[1001];
long long color[1001];
long long combination(int n, int p) {
  if (n == p || p == 0) {
    return C[n][p] = 1;
  }
  if (C[n][p] != -1) {
    return C[n][p];
  } else {
    long long ans = combination(n - 1, p) % 1000000007L;
    ans = ans + (combination(n - 1, p - 1) % 1000000007L);
    return C[n][p] = ans % 1000000007L;
  }
}
long long solve(int k) {
  if (k == 1) {
    return 1;
  } else if (dp[k] != -1) {
    return dp[k];
  } else {
    long long sum = 0;
    for (int i = 1; i <= k; i++) {
      sum += color[i];
    }
    sum--;
    long long ans = combination(sum, color[k] - 1);
    ans *= solve(k - 1);
    ans %= 1000000007L;
    return dp[k] = ans;
  }
}
int main() {
  scanf("%d\n", &N);
  for (int i = 1; i <= N; i++) {
    cin >> color[i];
  }
  memset(dp, -1, sizeof dp);
  memset(C, -1, sizeof C);
  long long ans = solve(N);
  cout << ans << endl;
}
