#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000;
struct edge {
  long long to, cost;
  edge(int a, int b) : to(a), cost(b) {}
};
long long n, m;
long long mod = 1000000007;
long long dp[15][1005][1005];
long long dfs(long long pos, long long sta, long long stb) {
  if (sta > stb) return 0;
  if (pos >= m) return 1;
  if (dp[pos][sta][stb]) return dp[pos][sta][stb];
  long long re = dfs(pos + 1, sta, stb);
  re += dfs(pos, sta, stb - 1) + dfs(pos, sta + 1, stb) -
        dfs(pos, sta + 1, stb - 1) + mod;
  re %= mod;
  dp[pos][sta][stb] = re;
  return re;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> n >> m;
  cout << dfs(0, 1, n) << endl;
}
