#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  int inf = 0x3f3f3f3f;
  int ans = inf;
  for (int i = a; i <= 100; i++) {
    for (int j = b; j <= 100; j++) {
      for (int k = c; k <= 100; k++) {
        if (i + j > k && i + k > j && j + k > i)
          ans = min(ans, i - a + j - b + k - c);
      }
    }
  }
  cout << ans;
  return 0;
}
