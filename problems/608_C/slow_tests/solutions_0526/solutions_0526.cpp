#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, d;
  vector<pair<int, int>> ab;
  cin >> n;
  for (i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    ab.push_back(make_pair(a, b));
  }
  sort(ab.begin(), ab.end());
  vector<int> cnt(ab.back().first + 2);
  vector<int> dst(ab.back().first + 1);
  for (auto p : ab) {
    cnt[p.first + 1]++;
  }
  for (i = 0; i < ab.back().first + 1; i++) cnt[i + 1] += cnt[i];
  j = 0;
  d = 0;
  for (i = 0; i < n; i++) {
    for (; j < ab[i].first; j++) {
      dst[j] = d;
    }
    dst[j] = cnt[j];
    if (ab[i].second <= j) dst[j] -= cnt[j - ab[i].second];
    if (ab[i].second < j) dst[j] += dst[j - ab[i].second - 1];
    d = dst[j];
  }
  int mn = n - cnt[0];
  for (i = 0; i < ab.back().first + 1; i++) {
    mn = min(mn, n - cnt[i + 1] + dst[i]);
  }
  cout << mn << endl;
  return 0;
}
