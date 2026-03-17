#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1000 * 1000 * 100 + 1;
const int INF = 99999999;
int k, n;
vector<int> coins;
bitset<maxn> mark;
int main() {
  int an;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> an, coins.push_back(an), mark[an] = true;
  sort(coins.begin(), coins.end());
  int q;
  cin >> q;
  while (q-- > 0) {
    cin >> an;
    int res = INF;
    for (int a = 0; a < coins.size() and coins[a] <= an; a++)
      for (int t = 1; t <= k and t * coins[a] <= an; t++) {
        int An = an - coins[a] * t;
        int Dp = INF;
        vector<int> M(0);
        for (int i = 1; i * i <= An and i <= k; i++)
          if (An % i == 0) M.push_back(i), M.push_back(An / i);
        for (int i = 0; i < M.size(); i++)
          if (mark[M[i]]) Dp = min(Dp, An / M[i]);
        if (An == 0) Dp = 0;
        if (An >= 0 and Dp != INF) res = min(res, t + Dp);
      }
    if (res > k) res = -1;
    cout << res << endl;
  }
  return 0;
}
