#include <bits/stdc++.h>
using namespace std;
const int MAX_N = (1 << 18);
int n, m;
int ans = 0;
bool func(int crt, int cnt) {
  if (crt > m)
    return 0;
  else if (crt == m) {
    ans = cnt;
    return 1;
  }
  return func(crt * 3, cnt + 1) | func(crt * 2, cnt + 1);
}
int main() {
  cin >> n >> m;
  if (!func(n, 0)) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
}
