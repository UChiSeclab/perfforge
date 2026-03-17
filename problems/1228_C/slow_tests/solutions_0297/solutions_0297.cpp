#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int n, x, i, j, ans = 1, c, s, k;
  unsigned long long int p[1000];
  k = 0;
  cin >> x >> n;
  c = x;
  if (c % 2 == 0) p[k++] = 2;
  while (c % 2 == 0) c /= 2;
  for (i = 3; i <= sqrt(x); i++) {
    if (c % i == 0) p[k++] = i;
    while (c % i == 0) c /= i;
  }
  if (c > 2) p[k++] = c;
  for (i = 0; i < k; i++) {
    c = p[i];
    s = 0;
    while (c <= n) {
      s += (n / c);
      s %= (1000000007 - 1);
      if (c > (n / p[i])) break;
      c *= p[i];
    }
    while (s > 0) {
      if (s % 2 == 1) ans = (ans * p[i]) % 1000000007;
      s /= 2;
      p[i] = (p[i] * p[i]) % 1000000007;
    }
  }
  cout << ans << endl;
  return 0;
}
