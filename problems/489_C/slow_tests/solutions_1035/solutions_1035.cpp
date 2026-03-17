#include <bits/stdc++.h>
using namespace std;
char tochar(int n) {
  int m = n;
  char x;
  stringstream ss;
  ss << m;
  ss >> x;
  return x;
}
string revers_(string s) {
  string x;
  for (int i = s.size() - 1, j = 0; i >= 0, j < s.size(); i--, j++) {
    x += s[i];
  }
  for (int i = 0; i < x.size(); i++) {
    for (int j = i + 1; j < x.size(); j++) {
      if (x[i] == '0' && x[j] != '0') {
        x[i] = '1';
        x[j] = tochar((x[j] - '0') - 1);
        return x;
      }
    }
  }
  return x;
}
int main() {
  int n, m, x;
  cin >> n >> m;
  x = m;
  string s;
  if (m == 0 && n != 1 || m > 9 * n) {
    cout << -1 << " " << -1;
    cout << endl;
    ;
    return 0;
  }
  if (m < 10) {
    for (int i = 0; i < n; i++) {
      s += tochar(m);
      m = 0;
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (m >= 10) {
        s += tochar(9);
        m -= 9;
      } else {
        s += tochar(m);
        m = 0;
      }
    }
  }
  if (x < 10 && n != 1) {
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        cout << 1;
        x -= 1;
      } else if (i == n - 1)
        cout << x;
      else
        cout << 0;
    }
    cout << " " << s;
    cout << endl;
  } else
    cout << revers_(s) << " " << s;
  cout << endl;
  return 0;
}
