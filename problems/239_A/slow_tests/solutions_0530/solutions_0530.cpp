#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long y, k, n;
  cin >> y >> k >> n;
  bool flag = true;
  long long i = 1;
  while (k * i <= n) {
    if (y == n)
      break;
    else if (k * i > y) {
      cout << k * i - y << " ";
      flag = false;
    }
    i++;
  }
  if (flag) cout << -1;
}
