#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return b / gcd(a, b) * a; }
long long w, m;
vector<long long> g;
vector<long long> gen;
bool ok(long long x) {
  if (x < 1) return 0;
  while (x % w == 0) x /= w;
  return x == 1;
}
int main() {
  cin >> w >> m;
  if (w == 2) {
    puts("YES");
    return 0;
  }
  g.push_back(1);
  while (ok(g.back() * w) && g.back() < g.back() * w &&
         (g.back() * w <= 2 * m || g.size() < 22))
    g.push_back(g.back() * w);
  sort(g.begin(), g.end());
  g.resize(unique(g.begin(), g.end()) - g.begin());
  int n = g.size();
  for (int i = 0; i < (1 << n); ++i) {
    long long sum = 0;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) sum += g[j];
    }
    if (sum >= 0) gen.push_back(sum);
  }
  sort(gen.begin(), gen.end());
  for (int i = 0; i < gen.size(); ++i) {
    if (binary_search(gen.begin(), gen.end(), m + gen[i])) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
}
