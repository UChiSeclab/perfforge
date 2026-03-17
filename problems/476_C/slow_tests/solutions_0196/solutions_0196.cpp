#include <bits/stdc++.h>
using namespace std;
long long a, b, ans;
const int mod = (int)1e9 + 7;
inline long long qpow(long long a, long long b) {
  long long ans = 1;
  for (a %= mod; b; b >>= 1, a = a * a % mod)
    if (b & 1) ans = ans * a % mod;
  return ans;
}
int main() {
  scanf("%I64d%I64d", &a, &b);
  long long inv = qpow(2, mod - 2);
  for (int i = 1; i < b; ++i) {
    long long sum = ((b + 1) * i % mod + (a * b + 1) % mod * i % mod) % mod *
                    a % mod * inv % mod;
    ans = (ans + sum) % mod;
  }
  printf("%I64d\n", ans);
  return 0;
}
