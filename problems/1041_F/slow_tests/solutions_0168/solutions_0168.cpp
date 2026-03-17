#include <bits/stdc++.h>
using namespace std;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const long double eps = 1e-8;
long long read() {
  long long n = 0;
  char a = getchar();
  bool flag = 0;
  while (a > '9' || a < '0') {
    if (a == '-') flag = 1;
    a = getchar();
  }
  while (a <= '9' && a >= '0') {
    n = n * 10 + a - '0', a = getchar();
  }
  if (flag) n = -n;
  return n;
}
long long n, m, a[SZ], b[SZ];
unordered_map<long long, long long> A[33], B[33];
int main() {
  int n = read(), y1 = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  int m = read(), y2 = read();
  for (int i = 1; i <= m; i++) b[i] = read();
  long long d = 1;
  for (int i = 1; i <= n; i++) {
    for (long long j = 1; (1 << j) <= 1e9; j++) A[j][a[i] % ((1 << j) * d)]++;
  }
  for (int i = 1; i <= m; i++) {
    for (long long j = 1; (1 << j) <= 1e9; j++) B[j][b[i] % ((1 << j) * d)]++;
  }
  long long ans = 2;
  for (int i = 1; i <= n; i++) {
    for (long long j = 1; (1 << j) <= 1e9; j++) {
      long long p = (1 << j) * d;
      ans = max(ans, A[j][a[i] % p] + B[j][(a[i] + p / 2) % p]);
    }
  }
  for (int i = 1; i <= m; i++) {
    for (long long j = 1; (1 << j) <= 1e9; j++) {
      long long p = (1 << j) * d;
      ans = max(ans, B[j][b[i] % p] + A[j][(b[i] + p / 2) % p]);
    }
  }
  cout << ans << endl;
  return 0;
}
