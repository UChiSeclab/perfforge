#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int INF = (1LL << 31) - 1;
const long long LINF = LLONG_MAX;
const int maxn = 1e3 + 1;
long long C[maxn][maxn], a[maxn], n, ans = 1;
long long c(int r, int n) {
  if (r == 0 || r == n) return 1ll;
  if (C[r][n]) return C[r][n];
  C[r][n] = c(r - 1, n - 1);
  C[r][n] %= mod;
  C[r][n] += c(r, n - 1);
  C[r][n] %= mod;
  return C[r][n];
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  int s = 0, t = 0;
  for (int i = 0; i < n; i++) cin >> a[i], t += a[i];
  for (int i = n - 1; i >= 0; i--) {
    ans *= c(a[i] - 1, t - s - 1) % mod;
    ans %= mod;
    s += a[i];
  }
  cout << ans << endl;
}
