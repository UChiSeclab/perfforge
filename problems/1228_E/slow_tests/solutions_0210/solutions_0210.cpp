#include <bits/stdc++.h>
using namespace std;
long long ncr[255][255], dp[255][255];
long long mod = 1000000007;
long long bigmod(long long n, long long po) {
  if (po == 0) return 1;
  if (po == 1) return n % mod;
  if (po % 2 == 0) {
    long long ret = bigmod(n, po / 2);
    ret *= ret;
    return ret % mod;
  }
  long long ret = bigmod(n, po - 1);
  ret *= (n % mod);
  return ret % mod;
}
long long NCR(int n, int r) {
  if (r == 0) return 1;
  if (n == r) return 1;
  if (r == 1) return n;
  if (ncr[n][r] != -1) return ncr[n][r];
  long long ret = 0;
  ret += NCR(n - 1, r);
  ret %= mod;
  ret += NCR(n - 1, r - 1);
  ret %= mod;
  return ncr[n][r] = ret;
}
int n, k;
long long po1[255], po2[255];
long long solve(int id, int col) {
  if (id == n) {
    return (col == 0);
  }
  if (dp[id][col] != -1) return dp[id][col];
  long long ret = 0;
  for (int i = 1; i <= n - col; i++) {
    long long z = NCR(n - col, i);
    long long pp = po2[n - i];
    long long ppp = solve(id + 1, col);
    z *= pp;
    z %= mod;
    z *= ppp;
    z %= mod;
    ret += z;
    ret %= mod;
  }
  for (int i = 1; i <= col; i++) {
    long long p = NCR(col, i);
    long long pp = po2[col - i];
    long long ppp = po1[n - col];
    p *= pp;
    p %= mod;
    p *= ppp;
    p %= mod;
    long long z = solve(id + 1, col - i);
    p *= z;
    p %= mod;
    ret += p;
    ret %= mod;
  }
  return dp[id][col] = ret;
}
int main() {
  memset(ncr, -1, sizeof(ncr));
  memset(dp, -1, sizeof(dp));
  cin >> n >> k;
  po1[0] = 1;
  for (int i = 1; i <= n; i++) {
    po1[i] = po1[i - 1] * k;
    po1[i] %= mod;
  }
  po2[0] = 1;
  for (int i = 1; i <= n; i++) {
    po2[i] = po2[i - 1] * (k - 1);
    po2[i] %= mod;
  }
  if (n == 1 || k == 1) {
    cout << "1" << endl;
    return 0;
  }
  long long ans = solve(0, n);
  cout << ans;
}
