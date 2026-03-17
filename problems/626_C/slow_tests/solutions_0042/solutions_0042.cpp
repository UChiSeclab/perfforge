#include <bits/stdc++.h>
using namespace std;
int n, m;
bool check(int x) {
  int num = (x - 2 * n) / 2, tmp = m, top = 0;
  while (tmp > 0) {
    top += 3;
    if (top % 6 == 0) {
      if (num > 0)
        num--;
      else
        top += 3;
    }
    tmp--;
  }
  return top <= x;
}
int main() {
  scanf("%d%d", &n, &m);
  int l = max(2 * n, 3 * m), r = 6000000, mid;
  while (l < r) {
    mid = (l + r) / 2;
    if (check(mid) == true)
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d", l);
  return 0;
}
