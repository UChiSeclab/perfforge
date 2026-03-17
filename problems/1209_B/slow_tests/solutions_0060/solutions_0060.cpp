#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, r = 0, j, max = 0;
  int a[100], b[100];
  string s;
  cin >> n;
  cin >> s;
  for (i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (j = 0; j < n; j++) {
    if (s[j] == '1') {
      r++;
    }
  }
  if (r > max) {
    max = r;
  }
  for (i = 0; i < n * 1000; i++) {
    r = 0;
    for (j = 0; j < n; j++) {
      if ((((i - b[j]) % a[j] == 0) && (i >= b[j]))) {
        if (s[j] == '1') {
          s[j] = '0';
        } else {
          s[j] = '1';
        }
      }
    }
    for (j = 0; j < n; j++) {
      if (s[j] == '1') {
        r++;
      }
    }
    if (r > max) {
      max = r;
    }
  }
  cout << max;
}
