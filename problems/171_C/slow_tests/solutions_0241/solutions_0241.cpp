#include <bits/stdc++.h>
using namespace std;
int x = 1, n;
int main() {
  cin >> n;
  long ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    ans += x * i;
  }
  cout << ans;
}
