#include <bits/stdc++.h>
using namespace std;
int n, w;
vector<long long> v;
void solve(int i, long long a, long long b) {
  if (a == b || w <= 3) {
    puts("YES");
    exit(0);
  }
  if (i == (int)v.size()) return;
  solve(i + 1, a + v[i], b);
  solve(i + 1, a, b + v[i]);
  solve(i + 1, a, b);
}
int main() {
  scanf("%d%d", &w, &n);
  long long val = 1;
  for (int i = 0; i <= 16 && val <= 1e10; ++i) {
    v.push_back(val);
    val *= w;
  }
  solve(0, 0, n);
  puts("NO");
  return 0;
}
