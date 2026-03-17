#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long n, m, L, R;
struct S {
  long long x, pe, po;
};
bool operator<(const S self, const S other) {
  if (self.x == other.x)
    return (self.pe == other.pe ? self.po < other.po : self.pe < other.pe);
  return self.x < other.x;
}
map<S, long long> M;
long long binpow(long long x, long long pw) {
  if (pw == 1) return x;
  if (pw == 0) return 1;
  if (pw % 2 == 1) return x * binpow(x, pw - 1) % MOD;
  long long k = binpow(x, pw / 2);
  return k * k % MOD;
}
long long ans(long long cnt, bool pe, bool po) {
  if (M.count({cnt, pe, po})) return M[{cnt, pe, po}];
  if (cnt % 2 == 1) {
    if (pe == po) return 0;
    M[{cnt, pe, po}] = (ans(cnt - 1, 0, 0) * ans(1, pe, po) +
                        ans(cnt - 1, 1, 1) * ans(1, pe ^ 1, po ^ 1)) %
                       MOD;
    return M[{cnt, pe, po}];
  }
  if (cnt % 2 == 0) {
    if (pe != po) return 0;
    if (pe) {
      M[{cnt, pe, po}] = (ans(cnt / 2, 0, 1) * ans(cnt / 2, 1, 0) * 2 +
                          ans(cnt / 2, 0, 0) * ans(cnt / 2, 1, 1) * 2) %
                         MOD;
    } else {
      M[{cnt, pe, po}] =
          (binpow(ans(cnt / 2, 0, 0), 2) + binpow(ans(cnt / 2, 1, 1), 2) +
           binpow(ans(cnt / 2, 0, 1), 2) + binpow(ans(cnt / 2, 1, 0), 2)) %
          MOD;
    }
    return M[{cnt, pe, po}];
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> L >> R;
  M[{1, 0, 1}] = (R - L + 1) / 2 + (L % 2 == R % 2 && R % 2 == 1);
  M[{1, 1, 0}] = (R - L + 1) / 2 + (L % 2 == R % 2 && R % 2 == 0);
  if (n * m % 2 == 1) {
    cout << binpow(R - L + 1, n * m);
    return 0;
  }
  cout << ans(n * m, 0, 0) << "\n";
}
