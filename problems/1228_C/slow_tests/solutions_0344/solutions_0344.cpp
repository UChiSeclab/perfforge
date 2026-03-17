#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
long long x, n, cnt, pr[maxn];
long long quick(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cnt = 0;
  cin >> x >> n;
  long long tmp = x;
  for (long long i = 2; i <= sqrt(x); i++)
    if (tmp % i == 0) {
      pr[++cnt] = i;
      while (tmp % i == 0) tmp /= i;
    }
  if (tmp != 1) pr[++cnt] = tmp;
  long long ans = 1;
  for (long long i = 1; i <= cnt; i++) {
    long long sum = 0;
    tmp = n;
    while (tmp > 0) {
      sum += (tmp / pr[i]);
      tmp /= pr[i];
    }
    ans = (ans * quick(pr[i], sum)) % mod;
  }
  cout << ans << endl;
  return 0;
}
