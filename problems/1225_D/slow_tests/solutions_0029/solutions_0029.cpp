#include <bits/stdc++.h>
using namespace std;
int power(int a, int b, int c, int ans = 1) {
  for (; b; b >>= 1, a = (long long)a * a % c)
    if (b & 1) ans = (long long)ans * a % c;
  return ans;
}
const int NN = 100100;
int a[NN], flag[NN], prime[NN], np, qf, qb, deg[111], fac[111];
long long q[NN];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  if (k > 32) {
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += a[i] == 1;
    printf("%I64d\n", (long long)cnt * (cnt - 1) / 2);
    return 0;
  }
  map<long long, int> mp;
  for (int i = 0; i < n; i++) mp[a[i]]++;
  sort(a, a + n);
  long long ans = 0;
  for (int i = 2; i < NN; i++) {
    if (!flag[i]) prime[np++] = i, flag[i] = i;
    for (int j = 0; j < np && prime[j] <= flag[i] && prime[j] * i < NN; j++)
      flag[i * prime[j]] = prime[j];
  }
  for (int first = 1;; first++) {
    if (log(first) * k > log(10) * 10 + 1e-5) break;
    int cnt = 0;
    for (int u = first; u > 1;) {
      int v = flag[u];
      deg[cnt] = 0;
      while (flag[u] == v) u /= v, deg[cnt]++;
      deg[cnt] *= k;
      fac[cnt++] = v;
    }
    qb = 0;
    q[qb++] = 1;
    for (int i = 0; i < cnt; i++) {
      for (int j = 0, z = qb; j < z; j++) {
        long long mid = 1;
        for (int k = 0; k < deg[i]; k++) {
          mid *= fac[i];
          q[qb++] = q[j] * mid;
        }
      }
    }
    long long N = q[qb - 1];
    for (int i = 0; i < qb; i++)
      if (q[i] * q[i] <= N) {
        if (mp.count(q[i]) && mp.count(N / q[i])) {
          long long t = mp[q[i]], t1 = mp[N / q[i]];
          if (q[i] * q[i] == N)
            ans += t * (t - 1) / 2;
          else
            ans += t * t1;
        }
      }
  }
  cout << ans << endl;
  return 0;
}
