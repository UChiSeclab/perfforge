#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int p(long long int x, long long int y, long long int p = 1e9 + 7) {
  long long int res = 1;
  x = x;
  while (y > 0) {
    if (y & 1) {
      res = (res * x);
    }
    x = (x * x);
    y = y >> 1;
  }
  return res;
}
void solve() {
  long long int k, l, m, n, d;
  cin >> k >> l >> m >> n >> d;
  if (k == 1 || l == 1 || m == 1) {
    cout << d;
    return;
  }
  long long int i, cnt = d;
  for (i = 1; i < d + 1; i++) {
    if ((i % k != 0) && (i % l != 0) && (i % m != 0) && (i % n != 0)) cnt--;
  }
  cout << cnt;
  return;
}
int main() {
  long long int t = 1, temp;
  for (temp = 0; temp < t; temp++) {
    solve();
  }
}
