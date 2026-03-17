#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vlli = vector<long long int>;
using vpii = vector<pair<int, int>>;
int n, m, x, y, cnt, ans;
bool check = true;
vpii a, b, A, B;
vi cntA(30, 0), cntB(30, 0);
int get(pii p, pii q) {
  map<int, int> cnt;
  cnt[p.first]++;
  cnt[p.second]++;
  cnt[q.first]++;
  cnt[q.second]++;
  if (cnt.size() == 4)
    return 0;
  else if (cnt.size() == 3)
    return 1;
  return 2;
}
int common(pii p, pii q) {
  map<int, int> cnt;
  cnt[p.first]++;
  cnt[p.second]++;
  cnt[q.first]++;
  cnt[q.second]++;
  if (cnt[p.first] == 2) return p.first;
  if (cnt[p.second] == 2) return p.second;
  if (cnt[q.first] == 2) return q.first;
  if (cnt[q.second] == 2) return q.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> x >> y, a.push_back(make_pair(x, y));
  for (int i = 0; i < m; i++) cin >> x >> y, b.push_back(make_pair(x, y));
  for (auto p1 : a) {
    map<int, int> temp;
    for (auto p2 : b)
      if (get(p1, p2) == 1) temp[common(p1, p2)]++;
    if (temp.size() == 1)
      A.push_back(p1);
    else if (temp.size() > 1)
      check = false;
  }
  for (auto p1 : b) {
    map<int, int> temp;
    for (auto p2 : a)
      if (get(p1, p2) == 1) temp[common(p1, p2)]++;
    if (temp.size() == 1)
      B.push_back(p1);
    else if (temp.size() > 1)
      check = false;
  }
  set<int> ans;
  for (auto p1 : A)
    for (auto p2 : B)
      if (get(p1, p2) == 1) ans.insert(common(p1, p2));
  if (ans.size() > 1 && check)
    cout << 0;
  else if (ans.size() == 1 && check)
    cout << *(ans.begin());
  else
    cout << -1;
}
