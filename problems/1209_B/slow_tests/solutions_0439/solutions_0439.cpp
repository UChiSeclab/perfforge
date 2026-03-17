#include <bits/stdc++.h>
using namespace std;
long long n, a, b;
long long f[105];
long long x;
char s[105];
long long B[105];
long long C[105];
long long in[105];
signed main() {
  scanf("%I64d", &n);
  ;
  scanf("%s", s);
  for (long long i = 0; i < n; i++) {
    scanf("%I64d", &B[i]);
    ;
    scanf("%I64d", &C[i]);
    ;
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    in[i] = f[i] = s[i] - '0';
    if (f[i]) ans++;
  }
  long long t = 0;
  for (long long i = 1; i <= 500; i++) {
    t = 0;
    for (long long j = 0; j < n; j++) {
      if (i >= C[j] && (((i - C[j]) % B[j]) == 0)) f[j] ^= 1;
      if (f[j]) t++;
    }
    ans = max(ans, t);
    if (ans == n) break;
  }
  cout << ans << '\n';
}
