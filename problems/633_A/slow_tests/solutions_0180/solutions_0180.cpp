#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a == c || b == c) {
    cout << "YES" << endl;
    return 0;
  }
  if (a > c && b > c) {
    cout << "NO" << endl;
    return 0;
  }
  int cur = 0;
  int cur_b = 0;
  for (int i = 0; i < 10010; i++) {
    for (int i = 0; i < 10010; i++) {
      if ((cur + cur_b) == c) {
        cout << "YES" << endl;
        return 0;
      }
      cur_b += b;
    }
    cur_b = 0;
    cur += a;
  }
  cout << "NO" << endl;
  return 0;
}
