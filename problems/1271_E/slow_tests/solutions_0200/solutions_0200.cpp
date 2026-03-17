#include <bits/stdc++.h>
using namespace std;
const int LOG = 60;
int bit(long long mask, int k) { return (mask >> k) & 1; }
void printm(long long mask) {
  for (int k = 0; k < 5; ++k) printf("%d", bit(mask, k));
  printf("\n");
}
long long pw(int k) {
  if (k < 0) return 0;
  return 1LL << k;
}
long long get2(long long x, long long n, int k) {
  if (x > n) return 0;
  int pos = LOG;
  while (pos >= 0 && bit(n, pos) == bit(x, pos)) --pos;
  long long res;
  if (pos >= k)
    res = 1LL << k;
  else
    res = n - x + 1;
  return res;
}
long long get(long long x, long long n, int k) {
  long long res = 0;
  for (int i = 0; i <= LOG - k + 1; ++i) res += get2(x << i, n, i);
  if (x % 2 == 0) {
    x ^= 1;
    for (int i = 0; i <= LOG - k + 1; ++i) res += get2(x << i, n, i);
    x ^= 1;
  }
  return res;
}
int main() {
  long long n, k;
  scanf("%lld %lld", &n, &k);
  long long ans = 0;
  for (int i = LOG; i >= 0; --i) {
    long long cur = 1LL << i;
    if (get(cur, n, i + 1) < k) continue;
    for (int j = i - 1; j >= 0; --j) {
      cur ^= 1LL << j;
      if (get(cur, n, i + 1) < k) cur ^= 1LL << j;
    }
    printf("%lld\n", cur);
    return 0;
  }
}
