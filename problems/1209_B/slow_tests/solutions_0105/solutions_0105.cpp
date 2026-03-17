#include <bits/stdc++.h>
using namespace std;
void cases() {
  long long n, i, ans = 0, j, tg[200005] = {0}, k;
  string a;
  cin >> n >> a;
  for (i = 0; i < n; i++) a[i] -= '0';
  for (k = 0; k < n; k++) {
    long long x, y;
    cin >> x >> y;
    for (i = 0; i < y; i++) tg[i] += a[k];
    a[k] = 1 - a[k];
    for (i = y; i < 200005; i += x) {
      tg[i] += a[k];
      if (a[k]) {
        for (long long temp = i + 1; temp < i + x and temp < 200005; temp++)
          tg[temp]++;
      }
      a[k] = 1 - a[k];
    }
  }
  for (auto i : tg) ans = max(ans, i);
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cases();
  return 0;
}
