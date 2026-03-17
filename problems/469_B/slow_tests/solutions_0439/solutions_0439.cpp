#include <bits/stdc++.h>
using namespace std;
int ar[10001], ar2[10001];
int cc[10001];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int p, q, r, l;
  cin >> p >> q >> l >> r;
  for (int i = 0; i < p; i++) {
    int a, b;
    cin >> a >> b;
    for (int j = a; j <= b; j++) ar[j] = 1;
  }
  int z = 0;
  for (int i = 0; i < q; i++) {
    int a, b, c;
    cin >> a >> b;
    for (int j = a; j <= b; j++) {
      for (int p = l; p <= r; p++) {
        if (ar[p + j] == 1) {
          cc[p] = 1;
        }
      }
    }
  }
  for (int i = 0; i < 1001; i++) z += cc[i];
  cout << z;
  return 0;
}
