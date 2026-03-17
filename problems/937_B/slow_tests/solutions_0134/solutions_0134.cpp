#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int a, b;
  cin >> a >> b;
  if (a >= b) {
    cout << -1;
    return 0;
  }
  int k = b - a;
  if (a <= 1000000 && b <= 1000000) {
    int i, j;
    int A[1000006];
    int flag = 0;
    int ans = 0;
    for (i = 3; i <= 1000000; i++) {
      A[i] = 1;
    }
    for (i = 2; i <= a; i++) {
      for (j = i; j <= b; j = j + i) {
        A[j] = 0;
      }
    }
    for (i = 3; i <= b; i++) {
      if (A[i] == 1) {
        ans = i;
        flag = 1;
      }
    }
    if (flag) {
      cout << ans;
      return 0;
    }
    cout << -1;
    return 0;
  }
  if (a > 100000) {
    k = min(k, 500);
    int i, j;
    int flag = 0;
    int ans = 0;
    int flag1 = 0;
    for (i = max(2, b - k); i <= b; i++) {
      flag = 0;
      for (j = 2; j * j <= i; j++) {
        if (i % j == 0) {
          flag = 1;
        }
      }
      if (flag == 0) {
        if (i > a) {
          flag1 = 1;
          ans = i;
        }
      }
    }
    if (flag1) {
      cout << ans;
      return 0;
    }
    cout << -1;
    return 0;
  }
  if (a <= 100000) {
    k = min(k, 500);
    int i, j;
    int flag = 0;
    int ans = 0;
    int flag1 = 0;
    for (i = max(2, b - k); i <= b; i++) {
      flag = 0;
      for (j = 2; j <= a; j++) {
        if (i % j == 0) {
          flag = 1;
        }
      }
      if (flag == 0) {
        if (i > a) {
          flag1 = 1;
          ans = i;
        }
      }
    }
    if (flag1) {
      cout << ans;
      return 0;
    }
    cout << -1;
  }
  return 0;
}
