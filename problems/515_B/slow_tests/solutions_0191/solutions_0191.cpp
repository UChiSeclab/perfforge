#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1e2 + 17, mod = 1e6;
bool a[Nmax] = {0}, b[Nmax] = {0};
int main(void) {
  int n, m, x, g, ans;
  scanf("%d%d", &n, &m);
  ans = n + m;
  scanf("%d", &g);
  for (int i = 0; i < g; i++) {
    scanf("%d", &x);
    a[x] = 1;
    ans--;
  }
  scanf("%d", &g);
  for (int i = 0; i < g; i++) {
    scanf("%d", &x);
    b[x] = 1;
    ans--;
  }
  int i = 0, z = 0, iter = 0;
  while (iter < mod && ans) {
    iter++;
    if (a[i] || b[z]) {
      if (a[i] == 0) ans--;
      if (b[z] == 0) ans--;
      a[i] = b[z] = 1;
    }
    i++;
    z++;
    if (i >= n) i -= n;
    if (z >= m) z -= m;
  }
  if (ans == 0)
    cout << "Yes";
  else
    cout << "No";
}
