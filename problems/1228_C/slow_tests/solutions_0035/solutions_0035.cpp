#include <bits/stdc++.h>
using namespace std;
long long int Mod = 1000000000 + 7;
long long int binpow(long long int a, long long int n) {
  long long int res = 1;
  while (n) {
    if (n & 1) res *= a, res %= Mod;
    a *= a;
    a %= Mod;
    n >>= 1;
  }
  return res;
}
int main() {
  long long int x, n;
  cin >> x >> n;
  long long int get = x;
  vector<long long int> dels;
  for (int i = 2; i <= sqrt(x); i++) {
    if (get % i == 0) {
      dels.push_back(i);
      while (get % i == 0) get /= i;
    }
  }
  if (get > 1) dels.push_back(get);
  long long int ans = 1;
  for (int i = 0; i < dels.size(); i++) {
    long long int power = 0, curr = n;
    do {
      power += curr / dels[i];
      curr /= dels[i];
    } while (curr);
    ans *= binpow(dels[i] % Mod, power);
    ans %= Mod;
  }
  cout << ans;
}
