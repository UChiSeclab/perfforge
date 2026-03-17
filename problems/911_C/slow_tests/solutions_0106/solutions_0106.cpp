#include <bits/stdc++.h>
using namespace std;
struct $ {
  $() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  }
} $;
const int N = 200005;
int main() {
  int k1, k2, k3;
  cin >> k1 >> k2 >> k3;
  for (int x1 = 0; x1 < 20; x1++) {
    for (int x2 = 0; x2 < 20; x2++) {
      for (int x3 = 0; x3 < 20; x3++) {
        set<int> s;
        int m = max({x1, x2, x3});
        for (int i = x1; i <= 200; i += k1) {
          if (i >= m) s.insert(i);
        }
        for (int i = x2; i <= 200; i += k2) {
          if (i >= m) s.insert(i);
        }
        for (int i = x3; i <= 200; i += k3) {
          if (i >= m) s.insert(i);
        }
        if (s.size() == 200 - m + 1) {
          cout << "YES" << endl;
          return 0;
        }
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
