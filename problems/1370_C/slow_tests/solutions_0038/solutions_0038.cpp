#include <bits/stdc++.h>
using namespace std;
int n, m, t = 1;
long long ans = 0;
string str;
int nod(int n) {
  int x = 0;
  for (int i = 3; i * i <= n; i++) {
    if (n % i == 0) x += 2;
  }
  int k = sqrt(n);
  if (k * k == n)
    return x;
  else
    return x + 1;
}
int main() {
  cin >> t;
  while (t--) {
    int cnt = 0;
    int cnto = 0;
    cin >> n;
    if (n == 1) {
      cout << "FastestFinger\n";
    } else if (n == 2) {
      cout << "Ashishgup\n";
    } else {
      if (n % 2 == 1)
        cout << "Ashishgup\n";
      else {
        while (n % 2 == 0) {
          cnt++;
          n = n / 2;
        }
        cnto = nod(n);
        if ((cnt == 1 && cnto == 1) || n == 1)
          cout << "FastestFinger\n";
        else
          cout << "Ashishgup\n";
      }
    }
  }
  return 0;
}
