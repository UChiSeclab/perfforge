#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0, s1 = 0, s = 0, l = 0, m, sec;
  cin >> n;
  m = n - 1;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 2, k = 999999; c != n; i++, k--) {
    if (i == a[l]) {
      s1 = i - 2 + 1;
      c++;
      l++;
    }
    if (k == a[m]) {
      s = 1000000 - k;
      c++;
      m--;
    }
  }
  if (s > s1)
    sec = s;
  else
    sec = s1;
  cout << sec;
}
