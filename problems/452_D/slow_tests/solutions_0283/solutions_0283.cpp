#include <bits/stdc++.h>
using namespace std;
int k, n[5], t[5], r[5][1005], ks, kt, rm, res;
bool w[5][1005];
int main() {
  cin >> k;
  ks = k;
  for (int i = 1; i <= 3; i++) cin >> n[i];
  for (int i = 1; i <= 3; i++) cin >> t[i];
  while (kt < ks) {
    for (int i = 3; i >= 1; i--) {
      for (int j = 0; j < n[i]; j++) {
        if (r[i][j] == 0 && w[i][j]) {
          if (i == 3) {
            kt++;
            w[i][j] = false;
          } else {
            for (int k = 0; k < n[i + 1]; k++)
              if (!w[i + 1][k]) {
                w[i + 1][k] = true;
                r[i + 1][k] = t[i + 1];
                w[i][j] = false;
                break;
              }
          }
        }
      }
    }
    for (int i = 0; i < n[1]; i++) {
      if (!w[1][i] && k > 0) {
        w[1][i] = true;
        k--;
        r[1][i] = t[1];
      }
    }
    rm = 1005;
    for (int i = 1; i <= 3; i++)
      for (int j = 0; j < n[i]; j++)
        if (r[i][j] != 0) rm = min(rm, r[i][j]);
    for (int i = 1; i <= 3; i++)
      for (int j = 0; j < n[i]; j++)
        if (r[i][j] != 0) r[i][j] -= rm;
    res += rm;
  }
  cout << res - rm;
  return 0;
}
