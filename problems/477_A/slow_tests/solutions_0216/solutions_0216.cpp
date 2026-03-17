#include <bits/stdc++.h>
using namespace std;
const int P = 1000000007;
int a, b, mo, ans, _2;
int Pow(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = 1ll * a * a % P)
    if (b & 1) res = 1ll * res * a % P;
  return res;
}
int calc(int a0, int d, int n) {
  int an = a0 + 1ll * d * (n - 1) % P;
  an %= P;
  int res = (a0 + an) % P * 1ll * n % P * 1ll * _2 % P;
  return res;
}
int main() {
  scanf("%d%d", &a, &b);
  _2 = Pow(2, P - 2);
  for (mo = 1; mo < b; mo++) {
    ans += calc((mo + 1ll * b * mo) % P, (1ll * b * mo) % P, a);
    if (ans >= P) ans -= P;
  }
  printf("%d\n", ans);
}
