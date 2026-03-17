#include <bits/stdc++.h>
using namespace std;
const int N = 1000007;
int dp[N];
void solve() {
  int n;
  int ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < (n); ++i) {
    int a;
    scanf("%d", &a);
    dp[a] = max(dp[a], 1);
    for (int b = a + a; b < N; b += a) {
      dp[b] = max(dp[b], dp[a] + 1);
    }
    ans = max(ans, dp[a]);
  }
  printf("%d\n", ans);
}
void testGen() {
  FILE *f = fopen("input.txt", "w");
  fclose(f);
}
int main() {
  cerr << fixed;
  cerr.precision(3);
  cout << fixed;
  cout.precision(9);
  solve();
  return 0;
}
