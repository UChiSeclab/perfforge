#include <bits/stdc++.h>
using namespace std;
void oj() {}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  oj();
  long long t, x, y, n;
  cin >> n;
  map<char, long long> m;
  for (long long i = 0; i < 9; i++) {
    cin >> x;
    m['1' + i] = x;
  }
  long long d = LLONG_MIN;
  char ch;
  for (auto x : m) {
    if (n / x.second > d) {
      ch = x.first;
      d = n / x.second;
    } else if (n / x.second == d) {
      if (x.second < m[ch])
        ch = x.first;
      else if (x.second == m[ch])
        ch = max(ch, x.first);
    }
  }
  if (d == 0) {
    cout << -1;
    return 0;
  }
  string ans(d, ch);
  long long rem = n - d * m[ch];
  long long i = 0;
  while (rem > 0 && i < ans.length()) {
    for (long long j = 9; j >= 0; j--) {
      if (rem + m[ans[i]] >= m[j + '0']) {
        rem = rem + m[ans[i]] - m[j + '0'];
        ans[i] = j + '0';
        break;
      }
    }
    i++;
  }
  cout << ans;
  return 0;
}
