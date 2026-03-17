#include <bits/stdc++.h>
using namespace std;
int const MAXn = 5e5 + 2, MOD = 998244353;
long long fact[MAXn];
long long qp(long long a, long long e) {
  if (e == 0) return 1;
  if (e == 1) return a;
  if (!(e & 1)) {
    a = qp(a, e / 2);
    return a * a % MOD;
  }
  return a * qp(a, e - 1) % MOD;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  if (k > n) {
    cout << 0 << "\n";
    return 0;
  }
  fact[0] = 1;
  for (long long i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
  long long sol = 0;
  for (int i = 1; i <= n; i++) {
    long long x = n / i;
    if (x < k) break;
    sol =
        (sol + (fact[x - 1] *
                qp(fact[x - 1 - (k - 1)] * fact[k - 1] % MOD, MOD - 2) % MOD)) %
        MOD;
  }
  cout << sol << "\n";
  return 0;
}
