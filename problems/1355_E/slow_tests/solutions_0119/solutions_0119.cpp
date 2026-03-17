#include <bits/stdc++.h>
using namespace std;
const long long N = 111111;
long long n, A, R, M, h[N];
long long f(long long H) {
  long long x = 0, y = 0;
  for (long long i = 0; i < n; ++i) {
    if (h[i] > H)
      x += h[i] - H;
    else
      y += H - h[i];
  }
  return min(x, y) * M + (x - min(x, y)) * R + (y - min(x, y)) * A;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> A >> R >> M;
  M = min(M, A + R);
  for (long long i = 0; i < n; ++i) cin >> h[i];
  long long l = 0, r = 1e9;
  while (r - l > 20) {
    long long lmed = l + (r - l) / 3;
    long long rmed = r - (r - l) / 3;
    if (f(lmed) < f(rmed))
      r = rmed;
    else
      l = lmed;
  }
  long long res = 1e18;
  for (long long i = l; i <= r; ++i) res = min(res, f(i));
  cout << res;
}
