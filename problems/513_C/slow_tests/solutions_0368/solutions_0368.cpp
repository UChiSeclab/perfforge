#include <bits/stdc++.h>
using namespace std;
int l[10], r[10], pl[10], pr[10];
void lemon() {
  double ansc = 0, ansv = 0;
  int n;
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) scanf("%d%d", &l[i], &r[i]);
  for (int price = (1); price <= (10000); price++)
    for (int who = (1); who <= (n); who++)
      if (l[who] <= price && price <= r[who]) {
        int all = 0;
        for (int i = (1); i <= (n); i++)
          if (who != i) {
            all++;
            pl[all] = l[i];
            pr[all] = r[i];
            if (i < who) {
              pr[all] = min(pr[all], price - 1);
            } else {
              pr[all] = min(pr[all], price);
            }
          }
        int flag = 1, maxlow = 0, maxhigh = 0;
        for (int i = (1); i <= (all); i++) {
          maxlow = max(maxlow, pl[i]);
          maxhigh = max(maxhigh, pr[i]);
          if (pl[i] > pr[i]) {
            flag = 0;
            break;
          }
        }
        if (!flag) continue;
        double lastway = 0;
        for (int sp = (maxlow); sp <= (maxhigh); sp++) {
          double cnt = 1;
          for (int i = (1); i <= (all); i++)
            cnt *= ((sp > pr[i] ? pr[i] : sp) - pl[i] + 1);
          ansv += (cnt - lastway) * sp;
          ansc += cnt - lastway;
          lastway = cnt;
        }
      }
  printf("%.15lf\n", ansv / ansc);
}
int main() {
  ios::sync_with_stdio(true);
  lemon();
  return 0;
}
