#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, l, m, n, d;
  cin >> k >> l >> m >> n >> d;
  if (k == 1 || m == 1 || n == 1 || l == 1) {
    cout << d;
  } else {
    set<int> s;
    for (int i = k; i <= d; i += k) {
      s.insert(i);
    }
    for (int i = l; i <= d; i += l) {
      s.insert(i);
    }
    for (int i = m; i <= d; i += m) {
      s.insert(i);
    }
    for (int i = n; i <= d; i += n) {
      s.insert(i);
    }
    cout << s.size();
  }
  return 0;
}
