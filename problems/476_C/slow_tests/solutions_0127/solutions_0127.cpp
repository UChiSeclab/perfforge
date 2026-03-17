#include <bits/stdc++.h>
using namespace std;
long long fst, lst, val, ans, a, b;
long long mag;
long long pw(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2) return a * pw(a, b - 1) % 1000000007;
  return pw(a * a % 1000000007, b / 2);
}
long long inv(long long x) { return pw(x, 1000000007 - 2); }
int main() {
  ios_base::sync_with_stdio(0);
  cin >> a >> b;
  mag = inv(2);
  for (int rem = 1; rem < b; rem++) {
    fst = rem * b + rem;
    fst %= 1000000007;
    lst = ((rem * a) % 1000000007 * b) % 1000000007 + rem;
    lst %= 1000000007;
    val = fst + lst;
    val *= a;
    val %= 1000000007;
    val *= mag;
    val %= 1000000007;
    ans += val;
    ans %= 1000000007;
  }
  cout << ans << endl;
  cin.get();
  cin.get();
  return 0;
}
