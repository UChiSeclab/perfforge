#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
vector<vector<long long>> mul(vector<vector<long long>> A,
                              vector<vector<long long>> B) {
  int n = A.size();
  vector<vector<long long>> C(n, vector<long long>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
      }
    }
  }
  return C;
}
vector<vector<long long>> id(int n) {
  vector<vector<long long>> C(n, vector<long long>(n));
  for (int i = 0; i < n; i++) C[i][i] = 1;
  return C;
}
vector<vector<long long>> matpow(vector<vector<long long>> A, long long e) {
  vector<vector<long long>> res = id(A.size());
  for (long long k = 1; k <= e; k *= 2) {
    if (k & e) res = mul(res, A);
    A = mul(A, A);
  }
  return res;
}
long long mpow(long long b, long long e) {
  long long res = 1;
  for (long long k = 1; k <= e; k *= 2) {
    if (k & e) res = (res * b) % MOD;
    b = (b * b) % MOD;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, L, R;
  cin >> n >> m >> L >> R;
  if ((n % 2) && (m % 2)) {
    cout << mpow(R - L + 1, m * n) << '\n';
    return 0;
  }
  long long ce = R / 2 - (L - 1) / 2, co = (R - L + 1) - ce;
  vector<vector<long long>> M = {{ce, co}, {co, ce}};
  M = matpow(M, (m * n) / 2LL);
  long long wo = M[0][0], we = M[1][0];
  cout << (wo * wo + we * we) % MOD << '\n';
}
