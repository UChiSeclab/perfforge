#include <bits/stdc++.h>
using namespace std;
int a[1000005], b[1000005];
bool check[1000005];
int main() {
  int n, tmp = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    tmp = max(tmp, a[i]);
  }
  for (int i = 2; i <= tmp; i++) check[i] = true;
  for (int i = 2; i * i <= tmp; i++) {
    if (check[i] == true)
      for (int j = i * i; j <= tmp; j += i) check[j] = false;
  }
  for (int i = 2; i <= tmp; i++) {
    b[i] = (check[i] == true) + b[i - 1];
  }
  for (int i = 0; i < n; i++) {
    int cnt = sqrt(a[i]);
    cout << b[a[i]] - b[cnt] + 1 << " ";
  }
  return 0;
}
