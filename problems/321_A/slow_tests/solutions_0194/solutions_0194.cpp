#include <bits/stdc++.h>
using namespace std;
const int MX = 100005, INF = 1000000000, mod = 1000000009;
const long long int LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int ci[256];
int main() {
  ci['U'] = 3;
  ci['D'] = 1;
  ci['L'] = 0;
  ci['R'] = 2;
  int n, x, y, a, b;
  string s;
  cin >> a >> b >> s;
  if (a == 0 && b == 0) {
    puts("Yes");
    return 0;
  }
  n = s.size();
  x = y = 0;
  for (int i = 0; i < n; i++) {
    x += dx[ci[s[i]]];
    y += dy[ci[s[i]]];
    if (a == x && b == y) {
      puts("Yes");
      return 0;
    }
  }
  if (x == 0 && y == 0) {
    puts("No");
    return 0;
  }
  int t = 0;
  if (x > 0) t = max(t, (a - 200) / x);
  if (x < 0) t = max(t, (a + 200) / x);
  if (y > 0) t = max(t, (b - 200) / y);
  if (y < 0) t = max(t, (b + 200) / y);
  x *= t;
  y *= t;
  for (int j = 0; j < 10000; j++) {
    for (int i = 0; i < n; i++) {
      x += dx[ci[s[i]]];
      y += dy[ci[s[i]]];
      if (a == x && b == y) {
        puts("Yes");
        return 0;
      }
    }
  }
  puts("No");
  return 0;
}
