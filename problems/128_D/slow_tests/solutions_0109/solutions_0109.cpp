#include <bits/stdc++.h>
using namespace std;
int a[111111];
int b[111111];
int main() {
  int i, n;
  int themin = 1111111111;
  int sum = 0;
  int left;
  int newleft;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    themin = min(a[i], themin);
  }
  if (n % 2 == 1) {
    cout << "NO" << endl;
    return 0;
  }
  for (i = 0; i < 111110; i++) b[i] = 0;
  for (i = 0; i < n; i++) {
    a[i] -= themin;
    if (a[i] >= 111110) {
      cout << "NO" << endl;
      return 0;
    }
    b[a[i]]++;
  }
  sum = b[0];
  left = b[0] * 2;
  for (i = 1; i < 111110; i++) {
    sum += b[i];
    newleft = b[i] * 2 - left;
    left = newleft;
    if (sum == n && left == 0) {
      cout << "YES" << endl;
      break;
    } else if (left < 0) {
      cout << "NO" << endl;
      break;
    } else if (left == 0 && sum < n) {
      cout << "NO" << endl;
      break;
    }
  }
  return 0;
}
