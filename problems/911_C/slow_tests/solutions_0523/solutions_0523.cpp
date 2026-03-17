#include <bits/stdc++.h>
using namespace std;
long long a, b, c, pa = -1, pb = -1, pc = -1;
int main() {
  scanf("%lld%lld%lld", &a, &b, &c);
  if (a > b) swap(a, b);
  if (b > c) swap(b, c);
  if (a > b) swap(a, b);
  for (int i = 1; i <= 10000000; i++) {
    if (pa == -1) {
      pa = i % a;
      continue;
    }
    if (i % a != pa) {
      if (pb == -1) {
        pb = i % b;
        continue;
      }
      if (i % b != pb) {
        if (pc == -1) {
          pc = i % c;
          continue;
        }
        if (i % c != pc) {
          puts("NO");
          return 0;
        }
      }
    }
  }
  puts("YES");
}
