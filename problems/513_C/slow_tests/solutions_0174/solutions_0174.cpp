#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9, maxn = (int)1e5 + 1;
const double eps = (double)1e-8;
const int mod = (int)1000000009;
int i, n, l[10], r[10];
double s, v, ans;
void dzen(double tv, int x, int t) {
  if (x == n + 1 && t >= 2) {
    v += tv;
    return;
  }
  if (l[x] <= i && r[x] >= i) {
    dzen(tv / double(r[x] - l[x] + 1), x + 1, t + 1);
  }
  if (l[x] < i) {
    dzen(tv * (double(min(r[x] + 1, i) - l[x]) / (r[x] - l[x] + 1)), x + 1, t);
  }
  return;
}
void glen(double tv, int x, int t1, int t2) {
  if (x == n + 1 && t1 == 1 && t2 == 1) {
    v += tv;
    return;
  }
  if (l[x] <= i && r[x] >= i) {
    glen(tv / double(r[x] - l[x] + 1), x + 1, 1, t2);
  }
  if (l[x] < i) {
    glen(tv * (double(min(r[x] + 1, i) - l[x]) / (r[x] - l[x] + 1)), x + 1, t1,
         t2);
  }
  if (r[x] > i && t2 == 0) {
    glen(tv * (double(r[x] - max(l[x] - 1, i)) / (r[x] - l[x] + 1)), x + 1, t1,
         1);
  }
  return;
}
int main() {
  cout << fixed << setprecision(10);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  for (i = 1; i <= 10000; i++) {
    v = 0;
    dzen(1, 1, 0);
    glen(1, 1, 0, 0);
    ans += v * i;
  }
  cout << ans;
  return 0;
}
