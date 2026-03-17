#include <bits/stdc++.h>
using namespace std;
int f[10];
vector<int> sol;
int dp[10][1000001];
bool vis[10][1000001];
int calc(int i, int v) {
  if (v < 0) return -(1 << 29);
  if (!i) return 0;
  if (vis[i][v] == false) {
    vis[i][v] = true;
    dp[i][v] = max(calc(i - 1, v), 1 + calc(i, v - f[i]));
  }
  return dp[i][v];
}
void print(int i, int v) {
  if (v < 0) return;
  if (!i) return;
  if (dp[i][v] == 1 + calc(i, v - f[i])) {
    printf("%d", i);
    print(i, v - f[i]);
  } else
    print(i - 1, v);
}
int main() {
  int v;
  cin >> v;
  for (int i = 1; i <= 9; ++i) cin >> f[i];
  int x = calc(9, v);
  if (x > 0)
    print(9, v);
  else
    printf("-1");
  return 0;
}
