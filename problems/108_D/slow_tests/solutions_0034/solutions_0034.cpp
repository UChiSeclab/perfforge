#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const bool debug = true;
const long long INFL = LLONG_MAX;
int A, B, N, M, H, S[1010];
long double memo[100100][102];
bool was[100100][102];
long double dp(int b, int n) {
  int a = A;
  if (a + b < n) return 0;
  if (b < n) return 0;
  if (n == 0) return 1;
  if (a < 0 || b < 0 || n < 0) return 0;
  if (was[b][n]) return memo[b][n];
  long double x = (long double)n / (a + b);
  memo[b][n] = x * dp(b - 1, n - 1) + (1 - x) * dp(b - 1, n);
  was[b][n] = 1;
  return memo[b][n];
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.precision(15);
  cout << fixed;
  cin >> N >> M >> H;
  for (int(i) = 1; (i) <= (M); (i)++) cin >> S[i];
  S[H]--;
  for (int(i) = 1; (i) <= (M); (i)++)
    if (i == H)
      A = S[i];
    else
      B += S[i];
  N--;
  if (A + B < N) {
    cout << -1 << '\n';
  } else {
    cout << (1 - dp(B, N)) << '\n';
  }
}
