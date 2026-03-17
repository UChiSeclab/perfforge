#include <bits/stdc++.h>
using namespace std;
const int maxk = 1e3 + 7;
const int p = 1000000007;
int k;
int c[maxk];
long long dp[maxk];
int cnt;
long long n, m;
long long quick_mod(long long a, long long b) {
  long long ans = 1;
  a %= p;
  while (b) {
    if (b & 1) {
      ans = ans * a % p;
      b--;
    }
    b >>= 1;
    a = a * a % p;
  }
  return ans;
}
long long C(long long n, long long m) {
  if (m > n) return 0;
  long long ans = 1;
  for (int i = 1; i <= m; i++) {
    long long a = (n + i - m) % p;
    long long b = i % p;
    ans = ans * (a * quick_mod(b, p - 2) % p) % p;
  }
  return ans;
}
long long Lucas(long long n, long long m) {
  if (m == 0) return 1;
  return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}
long long fun(long long x) {
  long long ans = 0;
  for (int i = 0; i < x - 1; i++) {
    long long t = Lucas(x - 2, i);
    long long y = Lucas(cnt + 1, i + 1);
    ans = (ans % p + (t % p * y % p) % p) % p;
  }
  if (!ans) return 1ll;
  return ans;
}
void solve() {
  dp[0] = 1;
  cnt = c[0];
  for (int i = 1; i < k; i++) {
    dp[i] = dp[i - 1] * fun(c[i]) % p;
    cnt += c[i];
  }
  cout << dp[k - 1] << endl;
}
int main() {
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> c[i];
  }
  solve();
}
