#include <bits/stdc++.h>
using namespace std;
int n, k, x, t = 0, s = 1;
const int maxn = 2e3 + 5;
int f[2][maxn];
int main() {
  cin >> n >> k >> x;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    f[t][x]++;
  }
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < maxn; ++j) f[s][j] = 0;
    int num = 0;
    for (int j = 0; j < maxn; ++j) {
      f[s][j] += (f[t][j] + num) / 2;
      f[s][j ^ x] += (f[t][j] + 1 - num) / 2;
      num = (num + f[t][j]) % 2;
    }
    swap(t, s);
  }
  int mn = maxn, mx = 0;
  for (int i = 0; i < maxn; ++i) {
    if (f[t][i]) {
      mn = min(mn, i);
      mx = max(mx, i);
    }
  }
  cout << mx << ' ' << mn << endl;
  return 0;
}
