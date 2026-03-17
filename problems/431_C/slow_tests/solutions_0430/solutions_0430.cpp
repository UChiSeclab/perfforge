#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 1;
const int mod = 1e9 + 7;
int n, k, d, f[N + 1][N][2], x[N];
inline void add(int& src, const int& dt) { src = (src % mod + dt % mod) % mod; }
int dfs(int rank, int sum, int check) {
  if (sum > n) return 0;
  int& res = f[rank][sum][check];
  if (~res) return res;
  res = 0;
  if (sum == n) {
    if (!check) return res = 0;
    return res = 1;
  }
  for (int v = 1; v <= k; ++v) {
    x[rank] = v;
    res = (res + dfs(rank + 1, sum + v, check | (v >= d))) % mod;
  }
  return res;
}
int main() {
  scanf("%d%d%d", &n, &k, &d);
  memset(f, -1, sizeof f);
  cout << dfs(1, 0, 0);
  exit(0);
  for (int rank = n; rank >= 1; --rank) {
    for (int sum = 1; sum <= n; ++sum) {
      for (int v = 1; v <= k; ++v) {
        if (sum > v) {
          if (v >= d)
            f[rank][sum][1] =
                ((f[rank][sum][1] + f[rank + 1][sum - v][0]) % mod +
                 f[rank + 1][sum - v][1]) %
                mod;
          else
            f[rank][sum][0] = (f[rank][sum][0] + f[rank + 1][sum - v][0]) % mod;
        } else if (sum == v) {
          if (v >= d)
            f[rank][sum][1] = (f[rank][sum][1] + 1) % mod;
          else
            f[rank][sum][0] = (f[rank][sum][0] + 1) % mod;
        } else
          break;
      }
    }
  }
  printf("%d\n", f[1][n][1]);
  return 0;
}
