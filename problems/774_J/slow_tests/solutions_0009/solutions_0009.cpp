#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  bool flag = false;
  for (int i = k; i <= n; ++i) {
    string t = s;
    for (int j = 1; j <= i - k; ++j)
      if (t[j - 1] == '?') t[j - 1] = 'Y';
    for (int j = i + 1; j <= n; ++j)
      if (t[j - 1] == '?') t[j - 1] = 'Y';
    for (int j = i - k + 1; j <= i; ++j)
      if (t[j - 1] == '?') t[j - 1] = 'N';
    int c = 0, m = 0;
    for (int i = 1; i <= n; ++i) {
      if (t[i - 1] == 'N')
        ++c;
      else {
        m = max(m, c);
        c = 0;
      }
    }
    m = max(m, c);
    if (m == k) {
      flag = true;
      break;
    }
  }
  if (flag)
    cout << "YES\n";
  else
    cout << "NO\n";
}
