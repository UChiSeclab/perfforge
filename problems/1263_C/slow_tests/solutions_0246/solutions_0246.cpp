#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long ans[100010];
long long t, n, tot;
map<long long, bool> ma;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    ma.clear();
    tot = 0;
    cin >> n;
    ans[++tot] = 0;
    for (int i = 1; i * i <= n; ++i) {
      long long a = n / i;
      long long b = n / a;
      if (!ma[a]) {
        ma[a] = 1;
        ans[++tot] = a;
      }
      if (!ma[b]) {
        ma[b] = 1;
        ans[++tot] = b;
      }
    }
    sort(ans + 1, ans + 1 + tot);
    cout << tot << "\n";
    for (int i = 1; i <= tot; ++i) cout << ans[i] << " ";
    cout << "\n";
  }
  return 0;
}
