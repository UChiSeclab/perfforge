#include <bits/stdc++.h>
using namespace std;
int n, el[1001];
int main() {
  cin >> n;
  for (int i = 0; i < (int)n; ++i) cin >> el[i];
  sort(el, el + n);
  int j = 0, ans = 0;
  for (int i = el[0]; i <= el[n - 1]; i++) {
    if (el[j] != i) {
      ans++;
    } else
      j++;
  }
  cout << ans << endl;
  return 0;
}
