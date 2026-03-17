#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const int N = 2005, inf = 1e9;
int mark[N], val[N];
int a, n, m;
int dp[2][N][N];
int fun(int pos, int ind, bool present) {
  if (pos == a + 1) return 0;
  if (dp[present][pos][ind] != -1) return dp[present][pos][ind];
  int ans = inf;
  int newind = ((val[pos] < val[ind]) ? pos : ind);
  if ((present && mark[pos] == -1) || (!present && !mark[pos]))
    ans = min(fun(pos + 1, a + 1, false),
              val[newind] + fun(pos + 1, newind, false));
  else if (present || mark[pos] == 1)
    ans = val[newind] + fun(pos + 1, newind, true);
  ans = min(ans, inf);
  return dp[present][pos][ind] = ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  memset(dp, -1, sizeof(dp));
  cin >> a >> n >> m;
  for (int i = 1; i < n + 1; i++) {
    int x, y;
    cin >> x >> y;
    mark[x] = 1;
    mark[y] = -1;
  }
  for (int i = 0; i < a + 2; i++) val[i] = inf;
  for (int i = 1; i < m + 1; i++) {
    int x, y;
    cin >> x >> y;
    val[x] = min(val[x], y);
  }
  int ans = fun(0, a + 1, 0);
  if (ans >= inf) ans = -1;
  cout << ans << endl;
  return 0;
}
