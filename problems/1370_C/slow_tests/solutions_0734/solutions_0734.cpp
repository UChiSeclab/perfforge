#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n == 1) {
      cout << "FastestFinger" << endl;
    } else if (n == 2) {
      cout << "Ashishgup" << endl;
    } else {
      if (n % 2 != 0)
        cout << "Ashishgup" << endl;
      else {
        int flag = 0;
        for (int i = 2; i <= sqrtl(n); i++) {
          if (n % i == 0) {
            if (i % 2 != 0) {
              if (n / i != 2) flag = 1;
            } else {
              if (i != 2 && (n / i) % 2 != 0) flag = 1;
            }
          }
        }
        if (flag == 0)
          cout << "FastestFinger" << endl;
        else {
          cout << "Ashishgup" << endl;
        }
      }
    }
  }
  return 0;
}
