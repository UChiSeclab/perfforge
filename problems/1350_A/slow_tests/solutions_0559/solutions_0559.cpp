#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    if (n % 2 == 0) {
      cout << n + k * 2 << "\n";
    } else {
      long long int x = n;
      while (x % 2 != 0 && k > 0) {
        long long int a = 0;
        for (int i = 2; i <= x; i++) {
          if (x % i == 0) {
            a = i;
            break;
          }
        }
        x += a;
        k--;
      }
      cout << x + k * 2 << "\n";
    }
  }
  return 0;
}
