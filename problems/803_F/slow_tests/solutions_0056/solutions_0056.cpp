#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
int n, x, a[N], p[N], f[N], ma = 0;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    ma = max(ma, x);
    a[x]++;
  }
  p[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = 2 * p[i - 1] % MOD;
  for (int i = 1; i <= ma; i++) {
    int s = 0;
    for (int j = i; j <= ma; j += i) s += a[j];
    f[i] = (p[s] - 1 + MOD) % MOD;
  }
  for (int i = ma; i > 0; i--) {
    for (int j = 2; i * j <= ma; j++) f[i] = (f[i] - f[i * j] + MOD) % MOD;
  }
  cout << f[1];
  return 0;
}
