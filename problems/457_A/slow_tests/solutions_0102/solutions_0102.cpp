#include <bits/stdc++.h>
using namespace std;
string a, b;
int main() {
  cin >> a >> b;
  while (b.length() < a.length()) b = '0' + b;
  while (a.length() < b.length()) a = '0' + a;
  a = '0' + a;
  b = '0' + b;
  for (int i = 1; i < a.length(); i++) {
    if (a[i] == '1' && a[i + 1] == '1') {
      a[i - 1] = '1';
      a[i] = '0';
      a[i + 1] = '0';
    }
  }
  for (int i = a.length() - 1; i >= 0; i--) {
    if (a[i] == '1' && a[i + 1] == '1') {
      a[i - 1] = '1';
      a[i] = '0';
      a[i + 1] = '0';
    }
  }
  for (int i = 1; i < b.length(); i++) {
    if (b[i] == '1' && b[i + 1] == '1') {
      b[i - 1] = '1';
      b[i] = '0';
      b[i + 1] = '0';
    }
  }
  for (int i = b.length() - 1; i >= 0; i--) {
    if (b[i] == '1' && b[i + 1] == '1') {
      b[i - 1] = '1';
      b[i] = '0';
      b[i + 1] = '0';
    }
  }
  for (int i = 0; i < a.length(); i++) {
    if (a[i] != b[i]) {
      if (a[i] == '1')
        cout << ">\n";
      else
        cout << "<\n";
      return 0;
    }
  }
  cout << "=\n";
  return 0;
}
