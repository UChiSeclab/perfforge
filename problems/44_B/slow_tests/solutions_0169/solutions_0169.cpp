#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, a, b, c, cnt = 0;
  scanf("%d %d %d %d", &n, &a, &b, &c);
  for (int i = 0; i <= a; i += 2) {
    int vol = 0;
    vol += i / 2;
    if (vol == n) {
      cnt++;
      break;
    }
    for (int j = 0; j <= b; j++) {
      int vol1 = vol;
      vol1 += j;
      if (vol1 == n) {
        cnt++;
        break;
      }
      if (vol1 % 2 == n % 2) {
        if (vol1 + 2 * c >= n) {
          cnt++;
        }
      }
    }
  }
  printf("%d", cnt);
  return;
}
int main() {
  solve();
  return 0;
}
