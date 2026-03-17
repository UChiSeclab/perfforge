#include <bits/stdc++.h>
using namespace std;
int v, a[11], f[1000005];
int rec(int r) {
  int& res = f[r];
  if (res != -1) {
    return res;
  }
  res = 0;
  for (int d = 1; d <= 9; ++d) {
    if (a[d] <= r) {
      res = max(res, 1 + rec(r - a[d]));
    }
  }
  return res;
}
void printAns(int r) {
  int best = 0, d = 0;
  for (int i = 1; i <= 9; ++i) {
    if (a[i] <= r && best <= f[r - a[i]]) {
      best = f[r - a[i]];
      d = i;
    }
  }
  if (!d) return;
  cout << d;
  printAns(r - a[d]);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> v;
  for (int i = 1; i <= 9; ++i) {
    cin >> a[i];
  }
  memset(f, -1, sizeof f);
  rec(v);
  if (f[v] == 0) {
    cout << -1;
    return 0;
  }
  printAns(v);
  return 0;
}
