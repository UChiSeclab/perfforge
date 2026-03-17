#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int M = 1e2 + 30;
const int N = 1003;
const int mo = 1e9 + 7;
const LL inf = 1e16 + 1;
LL qpow(LL a, LL b) {
  LL res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mo;
    b >>= 1;
    a = a * a % mo;
  }
  return res;
}
char s[M][M];
int a[M];
int vis[M];
LL res = 0;
bool check(int u, int n) {
  for (int i = 1; i <= n; i++) vis[i] = 0;
  while (!vis[u]) {
    if (u == 1) return true;
    vis[u] = 1;
    u = a[u];
  }
  return false;
}
void dfs(int u, int n) {
  if (u > n) {
    int flag = 0;
    for (int i = 1; i <= n; i++) {
      if (!check(i, n)) {
        flag = 1;
        break;
      }
    }
    if (!flag) res++;
    return;
  }
  for (int i = 1; i <= n; i++) {
    a[u] = i;
    dfs(u + 1, n);
  }
}
void test() {
  for (int n = 2; n <= 6; n++) {
    cout << n << ": ";
    res = 0;
    dfs(1, n);
    cout << res << endl;
  }
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  LL tmp = qpow(n - k, n - k);
  dfs(1, k);
  res = res * tmp % mo;
  printf("%I64d\n", res);
  return 0;
}
