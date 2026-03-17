#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int mod = 1000000007;
int Pow(int a, int b, int c) {
  int res = 1;
  while (b) {
    if (b & 1) res = (res * 1ll * a) % mod;
    a = (a * 1ll * a) % mod;
    b >>= 1;
  }
  return res;
}
int p[10];
int ans = 0;
void Solve(int n, int pos) {
  if (pos == n) {
    int cnt = 0, v = 0, ok = 1;
    for (int(i) = 0; (i) < (n); ++(i)) {
      v = i;
      cnt = 0;
      while (v && cnt <= n) {
        cnt++;
        v = p[v];
      }
      if (v) ok = false;
    }
    ans += ok;
  } else {
    for (int(i) = 0; (i) < (n); ++(i)) {
      p[pos] = i;
      Solve(n, pos + 1);
    }
  }
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  Solve(k, 0);
  printf("%d\n", int((ans * 1ll * Pow(n - k, n - k, mod)) % mod));
  return 0;
}
