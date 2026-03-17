#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int a[maxn];
int main() {
  int n;
  string s;
  while (cin >> n) {
    int flag = false;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    int y = sum / 2;
    int sum2;
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++) {
      sum2 = 0;
      for (int j = i; j < n; j++) {
        sum2 += a[j];
        if (sum2 < y) continue;
        if (sum2 == y) {
          flag = true;
          break;
        }
        if (sum2 > y) break;
      }
      if (flag) break;
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
