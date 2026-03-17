#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 110;
int a[MAX_N], b[MAX_N];
int n;
string s;
int bit[MAX_N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cin >> s;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
  }
  for (int i = 1; i <= n; ++i) {
    bit[i] = s[i - 1] - '0';
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cnt += bit[i];
  }
  int ans = cnt;
  for (int now = 1; now <= 1e6; ++now) {
    bool can = true;
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
      if (now >= b[i] && (now - b[i]) % a[i] == 0) {
        bit[i] ^= 1;
      } else
        can = false;
      cnt += bit[i];
    }
    ans = max(ans, cnt);
    if (ans == n) break;
    if (can) break;
  }
  cout << ans << endl;
  return 0;
}
