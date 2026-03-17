#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<int> > a(N, vector<int>(M));
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j) cin >> a[i][j];
  vector<int> dp(K, -1e9);
  dp[0] = 0;
  int P = M / 2;
  for (int i = 0; i < N; ++i) {
    vector<vector<int> > knap(P + 1, vector<int>(K, -1e9));
    knap[0][0] = 0;
    for (int j = 0; j < M; ++j)
      for (int take = P - 1; take >= 0; --take)
        for (int rest = 0; rest < K; ++rest)
          knap[take + 1][(a[i][j] + rest) % K] = max(
              knap[take + 1][(a[i][j] + rest) % K], knap[take][rest] + a[i][j]);
    vector<int> ndp(K, -1e9);
    for (int rest1 = 0; rest1 < K; ++rest1)
      for (int rest2 = 0; rest2 < K; ++rest2)
        for (int take = 0; take <= P; ++take)
          ndp[(rest1 + rest2) % K] =
              max(ndp[(rest1 + rest2) % K], dp[rest1] + knap[take][rest2]);
    swap(dp, ndp);
  }
  cout << dp[0] << "\n";
  return 0;
}
