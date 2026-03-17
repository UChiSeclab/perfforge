#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long ans = 0;
  int s;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    ans += s * i;
  }
  cout << ans;
}
