#include <bits/stdc++.h>
using namespace std;
int A[100005], B[100005];
map<int, int> ma, maa;
int main(void) {
  int i, j, k, n, m, nn, mm, ans, res, pos, L, LL, beg, mod;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%d", A + i);
  }
  scanf("%d %d", &nn, &mm);
  for (i = 0; i < nn; i++) {
    scanf("%d", B + i);
  }
  ans = 2;
  for (pos = 1; pos < 1e9; pos <<= 1) {
    ma.clear();
    maa.clear();
    mod = pos * 2;
    for (i = 0; i < n; i++) {
      ma[A[i] % mod]++;
    }
    for (i = 0; i < nn; i++) {
      maa[B[i] % mod]++;
    }
    for (auto x : ma) {
      ans = max(ans, x.second + maa[x.first + pos]);
    }
    for (auto x : maa) {
      ans = max(ans, x.second + ma[x.first + pos]);
    }
  }
  printf("%d\n", ans);
}
