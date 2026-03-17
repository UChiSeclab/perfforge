#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 0;
  cin >> n;
  int a[n], b[n];
  if (n == 1) {
    cout << 1;
    return 0;
  }
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    k++;
    b[k - 1] = 0;
    for (int j = 0; j < n; j++)
      if (a[i] == a[j]) b[k - 1]++;
  }
  int max = b[0];
  for (int i = 0; i < n; i++)
    if (b[i] > max) max = b[i];
  cout << max;
  return 0;
}
