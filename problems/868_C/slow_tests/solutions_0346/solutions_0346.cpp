#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int INF = (int)(1e9 + 1e6);
const long long LINF = (long long)(4e18);
const double EPS = 1e-9;
mt19937 ggen;
const int MOD = 1000000007;
int add(int a, int b, int m = MOD) {
  int res = a + b;
  if (res >= m) res -= m;
  return res;
}
int sub(int a, int b, int m = MOD) {
  int res = a - b;
  if (res < 0) res += m;
  return res;
}
int mul(int a, int b, int m = MOD) { return (long long)a * b % m; }
const int MAXN = 105000;
int k, n;
int mas[MAXN];
int full;
int c[MAXN];
void init() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < k; ++j) {
      int q;
      scanf("%d", &q);
      mas[i] <<= 1;
      mas[i] |= q;
    }
  }
}
bool check_mask(int mask) {
  int cnt[4] = {0, 0, 0, 0};
  int pr = 0;
  for (int i = 0; i < (1 << k); ++i) {
    if (mask & (1 << i)) {
      if (!c[i]) {
        return false;
      }
      ++pr;
      for (int j = 0; j < k; ++j) {
        if (i & (1 << j)) {
          ++cnt[j];
        }
      }
    }
  }
  for (int i = 0; i < k; ++i) {
    if (cnt[i] * 2 > pr) {
      return false;
    }
  }
  return true;
}
void solve() {
  init();
  full = (1 << k) - 1;
  for (int i = 1; i <= n; ++i) {
    ++c[mas[i]];
  }
  for (int mask = 1; mask <= (1 << full); ++mask) {
    if (check_mask(mask)) {
      printf("YES\n");
      return;
    }
  }
  printf("NO\n");
}
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  ggen = mt19937(1337);
  solve();
  return 0;
}
