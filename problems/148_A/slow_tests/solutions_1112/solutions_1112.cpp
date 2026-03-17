#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, l, m, n, i, j, d, fucked = 0;
  cin >> k >> l >> m >> n >> d;
  int p[100010];
  if (k == 1 || l == 1 || m == 1 || n == 1) {
    cout << d;
  } else {
    for (i = 1; i <= d; i++) {
      if (i % (k) == 0 || i % (l) == 0 || i % (m) == 0 || i % (n) == 0) {
        p[i] = -1;
      } else {
        p[i] = 0;
      }
    }
    for (j = 1; j <= d; j++) {
      if (p[j] == -1) {
        fucked++;
      }
    }
    cout << fucked << endl;
  }
  return 0;
}
