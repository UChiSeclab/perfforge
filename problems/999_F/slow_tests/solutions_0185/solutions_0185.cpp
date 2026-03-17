#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[5005];
int Favo[505];
int cost[11];
int dp[5005][505][11];
int solve(int idx, int f, int rem) {
  if (idx == n * k || f == n) return cost[rem];
  int &ret = dp[idx][f][rem];
  if (~ret) return ret;
  if (rem < k && arr[idx] == Favo[f])
    ret = max(ret, solve(idx + 1, f, rem + 1));
  ret = max(ret, solve(idx, f + 1, 0) + cost[rem]);
  ret = max(ret, solve(idx + 1, f, rem));
  return ret;
}
int main() {
  scanf("%d %d", &n, &k);
  for (size_t i = 0; i < n * k; i++) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + (n * k));
  for (size_t i = 0; i < n; i++) {
    scanf("%d", &Favo[i]);
  }
  sort(Favo, Favo + n);
  for (size_t i = 1; i <= k; i++) {
    scanf("%d", &cost[i]);
  }
  memset(dp, -1, sizeof dp);
  printf("%d", solve(0, 0, 0));
  return 0;
}
