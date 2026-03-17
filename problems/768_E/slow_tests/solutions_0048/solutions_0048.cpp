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
  vector<int> mark(65, 0);
  for (int i = 1; i <= x; i++) {
    if (mask & (1ll << i)) continue;
    mark[solve(x - i, mask | (1ll << i))] = 1;
    while (mark[grundy]) grundy++;
  }
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
