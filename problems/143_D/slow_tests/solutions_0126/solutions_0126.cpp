#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
int n, m, a[N][N];
bool check(int i, int j) {
  if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == 0)
    return 1;
  else
    return 0;
}
int main() {
  cin >> n >> m;
  if (n == 1 || m == 1) {
    cout << max(n, m);
    return 0;
  }
  if (n == 2 || m == 2) {
    int ans = max(n, m) / 2;
    if (ans % 2 == 0)
      ans = (ans / 2) * 4 + (max(n, m) % 2) * 2;
    else
      ans = (ans / 2 + 1) * 4;
    cout << ans;
    return 0;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
        a[i][j] = 1;
        ans++;
      } else {
        a[i][j] = 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 0 && check(i + 1, j + 2) && check(i - 1, j + 2) &&
          check(i + 1, j - 2) && check(i - 1, j - 2) && check(i + 2, j + 1) &&
          check(i - 2, j + 1) && check(i + 2, j - 1) && check(i - 2, j - 1)) {
        ans++;
      }
    }
  }
  cout << ans;
}
