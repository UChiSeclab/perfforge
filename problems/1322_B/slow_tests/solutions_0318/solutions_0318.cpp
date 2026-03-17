#include <bits/stdc++.h>
using namespace std;
long long n, a[400005], b[400005];
long long cnt(long long l, long long r) {
  return upper_bound(b, b + n, r) - lower_bound(b, b + n, l);
}
int main(int argc, char const *argv[]) {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long ans = 0;
  for (long long j = 0; j <= 30; ++j) {
    long long c = 0;
    for (int i = 0; i < n; ++i) {
      b[i] = a[i] % (1ll << (j + 1));
    }
    sort(b, b + n);
    for (int i = 0; i < n; ++i) {
      c += cnt((1ll << j) - b[i], (1ll << (j + 1)) - 1 - b[i]);
      c += cnt((1ll << (j + 1)) + (1ll << j) - b[i],
               (1ll << (j + 2)) - 2 - b[i]);
      if (2 * b[i] >= (1ll << j) && 2 * b[i] < (1ll << (j + 1))) c--;
      if (2 * b[i] >= (1ll << (j + 1)) + (1ll << j) &&
          2 * b[i] <= (1ll << (j + 2)) - 2)
        c--;
    }
    c >>= 1;
    if (c & 1) ans |= (1ll << j);
  }
  cout << ans;
  return 0;
}
