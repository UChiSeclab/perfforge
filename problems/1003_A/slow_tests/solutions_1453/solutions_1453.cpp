#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int b = 0, c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i] == a[j]) c++;
    }
    if (c > b) b = c;
    c = 0;
  }
  cout << b << "\n";
}
