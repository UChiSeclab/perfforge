#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 7;
int a[10], dp[10][M];
int call(int pos, int cap) {
  if (cap < 0) return -1 << 29;
  if (pos >= 10) {
    if (cap >= 0) return 0;
    return -1 << 29;
  }
  if (dp[pos][cap] != -1) return dp[pos][cap];
  int p = 0, q = 0;
  p = call(pos + 1, cap);
  q = 1 + call(pos, cap - a[pos]);
  return dp[pos][cap] = max(p, q);
}
void solve() {
  memset(dp, -1, sizeof dp);
  int cap;
  cin >> cap;
  for (int i = 1; i <= 9; i++) cin >> a[i];
  int digLen = call(1, cap);
  if (digLen <= 0) {
    cout << "-1"
         << "\n";
    ;
    return;
  }
  string res = "";
  int rem;
  for (int i = 1; i <= 9; i++) {
    int div = cap / a[i];
    rem = cap % a[i];
    int cnt = 0;
    int d = -1;
    for (int j = 1; j <= 9; j++) {
      if (rem >= a[j]) {
        cnt = 1;
        d = j;
        rem -= a[j];
        break;
      }
    }
    if ((div + cnt) == digLen) {
      for (int j = 1; j <= div; j++) res += i + '0';
      if (cnt) res += d + '0';
      break;
    }
  }
  for (int i = 0; i < digLen; i++) {
    int val = res[i] - '0';
    rem += a[val];
    for (int j = 9; j >= 1; j--) {
      if (rem >= a[j]) {
        res[i] = j + '0';
        rem -= a[j];
        break;
      }
    }
  }
  cout << res << "\n";
  ;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
