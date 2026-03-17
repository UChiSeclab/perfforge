#include <bits/stdc++.h>
using namespace std;
constexpr long long mod = 1e9 + 7;
constexpr long long inf = LLONG_MAX;
long long log2(long long);
template <typename T>
void dispv(vector<T> v);
pair<long long, long long> vflip(long long i, long long j, long long n) {
  return {i, n - j - 1};
}
pair<long long, long long> hflip(long long i, long long j, long long n) {
  return {n - i - 1, j};
}
pair<long long, long long> rot90(long long i, long long j, long long n) {
  return {n - j - 1, i};
}
pair<long long, long long> rot180(long long i, long long j, long long n) {
  return {n - i - 1, n - j - 1};
}
pair<long long, long long> rot270(long long i, long long j, long long n) {
  return {j, n - i - 1};
}
pair<long long, long long> transform(long long i, long long j, long long x,
                                     long long n) {
  pair<long long, long long> coord = {i, j};
  long long p = 5;
  pair<long long, long long> (*fn[])(long long, long long, long long) = {
      vflip, hflip, rot90, rot180, rot270};
  while (p--) {
    if (x & 1) coord = fn[p](coord.first, coord.second, n);
    x >>= 1;
  }
  return coord;
}
void solve() {
  long long n;
  cin >> n;
  string m1[n], m2[n];
  for (auto &second : m1) cin >> second;
  for (auto &second : m2) cin >> second;
  bool yes;
  long long x = 125;
  while (x--) {
    yes = true;
    for (long long i = 0; i < n; ++i)
      for (long long j = 0; j < n; ++j) {
        pair<long long, long long> pt = transform(i, j, x, n);
        if (m1[i][j] != m2[pt.first][pt.second]) {
          yes = false;
          break;
        }
      }
    if (yes) {
      cout << "YES";
      return;
    }
  }
  cout << "NO";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  srand(time(NULL));
  int T = 1, t = 1;
  while (T--) {
    solve();
    cout << "\n";
  }
  return 0;
}
template <typename T>
void dispv(vector<T> v) {
  for (auto d : v) cout << d << " ";
  cout << "\n";
}
long long log2(long long x) { return 64 - __builtin_clzl(x) - 1; }
