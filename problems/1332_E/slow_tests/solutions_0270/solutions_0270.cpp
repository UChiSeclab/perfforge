#include <bits/stdc++.h>
using namespace std;
using row = vector<long long>;
using mat = vector<row>;
const int MOD = 998244353;
mat operator*(mat a, mat b) {
  mat ret = mat(a.size(), row(b[0].size()));
  for (int i = 0; i < ret.size(); i++)
    for (int j = 0; j < ret[i].size(); j++)
      for (int k = 0; k < ret[i].size(); k++)
        ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
  return ret;
}
mat operator^(mat b, long long p) {
  if (p == 1) return b;
  if (p & 1) return b * (b ^ (p - 1));
  return (b * b) ^ (p / 2);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, l, r;
  cin >> n >> m >> l >> r;
  int options = r - l + 1;
  int zeros = options / 2 + (l % 2 == 0 && r % 2 == 0);
  int ones = options - zeros;
  mat a = {{1, 0}};
  mat t = {{zeros, ones}, {ones, zeros}};
  a = (a * (t ^ (n * 1ll * m)));
  int ans = a[0][0];
  if (n & 1 && m & 1) ans = (ans + a[0][1]) % MOD;
  cout << ans;
}
