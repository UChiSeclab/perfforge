#include <bits/stdc++.h>
using namespace std;
void fastStream() {
  cin.tie(0);
  std::ios_base::sync_with_stdio(0);
}
const int mod = 1000000000 + 7;
int K;
int C[1010];
int dp[1010][1010];
int tot;
const int MAX_ARG = 2200;
long long dp2[MAX_ARG][MAX_ARG];
long long comb(int a, int b) {
  if (a < 0 || b < 0) return 0;
  if (a < b)
    return 0;
  else if (b == 0)
    return 1;
  else if (dp2[a][b] >= 0)
    return dp2[a][b];
  return dp2[a][b] = (comb(a - 1, b) + comb(a - 1, b - 1)) % mod;
}
int dfs(int kind, int pos, int sum) {
  if (dp[kind][pos] >= 0) return dp[kind][pos];
  long long res = 0;
  if (kind == K) {
    res = 1;
  } else if (pos == tot) {
    res = 0;
  } else {
    if (pos + 1 >= C[kind] + sum) {
      const int A = pos + 1 - (C[kind] + sum) + C[kind] - 1;
      const int B = C[kind] - 1;
      res = (res + (comb(A, B) * dfs(kind + 1, pos + 1, sum + C[kind]))) % mod;
    }
    res = (res + dfs(kind, pos + 1, sum)) % mod;
  }
  return dp[kind][pos] = res;
}
int main() {
  memset(dp, -1, sizeof(dp));
  fastStream();
  cin >> K;
  for (int i = 0; i < K; i++) {
    cin >> C[i];
    tot += C[i];
  }
  memset(dp2, -1, sizeof(dp2));
  cout << dfs(0, 0, 0) << endl;
  return 0;
}
