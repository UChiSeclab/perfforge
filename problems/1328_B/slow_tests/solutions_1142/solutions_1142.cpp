#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k, i = 1;
  cin >> n >> k;
  string s(n - 2, 'a');
  s = s + "bb";
  if (k == 1) {
    cout << s << endl;
    return;
  }
  while (k >= 0) {
    k = k - i;
    i++;
    if (k - i <= 0) break;
  }
  long long y = n - i - 1, a = y;
  while (y--) cout << "a";
  cout << "b";
  long long x = i - k, b = x;
  while (x--) cout << "a";
  cout << "b";
  long long c = n - a - b - 2;
  while (c--) cout << "a";
  cout << "\n";
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
