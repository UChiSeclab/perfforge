#include <bits/stdc++.h>
using namespace std;
int n, x, y, c;
int u, d, l, r;
int ur, rd, dl, lu;
int cnt, step;
int main() {
  cin >> n >> x >> y >> c;
  cnt = 1;
  u = d = x;
  l = r = y;
  while (cnt < c) {
    step++;
    if (u != 0) u--;
    if (d != n + 1) d++;
    if (l != 0) l--;
    if (r != n + 1) r++;
    if (u != 0) cnt++;
    if (d != n + 1) cnt++;
    if (l != 0) cnt++;
    if (r != n + 1) cnt++;
    cnt += ur;
    cnt += rd;
    cnt += dl;
    cnt += lu;
    ur++;
    rd++;
    dl++;
    lu++;
    if (u == 0) lu--;
    if (u == 0) ur--;
    if (d == n + 1) rd--;
    if (d == n + 1) dl--;
    if (l == 0) dl--;
    if (l == 0) lu--;
    if (r == n + 1) ur--;
    if (r == n + 1) rd--;
    if (ur < 0) ur = 0;
    if (rd < 0) rd = 0;
    if (dl < 0) dl = 0;
    if (lu < 0) lu = 0;
  }
  cout << step << '\n';
  return 0;
}
