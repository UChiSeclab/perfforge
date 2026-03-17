#include <bits/stdc++.h>
using namespace std;
template <class t>
inline t read(t &x) {
  char c = getchar();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
const int N = 505;
int n, m, ans, f[N][N];
signed main() {
  read(n);
  read(m);
  f[0][0] = 1;
  for (int i = 1, x; i <= n; i++) {
    read(x);
    for (int j = m; j >= x; j--)
      for (int k = 500; k >= 0; k--) {
        if (k >= x) f[j][k] |= f[j - x][k - x];
        f[j][k] |= f[j - x][k];
      }
  }
  for (int i = 0; i <= m; i++)
    if (f[m][i]) ans++;
  write(ans);
  puts("");
  for (int i = 0; i <= m; i++)
    if (f[m][i]) write(i), putchar(' ');
}
