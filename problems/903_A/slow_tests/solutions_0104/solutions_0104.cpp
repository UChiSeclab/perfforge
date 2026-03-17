#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    bool b = 0;
    for (int i = 0; i <= 100; i++) {
      for (int j = 0; j <= 100; j++) {
        if (3 * i + 7 * j == x) b = 1;
      }
    }
    if (b)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
}
