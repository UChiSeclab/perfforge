#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int N = 501;
long long pd[2][N][N];
int n, m, b;
long long mod;
long long v[N];
long long func(int pos, int qtd, int lin) {
  if (qtd > b) return 0;
  if (lin > m) return 0;
  if (pos == n) return (qtd <= b && lin == m);
  if (pd[pos & 1][qtd][lin] != -1) return pd[pos & 1][qtd][lin];
  long long ret = func(pos + 1, qtd, lin) + func(pos, qtd + v[pos], lin + 1);
  while (ret >= mod) ret -= mod;
  return pd[pos & 1][qtd][lin] = ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> b >> mod;
  for (int i = 0; i < n; ++i) cin >> v[i];
  memset(pd, -1, sizeof pd);
  for (int i = n; i >= 0; --i) {
    for (int j = 0; j <= b; ++j)
      for (int k = 0; k <= m; ++k) pd[i & 1][j][k] = -1;
    for (int j = b; j >= 0; --j)
      for (int k = m; k >= 0; --k) func(i, j, k);
  }
  cout << func(0, 0, 0) << endl;
  return 0;
}
