#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << "FastestFinger\n";
    return;
  }
  if (n == 2) {
    cout << "Ashishgup\n";
    return;
  }
  if (n % 2 == 1) {
    cout << "Ashishgup\n";
    return;
  }
  long long ok = -1;
  set<long long> s;
  for (long long i = 3; i * i <= n * 2; i += 2) {
    if (n % i == 0) {
      s.insert(i);
      ok = i;
    }
    if (n % (i - 1) == 0 && n / (i - 1) % 2 != 0) {
      s.insert(n / (i - 1));
      ok = n / (i - 1);
    }
  }
  if (s.size() == 0 || (n / ok == 2 && s.size() == 1)) {
    cout << "FastestFinger\n";
    return;
  }
  cout << "Ashishgup\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout.precision(30);
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
