#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  map<long long, vector<long long>> p, s, r, d;
  long long n, m, i, u, v;
  cin >> n >> m;
  vector<pair<long long, long long>> queen;
  for (i = 0; i < m; i++) {
    cin >> u >> v;
    queen.push_back(make_pair(u, v));
    p[u - v].push_back(u);
    s[u + v].push_back(u);
    r[u].push_back(v);
    d[v].push_back(u);
  }
  for (auto &i : p)
    sort(i.second.begin(), i.second.end(), greater<long long>());
  for (auto &i : s)
    sort(i.second.begin(), i.second.end(), greater<long long>());
  for (auto &i : r)
    sort(i.second.begin(), i.second.end(), greater<long long>());
  for (auto &i : d)
    sort(i.second.begin(), i.second.end(), greater<long long>());
  sort(queen.begin(), queen.end());
  map<pair<long long, long long>, long long> count;
  long long ans[9] = {0};
  for (i = 0; i < m; i++) {
    u = queen[i].first;
    v = queen[i].second;
    p[u - v].pop_back();
    s[u + v].pop_back();
    r[u].pop_back();
    d[v].pop_back();
    if (p[u - v].size()) {
      count[make_pair(u, v)]++;
      count[make_pair(*p[u - v].rbegin(), *p[u - v].rbegin() - u + v)]++;
    }
    if (s[u + v].size()) {
      count[make_pair(u, v)]++;
      count[make_pair(*s[u + v].rbegin(), -1 * (*s[u + v].rbegin()) + u + v)]++;
    }
    if (r[u].size()) {
      count[make_pair(u, v)]++;
      count[make_pair(u, *r[u].rbegin())]++;
    }
    if (d[v].size()) {
      count[make_pair(u, v)]++;
      count[make_pair(*d[v].rbegin(), v)]++;
    }
    ans[count[make_pair(u, v)]]++;
  }
  for (i = 0; i < 9; i++) cout << ans[i] << " ";
  return 0;
}
