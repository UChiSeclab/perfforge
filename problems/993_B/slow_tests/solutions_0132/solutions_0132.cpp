#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
int a[N], b[N], cnt[N], useda[N], usedb[N], c[N], d[N], gooda[N], goodb[N],
    wwa[N], wwb[N];
int n, m;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
  for (int i = 1; i <= m; i++) cin >> c[i] >> d[i];
  int it = 0;
  while (n > 0 && m > 0 && it < 100) {
    for (int i = 1; i <= 12; i++)
      useda[i] = usedb[i] = cnt[i] = 0, gooda[i] = 1, goodb[i] = 1, wwa[i] = -1;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        int t = 0;
        if (a[i] == c[j]) t++;
        if (b[i] == c[j]) t++;
        if (a[i] == d[j]) t++;
        if (b[i] == d[j]) t++;
        if (t == 1) {
          useda[i]++;
          usedb[j]++;
          if (a[i] == c[j]) t = a[i];
          if (b[i] == c[j]) t = b[i];
          if (a[i] == d[j]) t = a[i];
          if (b[i] == d[j]) t = b[i];
          cnt[t]++;
          if (useda[i] >= 2 && t != wwa[i]) gooda[i] = 0;
          if (usedb[j] >= 2 && t != wwb[j]) goodb[j] = 0;
          wwa[i] = t;
          wwb[j] = t;
        }
      }
    int q = 0, last;
    for (int i = 1; i <= 12; i++)
      if (cnt[i] > 0) {
        q++;
        last = i;
      }
    if (q == 1) {
      cout << last << "\n";
      return 0;
    }
    int cn = 0;
    for (int i = 1; i <= n; i++)
      if (useda[i]) {
        cn++;
        a[cn] = a[i];
        b[cn] = b[i];
      }
    n = cn;
    cn = 0;
    for (int i = 1; i <= m; i++)
      if (usedb[i]) {
        cn++;
        c[cn] = c[i];
        d[cn] = d[i];
      }
    m = cn;
    it++;
  }
  int ok = 0;
  for (int i = 1; i <= n; i++)
    if (gooda[i]) ok++;
  for (int i = 1; i <= m; i++)
    if (goodb[i]) ok++;
  if (ok == n + m) {
    cout << "0\n";
    return 0;
  } else
    cout << "-1\n";
  return 0;
}
