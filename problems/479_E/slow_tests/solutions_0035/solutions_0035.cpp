#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int n, a, b, k, mod = 1e9 + 7;
  cin >> n >> a >> b >> k;
  long long int f[n + 2], temp[n + 2];
  memset(f, 0, sizeof(f));
  memset(temp, 0, sizeof(temp));
  if (b > a) {
    for (int i = a; i < b; i++) f[i] = 1;
    for (int i = 0; i < k; i++) {
      for (int j = 1; j < b; j++) {
        long long int ind = (b + j) / 2;
        if (ind * 2 == b + j) ind--;
        temp[j] += (f[ind] - f[j] + mod) % mod;
        temp[j] += f[j - 1];
      }
      for (int j = 1; j < b; j++) f[j] = temp[j] % mod, temp[j] = 0;
      for (int j = 1; j < b; j++) f[j] = (f[j] + f[j - 1]) % mod;
    }
    cout << f[b - 1] << endl;
    return 0;
  }
  for (int i = a; i <= n; i++) f[i] = 1;
  for (int i = 0; i < k; i++) {
    for (int j = b + 1; j <= n; j++) {
      temp[j] += (f[n] - f[j] + mod) % mod;
      ;
      long long int ind = (b + j) / 2;
      temp[j] += (f[j - 1] - f[ind] + mod) % mod;
    }
    for (int j = b + 1; j <= n; j++) f[j] = temp[j] % mod, temp[j] = 0;
    for (int j = b + 1; j <= n; j++) f[j] = (f[j] + f[j - 1]) % mod;
  }
  cout << f[n] << endl;
  return 0;
}
