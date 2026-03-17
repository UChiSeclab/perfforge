#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long K[5050], D[5050];
int T[5050][5050];
long long n, k, ans;
long long mypow(long long a, long long b) {
  if (!b) return 1;
  long long ret = mypow(a, b >> 1);
  ret *= ret;
  ret %= mod;
  return ret * (b & 1 ? a : 1) % mod;
}
int main() {
  long long i, j, s;
  scanf("%lld%lld", &n, &k);
  if (n < k) {
    T[0][0] = 1;
    for (i = 1; i <= n; i++) {
      T[i][0] = 1;
      for (j = 1; j <= i; j++)
        T[i][j] = ((long long)T[i - 1][j] + (long long)T[i - 1][j - 1]) % mod;
    }
    for (i = 0; i <= n; i++) {
      ans = (ans + (long long)T[n][i] * mypow(i, k)) % mod;
    }
    printf("%lld\n", ans);
    return 0;
  }
  T[0][0] = s = 1;
  for (i = 1; i <= k; i++) {
    s = s * (n - i + 1) % mod;
    K[i] = (s * mypow(2, n - i)) % mod;
    for (j = 0; j < i; j++) {
      T[i][j] = (((long long)T[i][j] - (i - 1) * (long long)T[i - 1][j]) % mod +
                 mod) %
                mod;
      T[i][j + 1] = ((long long)T[i][j + 1] + (long long)T[i - 1][j]) % mod;
    }
  }
  D[k] = -1;
  for (i = k; i >= 0; i--) {
    s = -D[i];
    ans = ((ans + s * K[i]) % mod + mod) % mod;
    for (j = 0; j <= i; j++)
      D[j] = ((D[j] + s * (long long)T[i][j]) % mod + mod) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
