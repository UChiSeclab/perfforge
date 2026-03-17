#include <bits/stdc++.h>
using namespace std;
int m, a, b, h[10010];
long long ans;
int main() {
  cin >> m >> b;
  for (int i = 0; i <= b; i++) h[i] = (b - i) * m;
  for (int i = 0; i <= b; i++) {
    long long tot = 0;
    for (int j = 0; j <= i; j++)
      tot += 1ll * h[i] * (h[i] + 1) / 2 + 1ll * (h[i] + 1) * j;
    ans = max(ans, tot);
  }
  cout << ans;
  return 0;
}
