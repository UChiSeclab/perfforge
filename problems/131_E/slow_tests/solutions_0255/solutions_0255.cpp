#include <bits/stdc++.h>
using namespace std;
const int MAX = 100007;
const int MOD = 1000000007;
void solve() {
  pair<int, int> a[MAX];
  int n, m;
  cin >> n >> m;
  map<int, vector<pair<int, int> > > row, col, dr, ur;
  map<pair<int, int>, int> mp;
  for (int i = 0; i < m; i++) {
    cin >> a[i].first >> a[i].second;
    row[a[i].second].push_back(a[i]);
    col[a[i].first].push_back(a[i]);
    dr[a[i].first - a[i].second].push_back(a[i]);
    ur[a[i].first + a[i].second].push_back(a[i]);
  }
  for (int i = 1; i <= n; i++) {
    vector<pair<int, int> > curr = row[i];
    int mn = n + 7, mx = -1;
    if (curr.size() <= 1) {
      continue;
    }
    for (pair<int, int> p : curr) {
      mn = min(mn, p.first);
      mx = max(mx, p.first);
    }
    for (pair<int, int> p : curr) {
      if (p.first == mn || p.first == mx) {
        mp[p]++;
      } else {
        mp[p] += 2;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    vector<pair<int, int> > curr = col[i];
    int mn = n + 7, mx = -1;
    if (curr.size() <= 1) {
      continue;
    }
    for (pair<int, int> p : curr) {
      mn = min(mn, p.second);
      mx = max(mx, p.second);
    }
    for (pair<int, int> p : curr) {
      if (p.second == mn || p.second == mx) {
        mp[p]++;
      } else {
        mp[p] += 2;
      }
    }
  }
  for (int i = 1 - n; i <= n - 1; i++) {
    vector<pair<int, int> > curr = dr[i];
    int mn = n + 7, mx = -n - 7;
    if (curr.size() <= 1) {
      continue;
    }
    for (pair<int, int> p : curr) {
      mn = min(mn, p.first);
      mx = max(mx, p.first);
    }
    for (pair<int, int> p : curr) {
      if (p.first == mn || p.first == mx) {
        mp[p]++;
      } else {
        mp[p] += 2;
      }
    }
  }
  for (int i = 1 + 1; i <= n + n; i++) {
    vector<pair<int, int> > curr = ur[i];
    int mn = n + 7, mx = -n - 7;
    if (curr.size() <= 1) {
      continue;
    }
    for (pair<int, int> p : curr) {
      mn = min(mn, p.first);
      mx = max(mx, p.first);
    }
    for (pair<int, int> p : curr) {
      if (p.first == mn || p.first == mx) {
        mp[p]++;
      } else {
        mp[p] += 2;
      }
    }
  }
  int cnt[9] = {};
  for (int i = 0; i < m; i++) {
    cnt[mp[a[i]]]++;
  }
  for (int i = 0; i <= 8; i++) {
    cout << cnt[i] << " ";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
