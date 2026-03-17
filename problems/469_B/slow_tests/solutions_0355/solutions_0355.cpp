#include <bits/stdc++.h>
using namespace std;
int p, q, l, r, i, a, b, online[2010], S[1010], F[1010], sol, j, k, ok;
int main() {
  cin >> p >> q >> l >> r;
  for (i = 1; i <= p; i++) {
    cin >> a >> b;
    for (j = a; j <= b; j++) online[j] = 1;
  }
  for (i = 1; i <= q; i++) {
    cin >> S[i] >> F[i];
  }
  for (i = l; i <= r; i++) {
    ok = 0;
    for (j = 1; j <= q; j++) {
      for (k = S[j]; k <= F[j]; k++)
        if (online[i + k]) ok = 1;
    }
    sol = sol + ok;
  }
  cout << sol;
  return 0;
}
