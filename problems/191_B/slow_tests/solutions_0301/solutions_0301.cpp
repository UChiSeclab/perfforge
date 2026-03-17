#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
inline int mymax(int a, int b) { return a < b ? b : a; }
inline int mymin(int a, int b) { return a > b ? b : a; }
inline long long mymax(long long a, long long b) { return a < b ? b : a; }
inline long long mymin(long long a, long long b) { return a > b ? b : a; }
int main() {
  int n, k;
  cin >> n >> k;
  long long b;
  cin >> b;
  vector<pair<int, int> > ar(n - 1);
  for (int i = 0; i < (n - 1); ++i) {
    cin >> ar[i].first;
    ar[i].second = i + 1;
  }
  sort((ar).begin(), (ar).end());
  reverse((ar).begin(), (ar).end());
  long long s = 0;
  int mn = n;
  for (int i = 0; i < (k - 1); ++i) {
    s += ar[i].first;
    mn = min(mn, ar[i].second);
  }
  int res = n;
  if (b < s + ar[k - 1].first) res = mn;
  for (int i = k - 1; i < n - 1; ++i) {
    if (b < s + ar[i].first) res = min(res, ar[i].second);
  }
  cout << res;
  return 0;
}
