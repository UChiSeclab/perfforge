#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long n, x, y;
  cin >> n >> x >> y;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (x > y) {
    cout << n << "\n";
    return 0;
  } else if (x < y) {
    int doors = n;
    int mini = a[0] - x;
    for (int i = 0;; i++) {
      if (i % 2 == 0) {
        int flag = 1;
        for (int j = 0; j < n; j++) {
          if (a[j] <= x && a[j] != 0) {
            flag = 0;
          }
        }
        if (flag) {
          cout << n - doors << "\n";
          return 0;
        }
        long long mini = x, pos = -1;
        for (int j = 0; j < n; j++) {
          if (x - a[j] >= 0) {
            if (mini > x - a[j]) {
              pos = j;
              mini = x - a[j];
            }
          }
        }
        a[pos] = 0;
        doors--;
      } else {
        long long mini = x, pos = -1;
        for (int j = 0; j < n; j++) {
          if (a[j] > 0 && a[j] <= mini) {
            mini = a[j];
            pos = j;
          }
        }
        a[pos] += y;
      }
    }
  } else {
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (x >= a[i]) {
        count++;
      }
    }
    if (count % 2) count++;
    cout << count / 2 << "\n";
  }
  return 0;
}
