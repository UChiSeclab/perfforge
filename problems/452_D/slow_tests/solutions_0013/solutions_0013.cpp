#include <bits/stdc++.h>
using namespace std;
void RI() {}
template <typename... T>
void RI(int& head, T&... tail) {
  scanf("%d", &head);
  RI(tail...);
}
int n, m[5], t[5], c[5], x[10010], y[10010];
int main() {
  RI(n);
  for (int i = (1); i <= int(3); i++) RI(m[i]);
  for (int i = (1); i <= int(3); i++) RI(t[i]);
  m[0] = m[4] = c[0] = n;
  int ans = 0;
  while (1) {
    int mi = 1e9;
    for (int i = 0; i < int(n); i++)
      if (x[i] < 4 && c[x[i] + 1] < m[x[i] + 1]) {
        int dt = max(0, t[x[i]] - y[i]);
        if (dt < mi) mi = dt;
      }
    if (mi == 1e9) break;
    ans += mi;
    for (int i = 0; i < int(n); i++)
      if (x[i] < 4) {
        y[i] += mi;
        if (y[i] >= t[x[i]] && c[x[i] + 1] < m[x[i] + 1]) {
          c[x[i]]--;
          x[i]++;
          c[x[i]]++;
          y[i] = 0;
        }
      }
  }
  printf("%d\n", ans);
  return 0;
}
