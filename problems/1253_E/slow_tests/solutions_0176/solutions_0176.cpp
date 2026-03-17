#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> ants(N);
  for (int i = 0; i < N; ++i) {
    cin >> ants[i].first >> ants[i].second;
    M = max(M, ants[i].first + ants[i].second);
  }
  sort(ants.begin(), ants.end());
  vector<vector<int>> dp(N + 1, vector<int>(M + 1, 3 * M));
  vector<vector<int>> suffix_min(N + 1, vector<int>(M + 1, 3 * M));
  for (int i = 0; i < N; ++i) {
    int l = ants[i].first - ants[i].second;
    int r = ants[i].first + ants[i].second;
    ;
    for (int j = 1; j <= M; ++j) {
      dp[i][j] = 3 * M;
      if (i > 0) dp[i][j] = dp[i - 1][j];
      if (j < r) continue;
      int ldelta = max(0, l - 1);
      int rdelta = max(0, j - r);
      dp[i][j] = min(dp[i][j], max(ldelta, rdelta));
      int delta = j - r;
      int new_l = max(1, l - delta);
      if (i != 0 || new_l == 1) {
        dp[i][j] = min(
            dp[i][j],
            delta + (new_l == 1 || i == 0 ? 0 : suffix_min[i - 1][new_l - 1]));
      }
    }
    for (int j = M; j >= 1; --j) {
      suffix_min[i][j] = dp[i][j];
      if (j < M) {
        suffix_min[i][j] = min(suffix_min[i][j], suffix_min[i][j + 1]);
      }
    }
  }
  int answer = 3 * M;
  for (int i = 0; i < N; ++i) {
    answer = min(answer, dp[i][M]);
  }
  cout << answer << endl;
  return 0;
}
