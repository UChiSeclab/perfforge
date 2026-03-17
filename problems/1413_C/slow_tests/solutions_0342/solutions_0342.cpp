#include <bits/stdc++.h>
using namespace std;
const int max_n = 1e5 + 10, inf = 1000111222;
int n, m;
int a[max_n];
int b[max_n];
bool check1(int l, int r) {
  int p = 0;
  for (int i = 0; p < m && i < n; i++) {
    if (b[p] < a[i] + l) {
      return 0;
    }
    p = upper_bound(b + p, b + m, a[i] + r) - b;
  }
  return p == m;
}
bool check(int x) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      {
        int l = b[j] - a[i];
        int r = l + x;
        if (check1(l, r)) {
          return 1;
        }
      }
      {
        int r = b[j] - a[i];
        int l = r - x;
        if (check1(l, r)) {
          return 1;
        }
      }
    }
  }
  return 0;
}
int main() {
  n = 6;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(b, b + m);
  int l = 0, r = 1e9;
  while (r - l > 0) {
    int m = (l + r) / 2;
    if (check(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << l << "\n";
}
