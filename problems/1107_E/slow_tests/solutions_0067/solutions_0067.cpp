#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n;
long long a[N], f[N][N][2][N];
int c[N];
void cmax(long long &x, long long y) { x = max(y, x); }
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    char ch;
    cin >> ch;
    c[i] = ch - '0';
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 0; j < i; j++) a[i] = max(a[j] + a[i - j], a[i]);
  }
  memset(f, -0x3f, sizeof(f));
  for (int i = 1; i <= n; i++) {
    f[i][i][0][0] = f[i][i][1][0] = a[1];
    f[i][i][c[i]][1] = 0;
  }
  for (int len = 2; len <= n; len++)
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      for (int k = 0; k <= n; k++) {
        for (int cut = i; cut < j; cut++) {
          if (k)
            cmax(f[i][j][0][k], f[i][cut][0][k - 1] + f[cut + 1][j][0][1]),
                cmax(f[i][j][1][k], f[i][cut][1][k - 1] + f[cut + 1][j][1][1]);
          cmax(f[i][j][0][k], f[i][cut][0][k] + f[cut + 1][j][0][0]);
          cmax(f[i][j][1][k], f[i][cut][1][k] + f[cut + 1][j][0][0]);
          cmax(f[i][j][0][0], f[i][j][0][k] + a[k]);
          cmax(f[i][j][0][0], f[i][j][1][k] + a[k]);
        }
        for (int cut = j; cut < k; cut++) {
          if (k)
            cmax(f[i][j][0][k], f[i][cut][0][1] + f[cut + 1][j][0][k - 1]),
                cmax(f[i][j][1][k], f[i][cut][1][1] + f[cut + 1][j][1][k - 1]);
          cmax(f[i][j][0][k], f[i][cut][0][0] + f[cut + 1][j][0][k]);
          cmax(f[i][j][1][k], f[i][cut][0][0] + f[cut + 1][j][1][k]);
          cmax(f[i][j][0][0], f[i][j][0][k] + a[k]);
          cmax(f[i][j][0][0], f[i][j][1][k] + a[k]);
        }
      }
      f[i][j][1][0] = f[i][j][0][0];
    }
  cout << f[1][n][0][0] << endl;
  return 0;
}
