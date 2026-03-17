#include <bits/stdc++.h>
using namespace std;
int n, m, x;
int ans(int x) {
  int summ = 0;
  int stx = n;
  int sty = m;
  stx -= 2 * x;
  sty -= 2 * x;
  for (int i = 0; i < stx; i++)
    for (int j = 0; j < sty; j++)
      if ((i + j) % 2 == 0) summ++;
  return summ;
}
int main() {
  cin >> n >> m >> x;
  x--;
  cout << ans(x) - ans(x + 1);
  return 0;
}
