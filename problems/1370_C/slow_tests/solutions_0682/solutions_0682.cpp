#include <bits/stdc++.h>
using namespace std;
long long int sum() { return 0; }
template <typename T, typename... Args>
T sum(T a, Args... args) {
  return a + sum(args...);
}
void solve() {
  long long int n;
  cin >> n;
  if (n == 1) {
    cout << "FastestFinger"
         << "\n";
    return;
  }
  if (n % 2) {
    cout << "Ashishgup"
         << "\n";
    return;
  }
  long long int c = 0;
  while (n % 2 == 0) {
    c++;
    n /= 2;
  }
  if (n == 1) {
    if (c == 1) {
      cout << "Ashishgup"
           << "\n";
      return;
    } else {
      cout << "FastestFinger"
           << "\n";
      return;
    }
  } else {
    bool prime = true;
    for (long long int i = 2; i * i <= n; i++) {
      if (n % i == 0) prime = false;
    }
    if (prime) {
      if (c == 1) {
        cout << "FastestFinger"
             << "\n";
        return;
      } else {
        cout << "Ashishgup"
             << "\n";
        return;
      }
    } else {
      cout << "Ashishgup"
           << "\n";
      return;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
