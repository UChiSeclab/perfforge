#include <bits/stdc++.h>
const int maxn = 2e5 + 10;
int n;
long long a[maxn];
int ans = 0;
std::set<long long> p;
int solve(int bit, std::set<long long> p) {
  if (bit == 0) return p.size();
  int ret = 0;
  std::set<long long> a[2];
  for (auto i : p) {
    a[(i >> (bit - 1)) & 1].insert(i);
  }
  if (a[0].empty()) {
    ret = solve(bit - 1, a[1]);
  } else if (a[1].empty()) {
    ret = solve(bit - 1, a[0]);
  } else {
    ret = std::max(solve(bit - 1, a[0]), solve(bit - 1, a[1])) + 1;
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    p.insert(a[i]);
  }
  printf("%d\n", n - solve(30, p));
}
