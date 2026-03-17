#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  int a[100];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (x > y) {
    cout << n;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (a[j] > a[j + 1]) {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
  int num = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > x) break;
    num++;
  }
  if (num % 2 == 1) cout << num / 2 + 1;
  if (num % 2 == 0) cout << num / 2;
  return 0;
}
