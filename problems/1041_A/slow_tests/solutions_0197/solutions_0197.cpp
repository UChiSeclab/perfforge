#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int count = a[0];
  int counter = 0, i = 0;
  while (i < n) {
    if (count == a[i]) {
      count++;
      i++;
    } else {
      count++;
      counter++;
    }
  }
  cout << counter;
}
