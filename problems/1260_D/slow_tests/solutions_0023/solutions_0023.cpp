#include <bits/stdc++.h>
using namespace std;
int sold[200005];
int m, n, k, t;
pair<int, pair<int, int> > traps[200005];
bool pass(int indurance) {
  vector<pair<int, int> > leftTraps;
  int i = 0;
  while (indurance >= traps[i].first) i++;
  int j = i;
  while (j < k) leftTraps.push_back(traps[j++].second);
  sort(leftTraps.begin(), leftTraps.end());
  int l = leftTraps.size();
  int total_time = 0;
  int last = -1;
  i = 0;
  while (i < l) {
    j = i + 1;
    int firstPos = leftTraps[i].first;
    int maxWantedPos = leftTraps[i].second;
    while (leftTraps[j].first <= maxWantedPos && j < l) {
      maxWantedPos = max(maxWantedPos, leftTraps[j].second);
      j++;
    }
    total_time += 2 * (maxWantedPos - firstPos + 1);
    i = j;
  }
  return (n + 1 + total_time <= t);
}
int BS() {
  int e = m - 1, s = 0, mid;
  while (e > s + 1) {
    mid = (e + s) / 2;
    if (pass(sold[mid]))
      e = mid;
    else
      s = mid + 1;
  }
  while (pass(sold[e - 1]) && e >= 1) e--;
  if (!pass(sold[e])) return m;
  return e;
}
int main() {
  cin >> m >> n >> k >> t;
  for (int i = 0; i < m; i++) cin >> sold[i];
  sort(sold, sold + m);
  for (int i = 0; i < k; i++) {
    int l, r, d;
    cin >> l >> r >> d;
    pair<int, int> z = make_pair(l, r);
    traps[i] = make_pair(d, z);
  }
  sort(traps, traps + k);
  int x = BS();
  cout << m - x << endl;
  return 0;
}
