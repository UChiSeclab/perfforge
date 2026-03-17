#include <bits/stdc++.h>
using namespace std;
const long long int MAXN = 100000 + 7;
const long long int MOD = 1e09 + 7;
int v[MAXN], all[MAXN], f[MAXN], ans[MAXN];
int main() {
  int n;
  cin >> n;
  all[0] = 1;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    v[a]++;
    all[i] = (all[i - 1] << 1) % MOD;
    mx = max(mx, a);
  }
  for (int i = mx; i >= 1; i--) {
    for (int j = i; j <= mx; j += i) {
      f[i] += v[j];
      ans[i] = (ans[i] + MOD - ans[j]) % MOD;
    }
    ans[i] = (MOD + ans[i] + all[f[i]] - 1) % MOD;
  }
  cout << ans[1] << endl;
  return 0;
}
