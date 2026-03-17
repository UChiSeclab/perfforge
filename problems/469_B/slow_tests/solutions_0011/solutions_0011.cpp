#include <bits/stdc++.h>
using namespace std;
struct s {
  int l, r;
} ab[55], cd[55];
int c[2111];
int getnum(int x) {
  if (x <= 0) return 0;
  int rnt = 0;
  for (int i = x; i <= 2111; i += (i & (-i))) {
    rnt += c[i];
  }
  return rnt;
}
void add(int i, int a) {
  while (i >= 1) {
    c[i] += a;
    i -= (i & (-i));
  }
}
int main() {
  int p, q, l, r;
  scanf("%d%d%d%d", &p, &q, &l, &r);
  for (int i = 0; i < p; i++) scanf("%d%d", &ab[i].l, &ab[i].r);
  for (int i = 0; i < q; i++) scanf("%d%d", &cd[i].l, &cd[i].r);
  int ans = 0;
  for (int i = l; i <= r; i++) {
    memset(c, 0, sizeof(c));
    for (int j = 0; j < p; j++) {
      add(ab[j].r, 1);
      add(ab[j].l - 1, -1);
    }
    for (int j = 0; j < q; j++) {
      add(cd[j].r + i, 1);
      add(cd[j].l - 1 + i, -1);
    }
    for (int j = 1; j < 2111; j++) {
      if (getnum(j) > 1) {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
