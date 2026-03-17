#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void mini(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void maxi(T &a, T b) {
  if (b > a) a = b;
}
int main() {
  long long a, b, c;
  cin >> a >> b;
  string s;
  cin >> s;
  long long x = 0, y = 0;
  for (int i = 0; i < s.size(); i++) {
    if (x == a && y == b) {
      cout << "Yes\n";
      return 0;
    }
    if (s[i] == 'U') y++;
    if (s[i] == 'D') y--;
    if (s[i] == 'L') x--;
    if (s[i] == 'R') x++;
  }
  long long mx, my;
  mx = x;
  my = y;
  int x1 = 0, y1 = 0;
  if (x != 0) x1 = a / x;
  if (y != 0) y1 = b / y;
  if (x * a < 0 && y * b < 0) {
    cout << "No\n";
    return 0;
  }
  long long t;
  if (x * a > 0 && y * b > 0) {
    t = min(x1, y1);
    x += x * (t - 10000);
    y += y * (t - 10000);
  } else if (x * a > 0) {
    x += (x1 - 10000) * x;
    y += (x1 - 10000) * y;
  } else if (y * b > 0) {
    x += (y1 - 10000) * x;
    y += (y1 - 10000) * y;
  }
  int z = 10000;
  while (z--)
    for (int i = 0; i < s.size(); i++) {
      if (x == a && y == b) {
        cout << "Yes\n";
        return 0;
      }
      if (s[i] == 'U') y++;
      if (s[i] == 'D') y--;
      if (s[i] == 'L') x--;
      if (s[i] == 'R') x++;
    }
  cout << "No\n";
}
