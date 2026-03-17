#include <bits/stdc++.h>
using namespace std;
const int N = 501;
int n, m, b, mod, a[N], F[2][N][N];
void enter() {
  cin >> n >> m >> b >> mod;
  for (int i = 1; i <= n; i++) cin >> a[i];
}
void process() {
  F[0][0][0] = 1;
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= b; k++) {
        if (j < n)
          F[i % 2][j + 1][k] = (F[i % 2][j + 1][k] + F[i % 2][j][k]) % mod;
        if (i < m && j < n && a[j + 1] + k <= b)
          F[(i + 1) % 2][j][k + a[j + 1]] =
              (F[(i + 1) % 2][j][k + a[j + 1]] + F[i % 2][j][k]) % mod;
        if (i < m) F[i % 2][j][k] = 0;
      }
}
void process2() {
  F[0][0][0] = 1;
  for (int it = 1; it <= n; it++) {
    int i = it & 1;
    for (int j = 0; j <= m; j++)
      for (int k = 0; k <= b; k++) {
        F[i][j][k] = F[i ^ 1][j][k];
        if (j > 0 && k - a[it] >= 0)
          F[i][j][k] = (F[i][j][k] + F[i][j - 1][k - a[it]]) % mod;
      }
  }
  int res = 0;
  for (int i = 0; i <= b; i++) res = (res + F[n & 1][m][i]) % mod;
  cout << res << endl;
}
void process3() {
  F[0][0][0] = 1;
  for (int it = 0; it <= n; it++) {
    int i = it & 1;
    for (int j = 0; j <= m; j++)
      for (int k = 0; k <= b; k++) {
        if (it < n && j < m && k + a[it + 1] <= b)
          F[i][j + 1][k + a[it + 1]] =
              (F[i][j + 1][k + a[it + 1]] + F[i][j][k]) % mod;
        F[i ^ 1][j][k] = (F[i ^ 1][j][k] + F[i][j][k]) % mod;
        if (it < n) F[i][j][k] = 0;
      }
  }
  int res = 0;
  for (int i = 0; i <= b; i++) res = (res + F[(n)&1][m][i]) % mod;
  cout << res;
}
void print() {
  int res = 0;
  for (int j = 0; j <= b; j++) res = (res + F[m % 2][n][j]) % mod;
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  enter();
  process();
  print();
}
