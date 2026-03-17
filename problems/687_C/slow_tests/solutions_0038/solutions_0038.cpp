#include <bits/stdc++.h>
using namespace std;
int arr[501];
bool vis[501][501][501];
bool anw[501][501][501];
bool dp(int id, int sb, int sum) {
  if (sum + sb == 0) return anw[id][sb][sum] = 1;
  if (id == 0) return anw[id][sb][sum] = 0;
  if (vis[id][sb][sum]) return anw[id][sb][sum];
  vis[id][sb][sum] = 1;
  bool ws = dp(id - 1, sb, sum);
  if (sum - arr[id - 1] >= 0) {
    if (sb - arr[id - 1] >= 0)
      ws |= dp(id - 1, sb - arr[id - 1], sum - arr[id - 1]);
    ws |= dp(id - 1, sb, sum - arr[id - 1]);
  }
  return anw[id][sb][sum] = ws;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  vector<int> tp;
  for (int i = 0; i <= k; i++)
    if (dp(n, i, k)) tp.push_back(i);
  printf("%d\n", int(tp.size()));
  for (int i = 0; i < tp.size(); i++) {
    if (i != 0) printf(" ");
    printf("%d", tp[i]);
  }
  printf("\n");
}
