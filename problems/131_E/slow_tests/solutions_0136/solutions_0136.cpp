#include <bits/stdc++.h>
using namespace std;
const int inf = 1e5 + 9;
pair<pair<int, int>, int> a[inf];
map<int, int> row, col, d1, d2;
int atta[inf], ans[inf];
bool cmp1(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
  if (x.first.first == y.first.first) return x.first.second < y.first.second;
  return x.first.first < y.first.first;
}
bool cmp2(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
  if (x.first.first == y.first.first) return x.first.second > y.first.second;
  return x.first.first > y.first.first;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
    cin >> a[i].first.first >> a[i].first.second, a[i].second = i;
  sort(a + 1, a + 1 + m, cmp1);
  for (int i = 1; i <= m; i++) {
    int x = a[i].first.first, y = a[i].first.second, id = a[i].second;
    if (row.find(x) != row.end()) atta[id]++;
    if (col.find(y) != col.end()) atta[id]++;
    if (d1.find(x + y) != d1.end()) atta[id]++;
    if (d2.find(x - y) != d2.end()) atta[id]++;
    d2[x - y] = 1;
    d1[x + y] = 1;
    col[y] = 1;
    row[x] = 1;
  }
  row.clear();
  col.clear();
  d2.clear();
  d1.clear();
  sort(a + 1, a + 1 + m, cmp2);
  for (int i = 1; i <= m; i++) {
    int x = a[i].first.first, y = a[i].first.second, id = a[i].second;
    if (row.find(x) != row.end()) atta[id]++;
    if (col.find(y) != col.end()) atta[id]++;
    if (d1.find(x + y) != d1.end()) atta[id]++;
    if (d2.find(x - y) != d2.end()) atta[id]++;
    d2[x - y] = 1;
    d1[x + y] = 1;
    col[y] = 1;
    row[x] = 1;
  }
  for (int i = 1; i <= m; i++) ans[atta[i]]++;
  for (int i = 0; i <= 8; i++) cout << ans[i] << " ";
}
