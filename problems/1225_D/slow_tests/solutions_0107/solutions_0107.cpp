#include <bits/stdc++.h>
using namespace std;
const int N = 110000, base = 19260817, mod = 1e9 + 7;
unsigned long long ans, hsa[N], hsb[N];
int n, k, a[N], prime[N], nopr;
map<int, int> fac[N];
map<unsigned long long, long long> buc;
template <class T>
inline void read(T &x) {
  x = 0;
  char ch = getchar(), w = 0;
  while (!isdigit(ch)) w = ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  x = w ? -x : x;
  return;
}
inline long long quickpow(long long base, long long pw) {
  long long ret = 1;
  while (pw) {
    if (pw & 1) ret = ret * base;
    base = base * base, pw >>= 1;
  }
  return ret;
}
int main() {
  int maxA = 0;
  read(n), read(k);
  for (register int i = 1; i <= n; ++i) read(a[i]), maxA = max(maxA, a[i]);
  for (register int i = 2; i <= maxA; ++i) {
    if (fac[i].empty()) fac[i][i] = 1, prime[++nopr] = i;
    for (register int j = 1, k; j <= nopr && (k = i * prime[j]) <= maxA; ++j) {
      fac[k] = fac[i], ++fac[k][prime[j]];
      if (i % prime[j] == 0) break;
    }
    for (register auto j = fac[i].begin(); j != fac[i].end(); ++j) {
      if (j->second % k == 0) continue;
      hsa[i] = hsa[i] * base ^ quickpow(j->first, j->second % k) % base;
      hsb[i] =
          hsb[i] * base ^ quickpow(j->first, (k - j->second % k) % k) % base;
    }
  }
  for (register int i = 1; i <= n; ++i) ans += buc[hsb[a[i]]], ++buc[hsa[a[i]]];
  cout << ans << endl;
  return 0;
}
