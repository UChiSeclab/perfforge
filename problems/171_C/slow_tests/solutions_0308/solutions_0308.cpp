#include <bits/stdc++.h>
using namespace std;
int a[200];
int main() {
  int n;
  cin >> n;
  int i;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  unsigned long long ans;
  ans = 0;
  for (i = 1; i <= n; i++) {
    ans += a[i] * i;
  }
  cout << ans << endl;
  return 0;
}
