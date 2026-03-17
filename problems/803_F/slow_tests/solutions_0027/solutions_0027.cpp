#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int n;
long long f[100010], g[100010], s, sum, a[100010], v[100010];
long long faspow(long long a, long long b) {
  long long tmp = 1;
  while (b) {
    if (b & 1) tmp = tmp * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return tmp;
}
long long count(long long k) { return faspow(2, k) - 1; }
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    scanf("%lld", &a[i]), v[a[i]]++, s = max(s, a[i]);
  for (int i = 2; i <= s; i++)
    for (int j = 1; i * j <= s; j++) g[i] += v[i * j];
  f[s] = count(g[s]);
  sum += f[s];
  for (int i = s - 1; i >= 2; i--) {
    f[i] = count(g[i]);
    for (int j = 2; i * j <= s; j++) f[i] = (f[i] - f[i * j]) % mod;
    sum = (sum + f[i]) % mod;
  }
  cout << ((faspow(2, n) - sum - 1) % mod + mod) % mod;
  return 0;
}
