#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, temp = 0;
  long long x, y;
  cin >> n >> x >> y;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long i = 0, z = 0;
  if (x > y) {
    cout << n;
    return 0;
  } else {
    sort(a, a + n);
    bool isthere = true;
    int t = 0;
    while (isthere) {
      sort(a, a + n);
      isthere = false;
      for (int j = i; j < n; j++) {
        if (x >= a[j]) {
          isthere = true;
          t = i;
        }
      }
      a[t] = max(temp, a[t] - x);
      if (a[i] != 0) {
        a[i] = a[i] + y;
      } else {
        z++;
        a[i + 1] = a[i + 1] + y;
      }
      i++;
    }
  }
  cout << z;
  return 0;
}
