#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int A[n];
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  vector<vector<vector<bool> > > DP(
      k + 1, vector<vector<bool> >(n, vector<bool>(k + 1, false)));
  for (int i = 0; i < n; ++i) {
    DP[0][i][0] = true;
  }
  if (A[0] <= k) {
    DP[A[0]][0][A[0]] = true;
    DP[A[0]][0][0] = true;
  }
  for (int j = 1; j <= k; j++) {
    for (int i = 1; i < n; ++i) {
      if (j - A[i] >= 0) {
        for (int l = 0; l <= k; ++l) {
          if (DP[j - A[i]][i - 1][l]) {
            DP[j][i][l + A[i]] = true;
            DP[j][i][l] = true;
          }
        }
      }
      for (int l = 0; l <= k; l++) {
        if (DP[j][i - 1][l]) {
          DP[j][i][l] = true;
        }
      }
    }
  }
  int sum = 0;
  for (int l = 0; l <= k; ++l) {
    if (DP[k][n - 1][l]) {
      sum++;
    }
  }
  cout << sum << "\n";
  for (int l = 0; l <= k; ++l) {
    if (DP[k][n - 1][l]) {
      cout << l << " ";
    }
  }
}
