#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
long long powmod(long long a, long long b, long long MOD) {
  long long ans = 1;
  while (b) {
    if (b % 2) ans = ans * a % MOD;
    a = a * a % MOD;
    b /= 2;
  }
  return ans;
}
int bj, aa;
void dfs(int a) {
  if (!a) {
    bj = 1;
    return;
  }
  if (a >= 3) dfs(a - 3);
  if (a >= 7) dfs(a - 7);
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  for (cin >> t; t; t--) {
    cin >> aa;
    bj = 0;
    dfs(aa);
    if (!bj)
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
