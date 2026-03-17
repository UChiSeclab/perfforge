#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, x, temp, i;
  long ans;
  ans = 0;
  cin >> n >> x;
  for (i = 1; i <= n; i++) {
    temp = x / i;
    if (x % i == 0.0 && (temp <= n)) {
      ans++;
    }
  }
  cout << ans << endl;
}
