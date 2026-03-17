#include <bits/stdc++.h>
using namespace std;
long long n, k, m;
long long M[50][2500];
long long A[50], V[50];
int main() {
  long long p, i, j, maxim = 0, x, sum = 0;
  cin >> n >> k >> m;
  for (p = 1; p <= n * (k + 1); p++) M[1][p] = 1e15;
  for (i = 1; i <= k; i++) {
    cin >> V[i];
  }
  sort(V + 1, V + k + 1);
  for (i = 1; i <= k; i++) {
    x = V[i];
    sum += x;
    A[i] = sum;
    if (i == k)
      M[1][k + 1] = sum;
    else
      M[1][i] = sum;
  }
  for (i = 2; i <= n; i++) {
    for (p = 1; p <= n * (k + 1); p++) {
      M[i][p] = M[i - 1][p];
      for (j = 1; j < k; j++) {
        if (p - j < 1) break;
        if (M[i - 1][p - j]) M[i][p] = min(M[i][p], M[i - 1][p - j] + A[j]);
      }
      if (p - k - 1 > 0 && M[i - 1][p - k - 1])
        M[i][p] = min(M[i][p], M[i - 1][p - k - 1] + A[k]);
    }
  }
  for (p = 1; p <= n * (k + 1); p++) {
    if (M[n][p] <= m) maxim = p;
  }
  cout << maxim;
  return 0;
}
