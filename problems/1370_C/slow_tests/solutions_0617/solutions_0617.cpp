#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n == 1)
      cout << "FastestFinger" << endl;
    else if (n == 2)
      cout << "Ashishgup" << endl;
    else if (n % 2)
      cout << "Ashishgup" << endl;
    else {
      set<int> st;
      for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
          if (i % 2) st.insert(i);
          if ((n / i) % 2) st.insert(n / i);
        }
      }
      if (st.size() == 0)
        cout << "FastestFinger" << endl;
      else {
        int f = 0;
        for (auto i : st) {
          if (i != n / 2) {
            cout << "Ashishgup" << endl;
            f = 1;
            break;
          }
        }
        if (f == 0) cout << "FastestFinger" << endl;
      }
    }
  }
  return 0;
}
