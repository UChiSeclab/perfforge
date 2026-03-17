#include <bits/stdc++.h>
using namespace std;
int m[21][5010];
int n, k, x, T;
int find(int xx, int pos) {
  int left = 1;
  int right = n;
  if (xx == 0) return 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (m[pos][mid] == xx) return 2;
    if (m[pos][mid] > xx) right = mid - 1;
    if (m[pos][mid] < xx) left = mid + 1;
  }
  return -1;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> m[1][i];
    for (int j = 2; j <= k; j++) m[j][i] = m[1][i] * j;
  }
  cin >> T;
  while (T--) {
    cin >> x;
    int res = -1;
    for (int ans = 1; ans <= k; ans++) {
      for (int i = 1; i <= ans; i++) {
        for (int j = 1; j <= n; j++) {
          if (m[i][j] > x) break;
          int p = x - m[i][j];
          int leave = find(p, ans - i);
          if (leave == 1) res = i;
          if (leave == 2) res = ans;
        }
        if (res > 0) break;
      }
      if (res > 0) break;
    }
    cout << res << endl;
  }
  return 0;
}
