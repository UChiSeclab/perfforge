#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long A(long long B, long long C) {
  if (C == 0) return 1;
  if (C % 2) return (A(B, C - 1) * B) % MOD;
  long long X = A(B, C / 2);
  return (X * X) % MOD;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long X, N;
  cin >> X >> N;
  set<long long> Y;
  for (int i = 0; i < (50); i++)
    for (int j = 0; j < (sqrt(X) + 1); j++) {
      if (j > 1)
        if (X % j == 0) {
          X /= j;
          Y.insert(j);
          break;
        }
    }
  Y.insert(X);
  auto itr = Y.begin();
  long long ans = 1;
  for (int i = 0; i < (Y.size()); i++) {
    long long T = (*itr);
    long long TT = T;
    long long cnt = 0;
    if (T > 1)
      while (TT <= N) {
        cnt += N / TT;
        if (N / TT >= T)
          TT *= T;
        else
          break;
      }
    itr++;
    ans = (ans * A(T, cnt)) % MOD;
  }
  cout << ans << endl;
}
