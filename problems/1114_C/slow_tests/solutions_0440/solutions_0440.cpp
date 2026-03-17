#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long base = 16;
  long long n, i, j, p, c, noz, k;
  cin >> n >> base;
  noz = n;
  j = base;
  for (i = 2; i * i <= base; i++) {
    if (j % i == 0) {
      p = 0;
      while (j % i == 0) {
        p++;
        j /= i;
      }
      c = 0;
      k = n;
      while (k / i > 0) {
        c += k / i;
        k /= i;
      }
      noz = (((noz) < (c / p)) ? (noz) : (c / p));
    }
    long long wow = j / i;
    if (wow == 0) continue;
    if (j % wow) continue;
    if (wow > 1 and j % wow == 0) {
      p = 0;
      while (j % wow == 0) {
        p++;
        j /= wow;
      }
      c = 0;
      k = n;
      while (k / wow > 0) {
        c += k / wow;
        k /= wow;
      }
      noz = (((noz) < (c / p)) ? (noz) : (c / p));
    }
  }
  if (j > 1) {
    long long wow = j;
    p = 0;
    while (j % wow == 0) {
      p++;
      j /= wow;
    }
    c = 0;
    k = n;
    while (k / wow > 0) {
      c += k / wow;
      k /= wow;
    }
    noz = (((noz) < (c / p)) ? (noz) : (c / p));
  }
  cout << noz;
  return 0;
}
