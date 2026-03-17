#include <bits/stdc++.h>
using namespace std;
int n;
int maxa;
int a[100005];
int dp[1000005];
vector<int> d[1000005];
void sieve(int x) {
  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= x / i; j++) {
      d[i * j].push_back(i);
    }
  }
}
int cmp(int x, int y) { return x > y; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    maxa = max(maxa, a[i]);
  }
  dp[0] = 1;
  sieve(maxa);
  for (int i = 1; i <= n; i++) {
    for (int j = d[a[i]].size() - 1; j >= 0; j--) {
      int x = d[a[i]][j];
      dp[x] += dp[x - 1];
      dp[x] %= 1000000007;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += dp[i];
  }
  ans %= 1000000007;
  cout << ans;
}
