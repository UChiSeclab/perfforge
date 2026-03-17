#include <bits/stdc++.h>
using namespace std;
int n, c, d, a, b, ans, cmax, dmax;
char type;
vector<pair<int, int> > coin_list, diamond_list;
void calc(vector<pair<int, int> > x, int avail) {
  int sz = x.size();
  if (sz < 2) return;
  vector<int> vect(100007);
  vect[0] = x[0].second;
  for (int i = 1; i < sz; i++) vect[i] = max(vect[i - 1], x[i].second);
  for (int i = sz - 1; i > 0; i--) {
    int j;
    for (j = 0; j < i; j++)
      if (x[i].first + x[j].first > avail) break;
    j -= 1;
    if (j - 1 == i) break;
    if (j >= 0) ans = max(ans, x[i].second + vect[j]);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> c >> d;
  while (n--) {
    cin >> a >> b >> type;
    if (type == 'C') {
      if (b > c) continue;
      coin_list.push_back(make_pair(b, a));
      cmax = max(cmax, a);
    } else {
      if (b > d) continue;
      diamond_list.push_back(make_pair(b, a));
      dmax = max(dmax, a);
    }
  }
  sort(coin_list.begin(), coin_list.end());
  sort(diamond_list.begin(), diamond_list.end());
  calc(coin_list, c);
  calc(diamond_list, d);
  if (diamond_list.size() && coin_list.size()) ans = max(ans, cmax + dmax);
  cout << ans;
}
