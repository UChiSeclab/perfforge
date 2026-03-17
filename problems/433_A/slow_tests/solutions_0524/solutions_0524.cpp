#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int s1 = 0, s2 = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] == 100)
      s1++;
    else
      s2++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        for (int m = 0; m < n; m++) {
          if (i + j + k + m == n && i + k == s1 && j + m == s2) {
            int a = j - m;
            int b = k - i;
            if (200 * a == 100 * b) {
              cout << "YES" << '\n';
              return 0;
            }
          }
        }
      }
    }
  }
  cout << "NO" << '\n';
  return 0;
}
