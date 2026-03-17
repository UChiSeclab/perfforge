#include <bits/stdc++.h>
using namespace std;
long long D, u, v, w, mod = 998244353;
int q;
vector<long long> p;
long long fak[60], faki[60];
long long fpb(long long x, long long y) {
  if (x == 0) return y;
  return fpb(y % x, x);
}
long long pang(long long x, long long y) {
  if (y == 0) {
    return 1;
  }
  long long ret;
  ret = pang(x, y / 2);
  ret *= ret;
  ret %= mod;
  if (y % 2 == 0) {
    return ret;
  } else {
    return (x * ret) % mod;
  }
}
long long f(long long x) {
  if (x == 1) return 1;
  int po, tot = 0;
  vector<long long> v;
  for (long long i : p) {
    if (i > x) {
      if (x > 1) {
        v.push_back(1);
        tot++;
      }
      break;
    }
    po = 0;
    while (x % i == 0) {
      po++;
      x /= i;
    }
    if (po != 0) v.push_back(po);
    tot += po;
  }
  long long ret;
  ret = fak[tot];
  for (long long k : v) {
    ret *= faki[k];
    ret %= mod;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  cin >> D >> q;
  int d = sqrt(D);
  for (long long i = 2; i <= d; i++) {
    if (D % i == 0) {
      p.push_back(i);
    }
    while (D % i == 0) {
      D /= i;
    }
  }
  if (D > 1) {
    p.push_back(D);
  }
  long long ans;
  fak[0] = 1;
  for (int i = 1; i <= 50; i++) {
    fak[i] = (fak[i - 1] * i) % mod;
    faki[i] = pang(fak[i], mod - 2);
  }
  while (q--) {
    cin >> u >> v;
    w = fpb(u, v);
    ans = (f(u / w) * f(v / w)) % mod;
    cout << ans << endl;
  }
}
