#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000000")
using namespace std;
const double EPS = 1e-3;
const int INF = (int)(2e9 + 0.5);
const int MAXN = 410;
int n, k, a[MAXN], b[MAXN];
map<int, int> dp[MAXN];
int dfs(int num, int balance) {
  if (num < 0 && !balance) return 0;
  if (num < 0 && balance) return -INF;
  if (dp[num].count(balance)) return dp[num][balance];
  int& result = dp[num][balance];
  result = dfs(num - 1, balance);
  result = max(result, dfs(num - 1, balance - (a[num] - b[num])) + a[num]);
  return result;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; scanf("%d", &a[i]), ++i)
    ;
  for (int i = 0; i < n; scanf("%d", &b[i]), b[i] *= k, ++i)
    ;
  int result = dfs(n - 1, 0);
  printf("%d\n", result <= 0 ? -1 : result);
  return 0;
}
