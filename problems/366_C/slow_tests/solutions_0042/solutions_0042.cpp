#include <bits/stdc++.h>
using namespace std;
map<int, int> m1, m2;
int a[105], b[105];
int main() {
  ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    b[i] = a[i] - b[i] * k;
  }
  m2[0] = 0;
  for (int i = 1; i <= n; ++i) {
    m1.clear();
    m1 = m2;
    for (auto j : m1)
      m2[j.first + b[i]] = max(m2[j.first + b[i]], m1[j.first] + a[i]);
  }
  if (m2[0]) {
    cout << m2[0];
  } else {
    cout << -1;
  }
}
