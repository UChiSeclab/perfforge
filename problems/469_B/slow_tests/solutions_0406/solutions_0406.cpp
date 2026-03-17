#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;
bool mark[maxn];
int p, q, l, r;
int d[maxn], c[maxn];
int ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> p >> q >> l >> r;
  for (int i = 1; i <= p; i++) {
    int a, b;
    cin >> a >> b;
    for (int j = a; j <= b; j++) mark[j] = true;
  }
  for (int i = 1; i <= q; i++) cin >> c[i] >> d[i];
  for (int i = l; i <= r; i++) {
    bool f = 0;
    for (int j = 1; j <= q; j++) {
      int le = c[j] + i;
      int ri = d[j] + i;
      for (int k = le; k <= ri; k++) {
        if (mark[k]) f = true;
      }
    }
    if (f) ans++;
  }
  cout << ans << endl;
  return 0;
}
