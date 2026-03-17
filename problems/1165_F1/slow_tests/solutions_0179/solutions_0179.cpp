#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000;
int last[MAXN], k[MAXN];
pair<int, int> offer[MAXN + 1];
int n, m, sum;
bool isOK(int d) {
  int money = 0, cur = 0, hi = min(MAXN, d);
  memset(last, 0, sizeof(int) * n);
  for (int i = 0; offer[i].first <= hi; ++i)
    last[offer[i].second] = offer[i].first;
  vector<vector<int>> day(MAXN + 1);
  for (int i = 0; i < n; ++i)
    if (last[i]) day[last[i]].push_back(i);
  for (int i = 1; i <= hi; ++i) {
    ++money;
    for (auto x : day[i]) money -= min(k[x], money);
  }
  return 2 * sum + money - hi <= d;
}
int solve() {
  int lo = sum, hi = sum * 2, x = 0;
  while (lo <= hi) {
    int mid = lo + ((hi - lo) >> 1);
    if (isOK(mid))
      x = mid, hi = mid - 1;
    else
      lo = mid + 1;
  }
  return x;
}
int main() {
  scanf("%d%d", &n, &m);
  memset(last, 0, sizeof(int) * m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", k + i);
    sum += k[i];
  }
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    offer[i] = pair<int, int>{x, y - 1};
  }
  sort(offer, offer + m);
  offer[m].first = MAXN * 4;
  cout << solve() << endl;
  return 0;
}
