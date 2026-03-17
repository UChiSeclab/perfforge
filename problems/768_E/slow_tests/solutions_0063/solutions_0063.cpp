#include <bits/stdc++.h>
using namespace std;
map<pair<long long, int>, int> memo;
int n, s, Xor;
int solve(int x, long long mask) {
  if (memo.count({mask, x})) return memo[{mask, x}];
  if (x == 0) {
    memo[{mask, x}] = 0;
    return 0;
  }
  int grundy = 0;
  map<int, int> ump;
  for (int i = 1; i <= x; i++) {
    if (mask & (1ll << i)) continue;
    ump[solve(x - i, mask | (1ll << i))] = 1;
    while (ump.count(grundy)) grundy++;
  }
  ump.clear();
  memo[{mask, x}] = grundy;
  return grundy;
}
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &s);
    Xor ^= solve(s, 0);
  }
  printf((Xor) ? "NO" : "YES");
  return 0;
}
